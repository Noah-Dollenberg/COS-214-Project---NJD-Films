#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H
#include "PlantState.h"

class DormantState : public PlantState {
public:
    virtual ~DormantState() = default;
};

#endif // DORMANTSTATE_H