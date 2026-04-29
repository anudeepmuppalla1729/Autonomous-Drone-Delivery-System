# Autonomous Drone Delivery System

A modular C++ simulation of an autonomous drone delivery system. This project models a delivery environment as a graph and simulates drones navigating between nodes while managing battery levels and avoiding obstacles.

## 🚀 Features

- **Graph-Based Navigation**: Uses a 100-node graph with random edge weights to simulate a city layout.
- **Shortest Path Calculation**: Implements **Dijkstra's Algorithm** for efficient route planning.
- **Dynamic Obstacle Avoidance**: Detects and re-routes around obstacles in real-time.
- **Battery Management**: Drones automatically find the nearest recharge station when battery levels are low (< 20%).
- **Drone Hierarchy**: 
  - `CargoDrone`: Designed for heavy loads (weight ≥ 5), optimized for fuel efficiency.
  - `UtilityDrone`: Designed for light loads (weight < 5), optimized for speed.
- **Robust Input Handling**: Safe integer input validation for a smooth user experience.

## 📂 Project Structure

The project has been refactored for modularity:

- `main.cpp`: Entry point of the application and the main execution loop.
- `Graph.h` / `Graph.cpp`: Logic for the delivery environment, connectivity, and Dijkstra's algorithm.
- `Drone.h` / `Drone.cpp`: Base and derived drone classes with battery and navigation logic.
- `Simulation.h`: Template-based simulation logic for handling delivery lifecycles.
- `Exceptions.h`: Custom exception handling for obstacles and low battery states.
- `Utils.h` / `Utils.cpp`: Helper functions for user input and validation.

## 🛠️ How to Build and Run

### Prerequisites
- A C++ compiler (e.g., `g++` or `clang++`).

### Compilation
Open your terminal in the project directory and run:

```bash
g++ -o DroneDeliverySystem main.cpp Graph.cpp Drone.cpp Utils.cpp
```

### Running the System
Execute the compiled binary:

```bash
./DroneDeliverySystem
```

## 🎮 How to Use

1. **Start the Program**: The system will initialize a new graph and display the locations of recharge stations and obstacles.
2. **Enter Destination**: Input a delivery point between 0 and 99. The system validates that the destination is not an obstacle or a recharge station.
3. **Enter Weight**: Input the weight of the item (1-9). This determines whether a `CargoDrone` or a `UtilityDrone` is dispatched.
4. **Simulation**: Watch the drone navigate to the destination, handle battery issues if necessary, and return to base (Node 0).
5. **Repeat or Exit**: Choose to perform another delivery or exit the application.

## 📜 License
This project is open-source and available for educational purposes.