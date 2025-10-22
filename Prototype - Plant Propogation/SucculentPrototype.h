#ifndef SUCCULENTPROTOTYPE_H
#define SUCCULENTPROTOTYPE_H
#include "PlantPrototype.h"

class SucculentPrototype : public PlantPrototype {
public:
    virtual ~SucculentPrototype() = default;
    PlantPrototype* clone() override;
};

#endif // SUCCULENTPROTOTYPE_H