#ifndef ROSEFACTORY_H
#define ROSEFACTORY_H

#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

class Rose : public Plant
{
public:
    Rose();
    Rose(const Rose &other);
    ~Rose() override;

    Plant *clone() const override;
    std::string getType() const override;
    void initialize() override;
    void display() const override;
};

class RoseFactory : public PlantFactory
{
public:
    virtual ~RoseFactory() = default;
    Plant *createPlant() override;
    std::string getPlantType() const override;
};

#endif