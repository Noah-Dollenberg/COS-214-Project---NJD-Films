#ifndef LAVENDERFACTORY_H
#define LAVENDERFACTORY_H
#include "PlantFactory.h"

class LavenderFactory : public PlantFactory {
public:
    virtual ~LavenderFactory() = default;
    Plant* createPlant() override;  // Instantiates Plant
};

#endif // LAVENDERFACTORY_H