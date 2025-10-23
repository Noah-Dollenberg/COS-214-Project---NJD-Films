#ifndef ARRANGEMENTDIRECTOR_H
#define ARRANGEMENTDIRECTOR_H

class PlantArrangementBuilder;

class ArrangementDirector {
private:
    PlantArrangementBuilder* builder;  // Aggregation
    
public:
    virtual ~ArrangementDirector() = default;
};

#endif // ARRANGEMENTDIRECTOR_H