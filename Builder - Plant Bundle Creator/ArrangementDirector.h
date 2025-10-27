#ifndef ARRANGEMENTDIRECTOR_H
#define ARRANGEMENTDIRECTOR_H

class PlantArrangementBuilder;
class PlantArrangement;

class ArrangementDirector {
private:
    PlantArrangementBuilder* builder;

public:
    ArrangementDirector();
    virtual ~ArrangementDirector();

    // Set which builder to use
    void setBuilder(PlantArrangementBuilder* builder);

    // Construction methods
    PlantArrangement* constructSimpleArrangement();
    PlantArrangement* constructDeluxeArrangement();
    PlantArrangement* constructCustomArrangement(bool includeDecorations);
};

#endif // ARRANGEMENTDIRECTOR_H