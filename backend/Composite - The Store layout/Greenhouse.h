#ifndef GREENHOUSE_H
#define GREENHOUSE_H
#include "GreenhouseComponent.h"

class GreenhouseController;

class Greenhouse : public GreenhouseComponent {
private:
    GreenhouseController* controller;
    
public:
    Greenhouse(const std::string& name = "Main Greenhouse");
    virtual ~Greenhouse();
    
    void display(int depth = 0) const override;
    void setController(GreenhouseController* ctrl);
    GreenhouseController* getController() const;
    bool isComposite() const override;
};

#endif // GREENHOUSE_H
