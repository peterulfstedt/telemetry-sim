# Robotics Telemetry Logger

**Project Description**  
This is a **command-line simulation of a robotic sensor system**. The project demonstrates core principles of **sensor data management, dynamic memory handling, and persistent logging**, forming a foundation for robotics telemetry and control system simulations.

The system collects simulated sensor readings (temperature, distance, battery), logs them into a CSV file, and applies simple reactive logic to mimic robotic decision-making.

---

## Features

- **Sensor Simulation**
  - Temperature (°C), distance (cm), battery (%)  
  - Randomized but realistic values for testing
- **Dynamic Memory Management**
  - Stores an arbitrary number of readings using a dynamically resizing array
- **Reactive Logic**
  - Low battery → returns to base  
  - Overheating → activates cooling  
  - Obstacle detected → triggers rerouting
- **Persistent Data**
  - Save readings to CSV (`data_log.csv`)  
  - Load previously saved data into memory  
  - View CSV contents directly from the program
- **Interactive Menu**
  - Menu-driven CLI for running simulations and managing data

---

## Project Structure

telemetry-sim/
├── src
│ ├── main.c
│ ├── logic.c
│ ├── sensors.c
│ └── logger.c
├── include/
│ ├── logic.h
│ ├── sensors.h
│ └── logger.h
├── data/
│ └── data_log.csv
├── README.md
├── LICENSE
└── .gitignore

