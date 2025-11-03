@echo off
echo Building Greenhouse API Server...
echo.

REM Compile all source files
g++ -std=c++17 -O2 -I. ^
  simple_api_server.cpp ^
  "Plant - Abstract Base/Plant.cpp" ^
  "Factory - Plant Creation/RoseFactory.cpp" ^
  "Factory - Plant Creation/CactusFactory.cpp" ^
  "Factory - Plant Creation/SucculentFactory.cpp" ^
  "Factory - Plant Creation/LavenderFactory.cpp" ^
  "Factory - Plant Creation/BaobabFactory.cpp" ^
  "Composite - The Store layout/Greenhouse.cpp" ^
  "Composite - The Store layout/GreenhouseComponent.cpp" ^
  "Composite - The Store layout/GreenhouseSection.cpp" ^
  "Composite - The Store layout/PlantLeaf.cpp" ^
  "Composite - The Store layout/Shelf.cpp" ^
  "State - Plant lifecycle/DormantState.cpp" ^
  "State - Plant lifecycle/FloweringState.cpp" ^
  "State - Plant lifecycle/GrowingState.cpp" ^
  "State - Plant lifecycle/MatureState.cpp" ^
  "State - Plant lifecycle/PlantState.cpp" ^
  "State - Plant lifecycle/SeedlingState.cpp" ^
  "Prototype - Plant Propogation/PlantPrototype.cpp" ^
  "Prototype - Plant Propogation/RosePrototype.cpp" ^
  "Prototype - Plant Propogation/SucculentPrototype.cpp" ^
  "Prototype - Plant Propogation/NurseryManager.cpp" ^
  -o greenhouse_api.exe -lws2_32

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful! Run greenhouse_api.exe to start the server.
) else (
    echo.
    echo Build failed! Check errors above.
)

pause
