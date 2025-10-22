#ifndef GREENHOUSECOMPONENT_H
#define GREENHOUSECOMPONENT_H
#include <vector>

class InventoryManager;
class Shelf;
class Greenhouse;
class GreenhouseSection;

class GreenhouseComponent {
protected:
    std::vector<GreenhouseComponent*> children;  // Composite children
    
public:
    virtual ~GreenhouseComponent() = default;
};

#endif // GREENHOUSECOMPONENT_H