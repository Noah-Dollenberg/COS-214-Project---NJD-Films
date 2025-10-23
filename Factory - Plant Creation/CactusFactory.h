#ifndef CACTUSFACTORY_H
#define CACTUSFACTORY_H
#include "PlantFactory.h"

class CactusFactory : public PlantFactory {
public:
    virtual ~CactusFactory() = default;
    Plant* createPlant() override;  // Instantiates Plant
};

#endif // CACTUSFACTORY_H
