#ifndef PLANTARRANGEMENT_H
#define PLANTARRANGEMENT_H
#include <vector>
#include <string>

class Plant;

class PlantArrangement {
private:
    std::vector<Plant*> plants;
    std::string name;
    std::string description;
    double basePrice;
    std::string containerType;

public:
    PlantArrangement();
    virtual ~PlantArrangement();

    // Setters
    void setName(const std::string& name);
    void setDescription(const std::string& desc);
    void setBasePrice(double price);
    void setContainerType(const std::string& container);
    void addPlant(Plant* plant);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    double getBasePrice() const;
    double getTotalPrice() const;
    std::string getContainerType() const;
    const std::vector<Plant*>& getPlants() const;
    int getPlantCount() const;
    void display() const;
};

#endif // PLANTARRANGEMENT_H