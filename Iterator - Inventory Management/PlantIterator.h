#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

class Plant;

class PlantIterator {
public:
    virtual ~PlantIterator() = default;
    
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual Plant* currentItem() const = 0;
};

#endif // PLANTITERATOR_H
