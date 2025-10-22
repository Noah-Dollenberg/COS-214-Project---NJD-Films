#ifndef ROSEPROTOTYPE_H
#define ROSEPROTOTYPE_H
#include "PlantPrototype.h"

class RosePrototype : public PlantPrototype {
public:
    virtual ~RosePrototype() = default;
    PlantPrototype* clone() override;
};

#endif // ROSEPROTOTYPE_H