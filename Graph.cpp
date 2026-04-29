#include "Graph.h"
#include <iostream>
#include <queue>
#include <random>

using namespace std;

Graph::Graph(int n) : nodes(n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 5);

    for (int i = 0; i < nodes; ++i) {
        int conn1 = (i + 1) % nodes;
        int conn2 = (i + 2) % nodes;
        adjList[i].push_back({conn1, dist(gen)});
        adjList[conn1].push_back({i, dist(gen)});
        adjList[i].push_back({conn2, dist(gen)});
        adjList[conn2].push_back({i, dist(gen)});
    }

    for (int i = 0; i < nodes; i += 10) {
        rechargeStations.insert(i);
    }

    uniform_int_distribution<> obstacleDist(0, nodes - 1);
    while (obstacles.size() < 10) {
        int obstacleNode = obstacleDist(gen);
        if (rechargeStations.find(obstacleNode) == rechargeStations.end()) {
            obstacles.insert(obstacleNode);
        }
    }
}

bool Graph::isObstacle(int node) const {
    return obstacles.find(node) != obstacles.end();
}

bool Graph::isRechargeStation(int node) const {
    return rechargeStations.find(node) != rechargeStations.end();
}

vector<int> Graph::shortestPath(int start, int destination) {
    vector<int> distance(nodes, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    distance[start] = 0;
    set<int> reportedObstacles;  

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (node == destination) break;
        if (distance[node] < dist) continue;

        for (auto& edge : adjList[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (isObstacle(neighbor)) {
                if (reportedObstacles.find(neighbor) == reportedObstacles.end()) {
                    cout << "Obstacle detected at node " << neighbor << "! Re-routing..." << endl;
                    reportedObstacles.insert(neighbor); 
                }
                continue;
            }

            int newDist = dist + weight;
            if (newDist < distance[neighbor]) {
                distance[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }
    return distance;
}

void Graph::displayRechargeStationsAndObstacles() const {
    cout << "Recharge Stations available at nodes:\n";
    for (int station : rechargeStations) {
        cout << station << " ";
    }
    cout << endl;
    cout << "Obstacles present at nodes:\n";
    for (int obstacle : obstacles) {
        cout << obstacle << " ";
    }
    cout << endl;
}
