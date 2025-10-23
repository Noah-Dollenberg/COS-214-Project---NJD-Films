#ifndef BAOBABFACTORY_H
#define BAOBABFACTORY_H
#include "PlantFactory.h"

class BaobabFactory : public PlantFactory {
public:
    virtual ~BaobabFactory() = default;
    Plant* createPlant() override;  // Instantiates Plant
};

#endif // BAOBABFACTORY_H