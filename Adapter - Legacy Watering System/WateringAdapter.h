#ifndef WATERINGADAPTER_H
#define WATERINGADAPTER_H

class ModernWateringSystem;
class LegacyIrrigationSystem;

class WateringAdapter {
private:
    ModernWateringSystem* modernSystem;      // Instantiates
    LegacyIrrigationSystem* legacySystem;    // Aggregation
    
public:
    virtual ~WateringAdapter() = default;
};

#endif // WATERINGADAPTER_H