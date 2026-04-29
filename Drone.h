#ifndef DRONE_H
#define DRONE_H

#include "Graph.h"

class Drone {
protected:
    int batteryLevel;
    int speedLevel;
    int currentNode;

public:
    Drone();
    virtual ~Drone() = default;

    virtual void navigate(int destination, Graph& graph) = 0;

    int getCurrentNode() const;
    void checkBattery(Graph& graph);
    int findNearestRechargeStation(Graph& graph);
    void chargeBattery();
    void navigateTo(int destination, Graph& graph);
    int calculateBatteryConsumption(int distance);
};

class CargoDrone : public Drone {
public:
    CargoDrone();
    void navigate(int destination, Graph& graph) override;
};

class UtilityDrone : public Drone {
public:
    UtilityDrone();
    void navigate(int destination, Graph& graph) override;
};

#endif // DRONE_H
