#include "GreenhouseComponent.h"
#include <algorithm>

GreenhouseComponent::GreenhouseComponent(const std::string& componentName)
    : name(componentName) {
}

GreenhouseComponent::~GreenhouseComponent() {
    // Delete all children (composite takes ownership)
    for (auto child : children) {
        delete child;
    }
    children.clear();
}

void GreenhouseComponent::add(GreenhouseComponent* component) {
    if (component) {
        children.push_back(component);
    }
}

void GreenhouseComponent::remove(GreenhouseComponent* component) {
    auto it = std::find(children.begin(), children.end(), component);
    if (it != children.end()) {
        children.erase(it);
    }
}

GreenhouseComponent* GreenhouseComponent::getChild(int index) const {
    if (index >= 0 && index < static_cast<int>(children.size())) {
        return children[index];
    }
    return nullptr;
}

int GreenhouseComponent::getChildCount() const {
    return static_cast<int>(children.size());
}

std::string GreenhouseComponent::getName() const {
    return name;
}

bool GreenhouseComponent::isComposite() const {
    return true;  // Default implementation for composites
}
