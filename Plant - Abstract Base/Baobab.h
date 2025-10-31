#ifndef BAOBAB_H
#define BAOBAB_H
#include "Plant.h"

class Baobab : public Plant {
public:
    Baobab() : Plant("Baobab", 90) {
        setBasePrice(250.0);
        setWateringFrequency(7);  // Moderate watering
        setSunlightRequirement(10); // Very high sun requirement
        setFertilizingFrequency(30);
        setSoilType("loamy");
        setHeight(15.0); // Starts taller as a tree
    }

    Plant* clone() const override {
        return new Baobab(*this);
    }

    std::string getType() const override {
        return "Baobab Tree";
    }

    virtual ~Baobab() = default;
};

#endif // BAOBAB_H