#ifndef FREQUENTWATERING_H
#define FREQUENTWATERING_H
#include "PlantCareStrategy.h"

class FrequentWatering : public PlantCareStrategy {
public:
    virtual ~FrequentWatering() = default;
    void careForPlant() override;
};

#endif // FREQUENTWATERING_H