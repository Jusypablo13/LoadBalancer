#include "LoadBalancer.h"

int main(){
    int num_servers, max_requests;

    cout << "Ingrese el numero de servidores: ";
    cin >> num_servers;
    cout << "Ingrese el numero maximo de solicitudes por servidor: ";
    cin >> max_requests;

    LoadBalancer lb(num_servers, max_requests);
    lb.distributeRequest(0);
    lb.distributeRequest(0);
    lb.distributeRequest(1);
    lb.completeRequest(2);
    lb.distributeRequest(1);

    lb.displayServerLoad();    

    return 0;
}