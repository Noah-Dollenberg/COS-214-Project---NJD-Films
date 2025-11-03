#ifndef BAOBABFACTORY_H
#define BAOBABFACTORY_H
#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

class BaobabFactory : public PlantFactory
{
public:
    virtual ~BaobabFactory() = default;
    Plant *createPlant() override;
    std::string getPlantType() const override;
};

#endif