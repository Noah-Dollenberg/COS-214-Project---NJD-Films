#ifndef MINIMALWATERING_H
#define MINIMALWATERING_H
#include "PlantCareStrategy.h"

class MinimalWatering : public PlantCareStrategy {
public:
    virtual ~MinimalWatering() = default;
    void careForPlant() override;
};

#endif // MINIMALWATERING_H
