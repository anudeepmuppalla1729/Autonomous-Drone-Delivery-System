#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include "Drone.h"
#include "Graph.h"
#include "Exceptions.h"

template <typename T>
void simulateDroneDelivery(T* drone, int destination, Graph& graph) {
    try {
        drone->checkBattery(graph);
        drone->navigate(destination, graph);

        std::cout << "Delivery completed at node " << destination << ". Returning to base...\n";
        drone->navigate(0, graph);

        if (drone->getCurrentNode() == 0) {
            std::cout << "Returning to base...\n";
            std::cout << "Drone at Base. Charging the drone to full capacity...\n";
        }

    } catch (const DroneException<ObstacleDetected>& e) {
        std::cout << e.what() << "\nRe-routing...\n";
        try {
            drone->navigate(destination, graph);
        } catch (const DroneException<ObstacleDetected>& e) {
            std::cout << "Re-routing failed: " << e.what() << std::endl;
        }
    } catch (const DroneException<LowBattery>& e) {
        std::cout << e.what() << "\nReturning to base...\n";
        drone->navigate(0, graph);

        if (drone->getCurrentNode() == 0) {
            std::cout << "Returning to base. Charging the drone to full capacity...\n";
            drone->chargeBattery();
        }
    }
}

#endif // SIMULATION_H
