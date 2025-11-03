#include "SucculentFactory.h"
#include <iostream>

Succulent::Succulent() : Plant("Succulent", 40)
{
    initialize();
}

Succulent::Succulent(const Succulent &other) : Plant(other) {}

Succulent::~Succulent() {}

Plant *Succulent::clone() const
{
    return new Succulent(*this);
}

std::string Succulent::getType() const
{
    return "Succulent";
}

void Succulent::initialize()
{
    setScientificName("Crassulaceae");
    setHeight(2.5);
    setBasePrice(20.00);
    setWateringFrequency(10);
    setSunlightRequirement(6);
    setFertilizingFrequency(45);
    setSoilType("sandy");
    setHealthLevel(100);
    setCurrentSeason("summer");
}

void Succulent::display() const
{
    std::cout << "\n=== SUCCULENT PLANT ===" << std::endl;
    Plant::display();
    std::cout << "Scientific Name: " << getScientificName() << std::endl;
}

Plant* SucculentFactory::createPlant()
{
    return new Succulent();
}

std::string SucculentFactory::getPlantType() const
{
    return "Succulent";
}