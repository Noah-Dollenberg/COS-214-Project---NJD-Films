#ifndef CACTUSFACTORY_H
#define CACTUSFACTORY_H
#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

class Cactus : public Plant
{
public:
    Cactus();
    Cactus(const Cactus &other);
    ~Cactus() override;

    Plant *clone() const override;
    std::string getType() const override;
    void initialize() override;
    void display() const override;
};

class CactusFactory : public PlantFactory {
public:
    virtual ~CactusFactory() = default;
    Plant* createPlant() override;
    std::string getPlantType() const override;
};

#endif
