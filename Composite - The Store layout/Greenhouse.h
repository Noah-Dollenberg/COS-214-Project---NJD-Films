#ifndef GREENHOUSE_H
#define GREENHOUSE_H
#include "GreenhouseComponent.h"

class GreenhouseController;

class Greenhouse : public GreenhouseComponent {
private:
    GreenhouseController* controller;  // Relationship
    
public:
    virtual ~Greenhouse() = default;
};

#endif // GREENHOUSE_H