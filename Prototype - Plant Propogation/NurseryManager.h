#ifndef NURSERYMANAGER_H
#define NURSERYMANAGER_H
#include <vector>
#include <string>

class PlantPrototype;

class NurseryManager {
private:
    std::vector<PlantPrototype*> prototypes; 
    
public:
    virtual ~NurseryManager() = default;
    void addPrototype(PlantPrototype* proto);
    PlantPrototype* clonePrototype(const std::string& type);
};

#endif // NURSERYMANAGER_H