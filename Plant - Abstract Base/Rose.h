#ifndef ROSE_H
#define ROSE_H
#include "Plant.h"

class Rose : public Plant {
public:
    Rose() : Plant("Rose", 45) {
        setBasePrice(150.0);
        setWateringFrequency(3);  // Needs frequent water
        setSoilType("loamy");
    }

    Plant* clone() const override {
        return new Rose(*this);
    }

    std::string getType() const override {
        return "Rose";
    }
};
#endif // ROSE_H