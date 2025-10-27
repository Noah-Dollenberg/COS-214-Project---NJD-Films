#include "LavenderFactory.h"
#include <iostream>

Lavender::Lavender() : Plant("Lavender", 60)
{
    initialize();
}

Lavender::Lavender(const Lavender &other) : Plant(other) {}

Lavender::~Lavender() {}

Plant *Lavender::clone() const
{
    return new Lavender(*this);
}

std::string Lavender::getType() const
{
    return "Lavender";
}

void Lavender::initialize()
{
    setScientificName("Lavandula");
    setHeight(8.0);
    setBasePrice(35.00);
    setWateringFrequency(7);
    setSunlightRequirement(7);
    setFertilizingFrequency(30);
    setSoilType("sandy");
    setHealthLevel(100);
    setCurrentSeason("summer");
}

void Lavender::display() const
{
    std::cout << "\n=== LAVENDER PLANT ===" << std::endl;
    Plant::display();
    std::cout << "Scientific Name: " << getScientificName() << std::endl;
}

Plant* LavenderFactory::createPlant()
{
    return new Lavender();
}

std::string LavenderFactory::getPlantType() const
{
    return "Lavender";
}