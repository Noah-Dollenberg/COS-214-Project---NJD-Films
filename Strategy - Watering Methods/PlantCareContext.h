#ifndef PLANTCARECONTEXT_H
#define PLANTCARECONTEXT_H

class PlantCareStrategy;
class Plant;

class PlantCareContext {
private:
    PlantCareStrategy* strategy;
    Plant* plant;
    
public:
    PlantCareContext(Plant* p) : plant(p), strategy(nullptr) {}
    virtual ~PlantCareContext() = default;
    
    void setStrategy(PlantCareStrategy* s);
    void executeCare();
};

#endif // PLANTCARECONTEXT_H