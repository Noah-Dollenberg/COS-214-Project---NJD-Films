#include "GreenhouseSection.h"
#include <iostream>

GreenhouseSection::GreenhouseSection(const std::string& type, const std::string& name)
    : GreenhouseComponent(name), sectionType(type) {
}

GreenhouseSection::~GreenhouseSection() {
    // Base class destructor will handle children
}

void GreenhouseSection::display(int depth) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "++ Section: " << getName() << " (" << sectionType << ")" << std::endl;
    
    // Display all children (shelves and subsections)
    for (const auto& child : children) {
        if (child) {
            child->display(depth + 1);
        }
    }
}

std::string GreenhouseSection::getSectionType() const {
    return sectionType;
}

bool GreenhouseSection::isComposite() const {
    return true;
}
