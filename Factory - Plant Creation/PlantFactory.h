#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

class Plant;

class PlantFactory {
public:
    virtual ~PlantFactory() = default;
    virtual Plant* createPlant() = 0;
};

#endif // PLANTFACTORY_H