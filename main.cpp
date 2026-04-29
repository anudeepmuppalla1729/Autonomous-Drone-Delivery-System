#include <iostream>
#include <string>
#include "Graph.h"
#include "Drone.h"
#include "Simulation.h"
#include "Utils.h"

using namespace std;

int main() {
    while(1){
        int nodes = 100;
        Graph graph(nodes);

        graph.displayRechargeStationsAndObstacles();

        int destination;
        while (true) {
            destination = getIntegerInput("Enter delivery point (0 to 99): ");
            if (destination >= 0 && destination <= 99 && 
                !graph.isRechargeStation(destination) && 
                !graph.isObstacle(destination)) {
                break;
            } else {
                cout << "Enter valid destination: Not a recharge station or obstacle.\n";
            }
        }

        int weight;
        while (true) {
            weight = getIntegerInput("Enter Weight(w>0 and w<10): ");
            if (weight > 0 && weight < 10) {
                break;
            } else {
                cout << "Enter valid weight.\n";
            }
        }

        if (weight >= 5) {
            CargoDrone cargoDrone;
            simulateDroneDelivery(&cargoDrone, destination, graph);
        } else {
            UtilityDrone utilityDrone;
            simulateDroneDelivery(&utilityDrone, destination, graph);
        }
        
        string choice;
        cout<<"Press E/e to exit or enter any other character to Deliver onether item: ";
        cin>>choice;
        if(choice == "E" || choice == "e"){
            cout << "Thank You...";
            break;
        }
        cout << "Next Delivery : " <<endl;
    }

    return 0;
}
