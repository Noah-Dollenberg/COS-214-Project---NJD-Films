# COS 214 Project - NJD Films Greenhouse Management System

<img src="https://github.com/user-attachments/assets/368d21b1-bcd4-4f55-89f3-d0355c8a1c45" width="200" height="200">

## Contents
- [Description](#description)
- [Documentation](#documentation)
- [Setup](#setup)
- [Team](#team)

## Description
The NJD Films Greenhouse Management System is a C++ project that simulates a comprehensive plant lifecycle management system using design patterns. The simulation manages plant creation, decoration, watering systems, staff functions, and store layout while demonstrating principles of software design such as scalability, flexibility, and maintainability.

![uptherah](https://github.com/user-attachments/assets/4afa3ec3-c78d-452d-b4f8-c706f0a214d9)
*"Up the rah"*

## Documentation

### Project Documentation
- **[Documentation](Documents/)** - All the documentation you could need !

### UML Diagrams
- **[UML Diagrams](UMLs/)** - Design patterns and system architecture diagrams

## Setup

### Building and Running

#### Using CMake 
```bash
# Navigate to SystemFiles directory
cd SystemFiles

# Create and enter build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build the project
cmake --build .
```

#### Running the Demo Main
```bash
# From the build dir
./COS_214_Project___NJD_Films          # Linux
.\COS_214_Project___NJD_Films.exe      # Windows
```

#### Running Unit Tests
```bash
# From the build dir
./GreenhouseSimulation                 # Linux
.\GreenhouseSimulation.exe             # Windows
```

#### Using Makefile
```bash
# Navigate to SystemFiles directory
cd SystemFiles

# Compile all targets
make all

# Run demo main
make run

# Run unit tests
make run-test
```

## Team

| Member | Student Number | Roles | Description |
|--------|---------------|-------|-------------|
| Noah Dollenberg | TBD | TBD | TBD |
| Dillon Koekemoer | u23537052 | Builder, Decorator, Unit Testin, Class Diagram, Attempt at the GUI | Who decided that? I will be the one to decide !  |
| Dylan McRobbie | u24646866 | State, Prototype, demo main, Sequence Diagram | You met me at a very strange time in my life -"Where is my mind?" starts playing |
| David Potgieter | u04579624 | Template, Strategy, functional requirements doc, Activity Diagram | You merely adopted the dark, I was born in it, molded by it  |
| Joshua Roberts | u23536765 | Composite, Iterator, Command, Class Diagram | TONIGHTS THE NIGHT |

