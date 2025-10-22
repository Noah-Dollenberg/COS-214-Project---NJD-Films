#ifndef ROSEFACTORY_H
#define ROSEFACTORY_H
#include "PlantFactory.h"

class RoseFactory : public PlantFactory {
public:
    virtual ~RoseFactory() = default;
    Plant* createPlant() override;  // Instantiates Plant
};

#endif // ROSEFACTORY_H