#ifndef MODERATEWATERING_H
#define MODERATEWATERING_H
#include "PlantCareStrategy.h"

class ModerateWatering : public PlantCareStrategy {
public:
    virtual ~ModerateWatering() = default;
    void careForPlant() override;
};

#endif // MODERATEWATERING_H