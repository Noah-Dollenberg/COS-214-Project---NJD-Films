#ifndef LAVENDERFACTORY_H
#define LAVENDERFACTORY_H
#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

class Lavender : public Plant
{
public:
    Lavender();
    Lavender(const Lavender &other);
    ~Lavender() override;

    Plant *clone() const override;
    std::string getType() const override;
    void initialize() override;
    void display() const override;
};

class LavenderFactory : public PlantFactory {
public:
    virtual ~LavenderFactory() = default;
    Plant* createPlant() override;
    std::string getPlantType() const override;
};

#endif