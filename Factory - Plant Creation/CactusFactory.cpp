#include "CactusFactory.h"
#include <iostream>

Cactus::Cactus() : Plant("Cactus", 30)
{
    initialize();
}

Cactus::Cactus(const Cactus &other) : Plant(other) {}

Cactus::~Cactus() {}

Plant *Cactus::clone() const
{
    return new Cactus(*this);
}

std::string Cactus::getType() const
{
    return "Cactus";
}

void Cactus::initialize()
{
    setScientificName("Cactaceae");
    setHeight(3.0);
    setBasePrice(25.00);
    setWateringFrequency(14);
    setSunlightRequirement(8);
    setFertilizingFrequency(60);
    setSoilType("sandy");
    setHealthLevel(100);
    setCurrentSeason("summer");
}

void Cactus::display() const
{
    std::cout << "\n=== CACTUS PLANT ===" << std::endl;
    Plant::display();
    std::cout << "Scientific Name: " << getScientificName() << std::endl;
}

Plant* CactusFactory::createPlant()
{
    return new Cactus();
}

std::string CactusFactory::getPlantType() const
{
    return "Cactus";
}