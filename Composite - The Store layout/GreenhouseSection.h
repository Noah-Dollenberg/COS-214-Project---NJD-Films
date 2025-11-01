#ifndef GREENHOUSESECTION_H
#define GREENHOUSESECTION_H
#include "GreenhouseComponent.h"

class GreenhouseSection : public GreenhouseComponent {
private:
    std::string sectionType;
    
public:
    GreenhouseSection(const std::string& type, const std::string& name = "Section");
    virtual ~GreenhouseSection();
    
    void display(int depth = 0) const override;
    std::string getSectionType() const;
    bool isComposite() const override;
};

#endif // GREENHOUSESECTION_H
