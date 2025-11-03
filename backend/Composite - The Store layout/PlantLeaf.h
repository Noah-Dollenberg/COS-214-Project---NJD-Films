#ifndef PLANTLEAF_H
#define PLANTLEAF_H
#include "GreenhouseComponent.h"

class Plant;

class PlantLeaf : public GreenhouseComponent {
private:
    Plant* plant;
    
public:
    PlantLeaf(Plant* p, const std::string& name = "Plant");
    virtual ~PlantLeaf();
    
    void display(int depth = 0) const override;
    Plant* getPlant() const;
    void add(GreenhouseComponent* component) override;
    void remove(GreenhouseComponent* component) override;
    GreenhouseComponent* getChild(int index) const override;
    bool isComposite() const override;
};

#endif // PLANTLEAF_H
