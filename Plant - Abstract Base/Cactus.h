#ifndef CACTUS_H
#define CACTUS_H
#include "Plant.h"

class Cactus : public Plant {
public:
    Cactus() : Plant("Cactus", 30) {
        setBasePrice(75.0);
        setWateringFrequency(14);  // Needs very infrequent water
        setSunlightRequirement(8);  // High sun requirement
        setFertilizingFrequency(60); // Rarely needs fertilizer
        setSoilType("sandy");
    }

    Plant* clone() const override {
        return new Cactus(*this);
    }

    std::string getType() const override {
        return "Cactus";
    }

    virtual ~Cactus() = default;
};

#endif // CACTUS_H