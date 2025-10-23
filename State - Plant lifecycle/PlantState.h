#ifndef PLANTSTATE_H
#define PLANTSTATE_H

class PlantState {
public:
    virtual ~PlantState() = default;
};

#endif // PLANTSTATE_H

#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H
#include "PlantState.h"

class GrowingState : public PlantState {
public:
    virtual ~GrowingState() = default;
};

#endif // GROWINGSTATE_H