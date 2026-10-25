# IV Infusion Pump Project

A learning project focused on real-time embedded software architecture, simulating a safety-critical medical device using FreeRTOS.

## 1. Project Overview
The goal of this project is to practice writing preemptive, thread-safe C code for embedded systems by designing a rigid task hierarchy and managing inter-task communication without blocking shared resources.

**Key Features:**
- **Zero-Lock Architecture**: Inter-task communication relies purely on FreeRTOS Queues, eliminating Mutexes and the risk of Priority Inversion.
- **Task Hierarchy**: Strict scheduling with Security_Task (Prio 3), Motor_Task (Prio 2), and UI_Task (Prio 1).
- **Fail-Safe Behavior**: Immediate emergency motor shutdown upon occlusion detection (pressure > 60) utilizing xQueueSendToFront to bypass standard command queues.

## 2. Tools & Stack
- C Compiler (GCC / MinGW)
- CMake 
- FreeRTOS (Real-Time Operating System)

## 3. Project Structure
    IV_Pump_Project/
    ├── CMakeLists.txt        
    ├── inc/                  
    └── src/                  

## 4. Build and Run
To build and run the simulation locally (example using MinGW on Windows):

    mkdir build
    cd build
    cmake -G "MinGW Makefiles" ..
    cmake --build .
    .\iv_pump.exe

## 5. Testing
- Hardware components (pressure sensor, LCD display, motor controller) are mocked to validate the RTOS task communication and priority preemption in an isolated environment.
