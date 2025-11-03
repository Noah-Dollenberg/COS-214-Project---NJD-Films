#include "RoseFactory.h"
#include <iostream>

Rose::Rose() : Plant("Rose", 45)
{
    initialize();
}

Rose::Rose(const Rose &other) : Plant(other) {}

Rose::~Rose() {}

Plant *Rose::clone() const
{
    return new Rose(*this);
}

std::string Rose::getType() const
{
    return "Rose";
}

void Rose::initialize()
{
    setScientificName("Rosa rubiginosa");
    setHeight(5.0);
    setBasePrice(45.00);
    setWateringFrequency(3);
    setSunlightRequirement(6);
    setFertilizingFrequency(14);
    setSoilType("loamy");
    setHealthLevel(100);
    setCurrentSeason("spring");
}

void Rose::display() const
{
    std::cout << "\n=== ROSE PLANT ===" << std::endl;
    Plant::display();
    std::cout << "Scientific Name: " << getScientificName() << std::endl;
}

Plant* RoseFactory::createPlant()
{
    return new Rose();
}

std::string RoseFactory::getPlantType() const
{
    return "Rose";
}