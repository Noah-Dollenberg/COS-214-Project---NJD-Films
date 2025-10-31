#ifndef LAVENDER_H
#define LAVENDER_H
#include "Plant.h"

class Lavender : public Plant {
public:
    Lavender() : Plant("Lavender", 40) {
        setBasePrice(85.0);
        setWateringFrequency(5);  // Moderate watering
        setSunlightRequirement(7); // Needs good sun
        setFertilizingFrequency(30);
        setSoilType("sandy");
    }

    Plant* clone() const override {
        return new Lavender(*this);
    }

    std::string getType() const override {
        return "Lavender";
    }

    virtual ~Lavender() = default;
};

#endif // LAVENDER_H