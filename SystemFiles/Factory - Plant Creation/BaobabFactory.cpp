#include "BaobabFactory.h"
#include <iostream>

class Baobab : public Plant
{
public:
    Baobab() : Plant("Baobab", 120)
    {
        initialize();
    }

    Baobab(const Baobab &other) : Plant(other) {}

    ~Baobab() override {}

    Plant *clone() const override
    {
        return new Baobab(*this);
    }

    std::string getType() const override
    {
        return "Baobab";
    }

    void initialize() override
    {
        setScientificName("Adansonia");
        setHeight(15.0);
        setBasePrice(150.00);
        setWateringFrequency(21);
        setSunlightRequirement(10);
        setFertilizingFrequency(90);
        setSoilType("sandy");
        setHealthLevel(100);
        setCurrentSeason("summer");
    }

    void display() const override
    {
        std::cout << "\n=== BAOBAB TREE ===" << std::endl;
        Plant::display();
        std::cout << "Scientific Name: " << getScientificName() << std::endl;
    }
};

Plant* BaobabFactory::createPlant()
{
    return new Baobab();
}

std::string BaobabFactory::getPlantType() const
{
    return "Baobab";
}