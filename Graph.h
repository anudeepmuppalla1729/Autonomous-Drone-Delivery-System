#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>

constexpr int INF = 1000;

class Graph {
public:
    int nodes;
    std::vector<std::pair<int, int>> adjList[100];
    std::set<int> obstacles;
    std::set<int> rechargeStations;

    Graph(int n);
    bool isObstacle(int node) const;
    bool isRechargeStation(int node) const;
    std::vector<int> shortestPath(int start, int destination = -1);
    void displayRechargeStationsAndObstacles() const;
};

#endif // GRAPH_H
