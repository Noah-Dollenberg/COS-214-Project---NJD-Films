#ifndef SHELF_H
#define SHELF_H
#include "GreenhouseComponent.h"

class Shelf : public GreenhouseComponent {
private:
    int shelfNumber;
    
public:
    Shelf(int number, const std::string& name = "Shelf");
    virtual ~Shelf();
    
    void display(int depth = 0) const override;
    int getShelfNumber() const;
    bool isComposite() const override;
};

#endif // SHELF_H
