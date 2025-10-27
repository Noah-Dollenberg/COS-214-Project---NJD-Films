#ifndef GIFTARRANGEMENTBUILDER_H
#define GIFTARRANGEMENTBUILDER_H
#include "PlantArrangementBuilder.h"
#include <vector>

class Plant;

class GiftArrangementBuilder : public PlantArrangementBuilder {
private:
    std::vector<Plant*> availablePlants;  // Plants to choose from

public:
    GiftArrangementBuilder();
    virtual ~GiftArrangementBuilder();

    // Set available plants pool
    void setAvailablePlants(const std::vector<Plant*>& plants);

    // Implement abstract methods
    void reset() override;
    void setBasicInfo() override;
    void selectContainer() override;
    void addPlants() override;
    void addDecorations() override;
    void calculatePrice() override;
};

#endif // GIFTARRANGEMENTBUILDER_H