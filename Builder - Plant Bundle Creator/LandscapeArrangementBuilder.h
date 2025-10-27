#ifndef LANDSCAPEARRANGEMENTBUILDER_H
#define LANDSCAPEARRANGEMENTBUILDER_H
#include <string>

#include "PlantArrangementBuilder.h"
#include <vector>

class Plant;

class LandscapeArrangementBuilder : public PlantArrangementBuilder {
private:
    std::vector<Plant*> availablePlants;
    std::string landscapeTheme;  // "desert", "tropical", "formal", etc.

public:
    LandscapeArrangementBuilder();
    virtual ~LandscapeArrangementBuilder();

    // Set available plants pool
    void setAvailablePlants(const std::vector<Plant*>& plants);
    void setTheme(const std::string& theme);

    // Implement abstract methods
    void reset() override;
    void setBasicInfo() override;
    void selectContainer() override;
    void addPlants() override;
    void addDecorations() override;
    void calculatePrice() override;
};

#endif // LANDSCAPEARRANGEMENTBUILDER_H