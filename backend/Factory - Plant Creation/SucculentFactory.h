#ifndef SUCCULENTFACTORY_H
#define SUCCULENTFACTORY_H
#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

class Succulent : public Plant
{
public:
    Succulent();
    Succulent(const Succulent &other);
    ~Succulent() override;

    Plant *clone() const override;
    std::string getType() const override;
    void initialize() override;
    void display() const override;
};

class SucculentFactory : public PlantFactory
{
public:
    virtual ~SucculentFactory() = default;
    Plant *createPlant() override;
    std::string getPlantType() const override;
};

#endif