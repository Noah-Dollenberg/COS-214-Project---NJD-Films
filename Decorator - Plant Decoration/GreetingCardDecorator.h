#ifndef GREETINGCARDDECORATOR_H
#define GREETINGCARDDECORATOR_H
#include "PlantDecorator.h"

class GreetingCardDecorator : public PlantDecorator {
public:
    virtual ~GreetingCardDecorator() = default;
};

#endif // GREETINGCARDDECORATOR_H