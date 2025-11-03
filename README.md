# 🌿 NJD Films Greenhouse Simulation

<img src="https://github.com/user-attachments/assets/368d21b1-bcd4-4f55-89f3-d0355c8a1c45" width="100" height="100">

An interactive GUI application showcasing 11 design patterns in a greenhouse management system. Built with C++ (backend) and React (frontend).

## Team Members
1. Noah Dollenberg
2. Dillon Koekemoer
3. Dylan McRobbie
4. David Potgieter
5. Joshua Roberts

![uptherah](https://github.com/user-attachments/assets/4afa3ec3-c78d-452d-b4f8-c706f0a214d9)
"Up the rah"

---

## Project Structure

```
.
├── backend/                    # C++ backend with Boost.Beast API server
│   ├── api_server.cpp         # REST API server implementation
│   ├── main.cpp               # Original CLI application
│   ├── CMakeLists.txt         # CMake build configuration
│   ├── Plant - Abstract Base/ # Plant base classes
│   ├── Factory - Plant Creation/
│   ├── Prototype - Plant Propogation/
│   ├── Composite - The Store layout/
│   ├── Iterator - Inventory Management/
│   ├── Template- Plant Care/
│   ├── Strategy - Watering Methods/
│   ├── State - Plant lifecycle/
│   ├── Adapter - Legacy Watering System/
│   ├── Command - Staff Functions/
│   ├── Decorator - Plant Decoration/
│   └── Builder - Plant Bundle Creator/
│
└── frontend/                   # React frontend application
    ├── src/
    │   ├── App.jsx            # Main application component
    │   ├── App.css            # Styling
    │   └── components/
    │       ├── PatternDemo.jsx      # Design pattern demonstrations
    │       ├── PlantList.jsx        # Plant inventory display
    │       └── GreenhouseView.jsx   # Greenhouse visualization
    ├── package.json
    └── vite.config.js
```

## Design Patterns Implemented

### Creational Patterns
1. **Factory Pattern** - Plant creation through specialized factories
2. **Prototype Pattern** - Plant cloning/propagation
3. **Builder Pattern** - Complex plant arrangement construction

### Structural Patterns
4. **Composite Pattern** - Hierarchical greenhouse structure
5. **Decorator Pattern** - Dynamic plant product customization
6. **Adapter Pattern** - Legacy irrigation system integration

### Behavioral Patterns
7. **Iterator Pattern** - Inventory traversal
8. **Template Pattern** - Standardized plant care routines
9. **Strategy Pattern** - Dynamic watering strategies
10. **State Pattern** - Plant lifecycle management
11. **Command Pattern** - Task scheduling and execution

## Prerequisites

### Backend (C++)
- C++17 or higher
- CMake 3.20 or higher
- Boost libraries (1.70 or higher) with:
  - Boost.Beast
  - Boost.Asio
  - Boost.System
  - Boost.Thread
  - Boost.JSON

### Frontend (React)
- Node.js 16+ and npm (tested with Node.js v22.14.0)
- Modern web browser

## Installation

### 1. Install Boost (if not already installed)

#### Windows (using vcpkg)
```bash
vcpkg install boost-beast boost-asio boost-system boost-thread boost-json
```

#### macOS (using Homebrew)
```bash
brew install boost
```

#### Linux (Ubuntu/Debian)
```bash
sudo apt-get install libboost-all-dev
```

### 2. Build the Backend

```bash
cd backend
mkdir build
cd build
cmake ..
cmake --build .
```

This will create two executables:
- `greenhouse_api` - REST API server
- `greenhouse_cli` - Original command-line interface

### 3. Install Frontend Dependencies

```bash
cd frontend
npm install
```

## Running the Application

### Step 1: Start the Backend Server

```bash
cd backend/build
./greenhouse_api        # On Linux/macOS
# or
greenhouse_api.exe      # On Windows
```

The server will start on `http://127.0.0.1:8080`

You should see:
```
Greenhouse API Server running on http://127.0.0.1:8080
Available endpoints:
  GET  /api/plants - Get all plants
  POST /api/factory/create - Create plant
  POST /api/prototype/clone - Clone plant
  GET  /api/greenhouse - Get greenhouse structure
  POST /api/state/change - Change plant state
```

### Step 2: Start the Frontend

In a new terminal:

```bash
cd frontend
npm run dev
```

The React app will start (typically on `http://localhost:5173`)

### Step 3: Open in Browser

Navigate to the URL shown by Vite (usually `http://localhost:5173`)

## Using the Application

### Factory Pattern Demo
- Click the "Factory Pattern" button
- Create different plant types (Rose, Cactus, Succulent, Lavender, Baobab)
- Each plant is created through its specialized factory

### Prototype Pattern Demo
- Click the "Prototype Pattern" button
- Select a plant from the list to clone it
- The cloned plant maintains the characteristics of the original

### Composite Pattern Demo
- Click the "Composite Pattern" button
- View the hierarchical structure of the greenhouse
- See sections, shelves, and plants organized in a tree structure

### State Pattern Demo
- Click the "State Pattern" button
- Select a plant and change its lifecycle state
- States: Seedling → Growing → Mature → Flowering → Dormant

## API Endpoints

### GET `/api/plants`
Returns all plants in the system.

**Response:**
```json
{
  "plants": [
    {
      "id": 1,
      "type": "Rose",
      "price": 150.00,
      "health": 100
    }
  ]
}
```

### POST `/api/factory/create`
Create a new plant using the factory pattern.

**Request:**
```json
{
  "type": "rose"  // Options: rose, cactus, succulent, lavender, baobab
}
```

**Response:**
```json
{
  "success": true,
  "id": 1,
  "type": "Rose",
  "price": 150.00,
  "health": 100
}
```

### POST `/api/prototype/clone`
Clone an existing plant.

**Request:**
```json
{
  "id": 1
}
```

**Response:**
```json
{
  "success": true,
  "original_id": 1,
  "clone_id": 2,
  "type": "Rose"
}
```

### GET `/api/greenhouse`
Get greenhouse structure information.

**Response:**
```json
{
  "name": "NJD Films Greenhouse",
  "sections": 2,
  "total_plants": 5
}
```

### POST `/api/state/change`
Change a plant's lifecycle state.

**Request:**
```json
{
  "id": 1,
  "state": "growing"  // Options: seedling, growing, mature, flowering, dormant
}
```

**Response:**
```json
{
  "success": true,
  "plant_id": 1,
  "new_state": "growing"
}
```

## Architecture

### Backend Architecture
- **Boost.Beast** for HTTP server functionality
- **Boost.Asio** for asynchronous I/O operations
- **Boost.JSON** for JSON serialization
- Multi-threaded request handling
- CORS-enabled for cross-origin requests

### Frontend Architecture
- **React** for UI components
- **Vite** for fast development and building
- Polling mechanism for real-time updates
- Responsive design with CSS Grid and Flexbox

### Communication Flow
```
React Frontend (Port 5173)
        ↓ HTTP Requests
   REST API Server (Port 8080)
        ↓
   C++ Greenhouse System
   (Design Pattern Logic)
```

## Development Notes

### Running the CLI Version
To run the original command-line version:
```bash
cd backend/build
./greenhouse_cli        # On Linux/macOS
# or
COS_214_Project___NJD_Films.exe  # On Windows
```

### Modifying the API
Edit `backend/api_server.cpp` to add new endpoints or modify existing ones.

### Modifying the Frontend
- Components are in `frontend/src/components/`
- Styling is in `frontend/src/App.css`
- API base URL can be changed in `frontend/src/App.jsx`

## Troubleshooting

### Backend won't compile
- Ensure Boost is properly installed and CMake can find it
- Check CMake output for missing dependencies
- Verify C++17 support in your compiler

### Frontend can't connect to backend
- Ensure the backend server is running on port 8080
- Check for firewall/antivirus blocking the connection
- Verify the API_BASE URL in `App.jsx` matches your backend

### CORS errors
- The backend includes CORS headers by default
- If issues persist, check browser console for specific errors

## Technologies Used

### Backend
- C++17
- Boost.Beast (HTTP server)
- Boost.Asio (Async I/O)
- Boost.JSON (JSON handling)
- CMake (Build system)

### Frontend
- React 18
- Vite (Build tool)
- Modern JavaScript (ES6+)
- CSS3 (Grid, Flexbox, Animations)

## License

Educational project for COS 214 coursework.

## Acknowledgments

- Design patterns implementation inspired by Gang of Four
- Boost.Beast documentation and examples
- React and Vite communities

