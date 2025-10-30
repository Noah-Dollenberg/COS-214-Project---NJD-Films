#ifndef ROSEPROTOTYPE_H
#define ROSEPROTOTYPE_H
#include "PlantPrototype.h"

class RosePrototype : public PlantPrototype {
public:
    RosePrototype();
    RosePrototype(const RosePrototype& other);
    virtual ~RosePrototype();
    PlantPrototype* clone() override;
};

#endif // ROSEPROTOTYPE_H