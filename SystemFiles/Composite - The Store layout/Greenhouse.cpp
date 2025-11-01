#include "Greenhouse.h"
#include <iostream>

Greenhouse::Greenhouse(const std::string& name)
    : GreenhouseComponent(name), controller(nullptr) {
}

Greenhouse::~Greenhouse() {
    // Base class destructor will handle children
    // We don't own the controller
    controller = nullptr;
}

void Greenhouse::display(int depth) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "=== GREENHOUSE: " << getName() << " ===" << std::endl;
    
    // Display all children (sections)
    for (const auto& child : children) {
        if (child) {
            child->display(depth + 1);
        }
    }
    
    std::cout << indent << "=== END OF GREENHOUSE ===" << std::endl;
}

void Greenhouse::setController(GreenhouseController* ctrl) {
    controller = ctrl;
}

GreenhouseController* Greenhouse::getController() const {
    return controller;
}

bool Greenhouse::isComposite() const {
    return true;
}
