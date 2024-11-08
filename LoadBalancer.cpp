#include "LoadBalancer.h"
#include <cstdlib> //random
#include <ctime> //time

LoadBalancer::LoadBalancer(int n, int max_requests)
: num_servers(n), max_requests_per_server(max_requests), adjMatrix(n, vector<int>(n,0)),requestsPerServer(n, 0){

    //Inicializar matriz de adyacencia con valores random
    srand(time(0));
    for(int i=0; i<num_servers; i++){
        for(int j=0; j<num_servers; j++){
            adjMatrix[i][j] = (i==j)? 0 : (rand() % 10 + 1);
        }
    }
};

int LoadBalancer::distributeRequest(int startServer){
    int minCost = INF;
    int selectedServer = -1;

    for(int i=0; i<num_servers; i++){
        if(i != startServer && adjMatrix[startServer][i] != INF){
            //Se valida si el servidor i tiene menos solicitudes que el servidor seleccionado
            if((requestsPerServer[i] < requestsPerServer[selectedServer] || selectedServer == -1) && (adjMatrix[startServer][i] < minCost)){
                //Se actualiza el servidor seleccionado junto con el costo minimo
                minCost = adjMatrix[startServer][i];
                selectedServer = i;
            }
        }
    }
    //Si se encontro un servidor disponible, se asigna la solicitud
    if(selectedServer != -1){
        requestsPerServer[selectedServer]++;
        cout << "Solicitud asignada al Servidor " << selectedServer << " desde Servidor " << startServer << ", Carga actual: " << requestsPerServer[selectedServer] << "\n";
    } else {
        cout << "No hay servidores disponibles" << startServer << "\n";
    }
    return selectedServer;
}

void LoadBalancer::completeRequest(int serverId){
    //Se valida que el servidor exista y tenga solicitudes pendientes
    if(serverId < 0 || serverId >= num_servers || requestsPerServer[serverId] == 0){
        cout << "Error: no hay solicitudes pendientes en el servidor " << serverId << "\n";
        return;
    }
    //Se disminuye el numero de solicitudes pendientes en el servidor
    requestsPerServer[serverId]--;
    cout << "Solicitud completada en el Servidor " << serverId << ", Carga actual: " << requestsPerServer[serverId] << "\n";
}

void LoadBalancer::displayServerLoad(){
    cout << "Carga de los servidores:\n";
    for(int i=0; i<num_servers; i++){
        cout << "Servidor " << i << ": " << requestsPerServer[i] << "\n";
    }
}