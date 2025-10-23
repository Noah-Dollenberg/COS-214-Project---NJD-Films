#include "Shelf.h"
#include <iostream>

Shelf::Shelf(int number, const std::string& name)
    : GreenhouseComponent(name), shelfNumber(number) {
}

Shelf::~Shelf() {
    // Base class destructor will handle children
}

void Shelf::display(int depth) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "+ Shelf #" << shelfNumber << ": " << getName() << std::endl;
    
    // Display all children (plants on this shelf)
    for (const auto& child : children) {
        if (child) {
            child->display(depth + 1);
        }
    }
}

int Shelf::getShelfNumber() const {
    return shelfNumber;
}

bool Shelf::isComposite() const {
    return true;
}
