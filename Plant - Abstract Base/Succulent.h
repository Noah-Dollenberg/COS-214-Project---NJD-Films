#ifndef SUCCULENT_H
#define SUCCULENT_H
#include "Plant.h"

class Succulent : public Plant {
public:
    Succulent() : Plant("Succulent", 25) {
        setBasePrice(50.0);
        setWateringFrequency(10);  // Infrequent watering
        setSunlightRequirement(6);  // Moderate sun
        setFertilizingFrequency(45);
        setSoilType("sandy");
    }

    Plant* clone() const override {
        return new Succulent(*this);
    }

    std::string getType() const override {
        return "Succulent";
    }

    virtual ~Succulent() = default;
};

#endif // SUCCULENT_H