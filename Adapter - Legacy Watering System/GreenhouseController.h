#ifndef GREENHOUSECONTROLLER_H
#define GREENHOUSECONTROLLER_H

class ModernWateringSystem;

class GreenhouseController {
private:
    ModernWateringSystem* wateringSystem;  // Aggregation
    
public:
    virtual ~GreenhouseController() = default;
};

#endif // GREENHOUSECONTROLLER_H