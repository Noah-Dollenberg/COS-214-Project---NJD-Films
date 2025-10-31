# Makefile for COS-214-Project - NJD Films Greenhouse Management System
# Compiles all design pattern implementations and creates executable

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I.
TARGET = greenhouse_system
TEST_TARGET = greenhouse_simulation

# Define all source files with their full paths
SRCS = Plant\ -\ Abstract\ Base/Plant.cpp \
       State\ -\ Plant\ lifecycle/PlantState.cpp \
       State\ -\ Plant\ lifecycle/SeedlingState.cpp \
       State\ -\ Plant\ lifecycle/GrowingState.cpp \
       State\ -\ Plant\ lifecycle/MatureState.cpp \
       State\ -\ Plant\ lifecycle/FloweringState.cpp \
       State\ -\ Plant\ lifecycle/DormantState.cpp \
       Prototype\ -\ Plant\ Propogation/PlantPrototype.cpp \
       Prototype\ -\ Plant\ Propogation/SucculentPrototype.cpp \
       Prototype\ -\ Plant\ Propogation/RosePrototype.cpp \
       Prototype\ -\ Plant\ Propogation/NurseryManager.cpp \
       Adapter\ -\ Legacy\ Watering\ System/LegacyIrrigationSystem.cpp \
       Adapter\ -\ Legacy\ Watering\ System/GreenhouseController.cpp \
       Adapter\ -\ Legacy\ Watering\ System/WateringAdapter.cpp \
       Builder\ -\ Plant\ Bundle\ Creator/ArrangementDirector.cpp \
       Builder\ -\ Plant\ Bundle\ Creator/LandscapeArrangementBuilder.cpp \
       Builder\ -\ Plant\ Bundle\ Creator/GiftArrangementBuilder.cpp \
       Builder\ -\ Plant\ Bundle\ Creator/PlantArrangement.cpp \
       Builder\ -\ Plant\ Bundle\ Creator/PlantArrangementBuilder.cpp \
       Command\ -\ Staff\ Functions/AssistCustomerCommand.cpp \
       Command\ -\ Staff\ Functions/FertilizePlantsCommand.cpp \
       Command\ -\ Staff\ Functions/PlantCareStaff.cpp \
       Command\ -\ Staff\ Functions/PrunePlantsCommand.cpp \
       Command\ -\ Staff\ Functions/SalesStaff.cpp \
       Command\ -\ Staff\ Functions/StaffMember.cpp \
       Command\ -\ Staff\ Functions/TaskScheduler.cpp \
       Command\ -\ Staff\ Functions/WaterPlantsCommand.cpp \
       Composite\ -\ The\ Store\ layout/Greenhouse.cpp \
       Composite\ -\ The\ Store\ layout/GreenhouseSection.cpp \
       Composite\ -\ The\ Store\ layout/GreenhouseComponent.cpp \
       Composite\ -\ The\ Store\ layout/PlantLeaf.cpp \
       Composite\ -\ The\ Store\ layout/Shelf.cpp \
       Decorator\ -\ Plant\ Decoration/BasicPlant.cpp \
       Decorator\ -\ Plant\ Decoration/DecorativePotDecorator.cpp \
       Decorator\ -\ Plant\ Decoration/GiftWrappingDecorator.cpp \
       Decorator\ -\ Plant\ Decoration/GreetingCardDecorator.cpp \
       Decorator\ -\ Plant\ Decoration/PlantDecorator.cpp \
       Decorator\ -\ Plant\ Decoration/PlantProduct.cpp \
       Factory\ -\ Plant\ Creation/BaobabFactory.cpp \
       Factory\ -\ Plant\ Creation/CactusFactory.cpp \
       Factory\ -\ Plant\ Creation/LavenderFactory.cpp \
       Factory\ -\ Plant\ Creation/RoseFactory.cpp \
       Factory\ -\ Plant\ Creation/SucculentFactory.cpp \
       Iterator\ -\ Inventory\ Management/GreenhouseInventory.cpp \
       Iterator\ -\ Inventory\ Management/InventoryIterator.cpp \
       Iterator\ -\ Inventory\ Management/InventoryManager.cpp \
       Strategy\ -\ Watering\ Methods/FrequentWatering.cpp \
       Strategy\ -\ Watering\ Methods/MinimalWatering.cpp \
       Strategy\ -\ Watering\ Methods/ModerateWatering.cpp \
       Strategy\ -\ Watering\ Methods/PlantCareContext.cpp \
       Template-\ Plant\ Care/PlantCareRoutine.cpp \
       Template-\ Plant\ Care/RoseCare.cpp \
       Template-\ Plant\ Care/SucculentCare.cpp \
       Template-\ Plant\ Care/TreeCare.cpp

# Main and test sources
MAIN_SRC = main.cpp
TEST_SRC = greenhouse_simulation.cpp

# Create object file names by replacing .cpp with .o
OBJS = $(SRCS:.cpp=.o)
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Default target - build main application
all: $(TARGET)

# Build test application
test: $(TEST_TARGET)

# Build both
both: $(TARGET) $(TEST_TARGET)

# Link main executable
$(TARGET): $(OBJS) $(MAIN_OBJ)
	@echo "Linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) -o "$@" $(OBJS) $(MAIN_OBJ)
	@echo "Build successful! Run with: ./$(TARGET)"

# Link test executable
$(TEST_TARGET): $(OBJS) $(TEST_OBJ)
	@echo "Linking $(TEST_TARGET)..."
	$(CXX) $(CXXFLAGS) -o "$@" $(OBJS) $(TEST_OBJ)
	@echo "Build successful! Run with: ./$(TEST_TARGET)"

# Generic rule to compile .cpp to .o
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c "$<" -o "$@"

# Run the main application
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)

# Run the test application
run-test: $(TEST_TARGET)
	@echo "Running $(TEST_TARGET)..."
	./$(TEST_TARGET)

# Generate Doxygen documentation
docs:
	@echo "Generating Doxygen documentation..."
	@doxygen Doxyfile
	@echo "Documentation generated in ./docs/html/"
	@echo "Open ./docs/html/index.html in your browser to view"

# Clean documentation
clean-docs:
	@echo "Cleaning documentation..."
	@rm -rf ./docs
	@echo "Documentation cleaned!"

# Clean build artifacts (Linux/Unix)
clean:
	@echo "Cleaning build artifacts..."
	@find . -name "*.o" -type f -delete 2>/dev/null || true
	@rm -f $(TARGET) $(TEST_TARGET)
	@echo "Clean complete!"

# Clean build artifacts (Windows)
clean-win:
	@echo "Cleaning build artifacts..."
	@cmd /c "for /r %i in (*.o) do @del /q %i" 2>nul || echo Cleaned
	@if exist $(TARGET).exe del /Q $(TARGET).exe
	@if exist $(TEST_TARGET).exe del /Q $(TEST_TARGET).exe
	@if exist $(TARGET) del /Q $(TARGET)
	@if exist $(TEST_TARGET) del /Q $(TEST_TARGET)
	@echo "Clean complete!"

# Help information
help:
	@echo "NJD Films Greenhouse Management System - Makefile"
	@echo ""
	@echo "Available targets:"
	@echo "  make          - Build main application (default)"
	@echo "  make all      - Build main application"
	@echo "  make test     - Build test application (greenhouse_simulation)"
	@echo "  make both     - Build both main and test applications"
	@echo "  make run      - Build and run main application"
	@echo "  make run-test - Build and run test application"
	@echo "  make docs     - Generate Doxygen documentation"
	@echo "  make clean-docs - Remove generated documentation"
	@echo "  make clean    - Remove all build artifacts (Linux/Unix)"
	@echo "  make clean-win - Remove all build artifacts (Windows)"
	@echo "  make help     - Show this help message"
	@echo ""
	@echo "Design Patterns Implemented:"
	@echo "  1. Factory Pattern       - Plant creation"
	@echo "  2. Prototype Pattern     - Plant propagation"
	@echo "  3. Builder Pattern       - Plant arrangements"
	@echo "  4. Adapter Pattern       - Legacy watering system"
	@echo "  5. Decorator Pattern     - Plant decorations"
	@echo "  6. Composite Pattern     - Store layout"
	@echo "  7. Command Pattern       - Staff functions"
	@echo "  8. Iterator Pattern      - Inventory management"
	@echo "  9. State Pattern         - Plant lifecycle"
	@echo "  10. Strategy Pattern     - Watering methods"
	@echo "  11. Template Pattern     - Plant care routines"

# Phony targets (not actual files)
.PHONY: all test both clean clean-win clean-docs run run-test docs help
