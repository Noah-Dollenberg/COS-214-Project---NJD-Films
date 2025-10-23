#ifndef GREENHOUSECOMPONENT_H
#define GREENHOUSECOMPONENT_H
#include <vector>
#include <string>

class InventoryManager;
class Shelf;
class Greenhouse;
class GreenhouseSection;

class GreenhouseComponent {
protected:
    std::vector<GreenhouseComponent*> children;  // Composite children
    std::string name;
    
public:
    GreenhouseComponent(const std::string& componentName = "");
    virtual ~GreenhouseComponent();
    
    virtual void display(int depth = 0) const = 0;
    virtual void add(GreenhouseComponent* component);
    virtual void remove(GreenhouseComponent* component);
    virtual GreenhouseComponent* getChild(int index) const;
    virtual int getChildCount() const;
    std::string getName() const;
    virtual bool isComposite() const;
};

#endif // GREENHOUSECOMPONENT_H
