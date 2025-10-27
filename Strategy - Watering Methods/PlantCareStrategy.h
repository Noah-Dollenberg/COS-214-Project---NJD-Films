#ifndef PLANTCARESTRATEGY_H
#define PLANTCARESTRATEGY_H

class PlantCareStrategy {
public:
    virtual ~PlantCareStrategy() = default;
    virtual void careForPlant() = 0;
};

#endif // PLANTCARESTRATEGY_H