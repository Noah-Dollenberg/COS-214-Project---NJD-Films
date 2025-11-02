#include "PlantLeaf.h"
#include "../Plant - Abstract Base/Plant.h"
#include <iostream>
#include <string>

PlantLeaf::PlantLeaf(Plant* p, const std::string& name)
    : GreenhouseComponent(name), plant(p) {
}

PlantLeaf::~PlantLeaf() {
    // We don't own the plant, just reference it
    plant = nullptr;
}

void PlantLeaf::display(int depth) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "- " << getName() << " (Leaf)" << std::endl;
}

Plant* PlantLeaf::getPlant() const {
    return plant;
}

void PlantLeaf::add(GreenhouseComponent* component) {
    // Leaf cannot have children - do nothing
    std::cout << "Cannot add to a leaf node." << std::endl;
}

void PlantLeaf::remove(GreenhouseComponent* component) {
    // Leaf cannot have children - do nothing
    std::cout << "Cannot remove from a leaf node." << std::endl;
}

GreenhouseComponent* PlantLeaf::getChild(int index) const {
    // Leaf has no children
    return nullptr;
}

bool PlantLeaf::isComposite() const {
    return false;  // Leaves are not composites
}
