#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX;

class LoadBalancer{
    private:
        int num_servers;
        int max_requests_per_server;
        vector<vector<int> > adjMatrix;
        vector<int> requestsPerServer;
    public:
        LoadBalancer(int n, int max_requests);
        int distributeRequest(int startServer);
        void completeRequest(int serverId);
        void displayServerLoad();
};

#endif // LOADBALANCER_H