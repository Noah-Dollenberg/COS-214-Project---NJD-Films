#ifndef GIFTWRAPPINGDECORATOR_H
#define GIFTWRAPPINGDECORATOR_H
#include "PlantDecorator.h"

class GiftWrappingDecorator : public PlantDecorator {
public:
    virtual ~GiftWrappingDecorator() = default;
};

#endif // GIFTWRAPPINGDECORATOR_H