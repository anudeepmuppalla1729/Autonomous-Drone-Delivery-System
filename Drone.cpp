#include "Drone.h"
#include <iostream>

using namespace std;

Drone::Drone() : batteryLevel(100), speedLevel(0), currentNode(0) {}

int Drone::getCurrentNode() const { return currentNode; }

void Drone::checkBattery(Graph& graph) {
    if (batteryLevel < 20) {
        cout << "Low battery at node " << currentNode << "! Navigating to nearest recharge station...\n";
        int nearestStation = findNearestRechargeStation(graph);
        navigateTo(nearestStation, graph);
        chargeBattery();
    }
}

int Drone::findNearestRechargeStation(Graph& graph) {
    vector<int> distances = graph.shortestPath(currentNode);
    int minDistance = INF;
    int nearestStation = -1;

    for (int station : graph.rechargeStations) {
        if (distances[station] < minDistance) {
            minDistance = distances[station];
            nearestStation = station;
        }
    }
    return nearestStation;
}

void Drone::chargeBattery() {
    cout << "Charging at station...\n";
    batteryLevel = 100;
    cout << "Battery fully charged!\n";
}

void Drone::navigateTo(int destination, Graph& graph) {
    vector<int> distances = graph.shortestPath(currentNode, destination);
    int distanceToDestination = distances[destination];
    
    int requiredBattery = calculateBatteryConsumption(distanceToDestination);

    if (distanceToDestination >= INF) {
        cout << "No path to destination.\n";
        return;
    }

    if (batteryLevel < requiredBattery) {
        cout << "Battery too low to reach destination. Navigating to nearest recharge station...\n";
        int nearestStation = findNearestRechargeStation(graph);
        navigateTo(nearestStation, graph);
        chargeBattery();

        if (batteryLevel < requiredBattery) {
            cout << "Still not enough battery to reach the destination, even after recharging.\n";
            return;
        }
    }
    
    batteryLevel -= requiredBattery;
    cout << ((graph.isRechargeStation(destination) && destination != 0) ? "Recharge Station at node " : "Navigated to node ")
         << destination << " (Distance: " << distanceToDestination << " km)\n";
    cout << "Current Battery Level: " << batteryLevel << "%\n";
    currentNode = destination;
}

int Drone::calculateBatteryConsumption(int distance) {
    return distance;
}

CargoDrone::CargoDrone() { this->speedLevel = 5; }

void CargoDrone::navigate(int destination, Graph& graph) {
    cout << "CargoDrone navigating with fuel-efficient path.\n";
    checkBattery(graph);
    navigateTo(destination, graph);
}

UtilityDrone::UtilityDrone() { this->speedLevel = 10; }

void UtilityDrone::navigate(int destination, Graph& graph) {
    cout << "UtilityDrone navigating with time-efficient path.\n";
    checkBattery(graph);
    navigateTo(destination, graph);
}
