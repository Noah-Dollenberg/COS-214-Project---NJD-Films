#ifndef SUCCULENTPROTOTYPE_H
#define SUCCULENTPROTOTYPE_H
#include "PlantPrototype.h"

class SucculentPrototype : public PlantPrototype {
public:
    SucculentPrototype();
    SucculentPrototype(const SucculentPrototype& other);
    virtual ~SucculentPrototype();
    PlantPrototype* clone() override;
};

#endif // SUCCULENTPROTOTYPE_H