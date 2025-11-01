/**
 * @file PlantArrangement.h
 * @brief Header file for the PlantArrangement product class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef PLANTARRANGEMENT_H
#define PLANTARRANGEMENT_H
#include <vector>
#include <string>

// Forward declaration
class Plant;

/**
 * @class PlantArrangement
 * @brief Product class representing a complex plant arrangement in the Builder pattern
 * @ingroup Builder
 *
 * PlantArrangement serves as the Product in the Builder design pattern. It represents
 * a complex object composed of multiple plants arranged in a container with specific
 * properties like name, description, and pricing. This class is constructed step-by-step
 * by PlantArrangementBuilder and its concrete subclasses.
 *
 * The arrangement can contain multiple plants of different types, each contributing
 * to the overall aesthetic and price. It supports various container types for different
 * purposes (gift baskets, landscape planters, decorative arrangements).
 *
 * PlantArrangement objects are typically created through the Builder pattern rather
 * than directly, allowing for flexible and controlled construction of complex arrangements.
 *
 * @par Design Pattern Role:
 * - Product: PlantArrangement (this class)
 * - Builder: PlantArrangementBuilder
 * - ConcreteBuilders: GiftArrangementBuilder, LandscapeArrangementBuilder
 * - Director: ArrangementDirector
 *
 * @par Usage Example:
 * @code
 * // Typically created through builder, not directly:
 * GiftArrangementBuilder builder;
 * ArrangementDirector director;
 * director.setBuilder(&builder);
 * PlantArrangement* arrangement = director.constructDeluxeArrangement();
 * arrangement->display();
 * @endcode
 *
 * @see PlantArrangementBuilder
 * @see GiftArrangementBuilder
 * @see LandscapeArrangementBuilder
 * @see ArrangementDirector
 * @see Plant
 */
class PlantArrangement {
private:
    /** @brief Collection of plants in this arrangement */
    std::vector<Plant*> plants;

    /** @brief Name of the arrangement (e.g., "Romantic Rose Bouquet") */
    std::string name;

    /** @brief Detailed description of the arrangement */
    std::string description;

    /** @brief Base price for the arrangement (excludes plant costs) */
    double basePrice;

    /** @brief Type of container (basket, planter, vase, etc.) */
    std::string containerType;

public:
    /**
     * @brief Default constructor
     * @post PlantArrangement created with empty plant list and default values
     */
    PlantArrangement();

    /**
     * @brief Virtual destructor
     * @note Does not delete plant objects - ownership managed externally
     */
    virtual ~PlantArrangement();

    /**
     * @brief Sets the arrangement name
     * @param name Name for this arrangement
     * @post Arrangement name is updated
     */
    void setName(const std::string& name);

    /**
     * @brief Sets the arrangement description
     * @param desc Detailed description of the arrangement
     * @post Arrangement description is updated
     */
    void setDescription(const std::string& desc);

    /**
     * @brief Sets the base price (excluding plants)
     * @param price Base price for arrangement assembly and container
     * @post Base price is updated
     * @note Total price includes plant costs
     */
    void setBasePrice(double price);

    /**
     * @brief Sets the container type
     * @param container Type of container (basket, planter, vase, etc.)
     * @post Container type is updated
     */
    void setContainerType(const std::string& container);

    /**
     * @brief Adds a plant to the arrangement
     * @param plant Pointer to Plant to add
     * @pre plant should be a valid Plant pointer
     * @post Plant is added to the arrangement's plant list
     * @note Does not transfer ownership of plant
     */
    void addPlant(Plant* plant);

    /**
     * @brief Gets the arrangement name
     * @return Name of the arrangement
     */
    std::string getName() const;

    /**
     * @brief Gets the arrangement description
     * @return Detailed description of the arrangement
     */
    std::string getDescription() const;

    /**
     * @brief Gets the base price (excluding plants)
     * @return Base price for arrangement and container
     * @note Use getTotalPrice() for complete cost including plants
     */
    double getBasePrice() const;

    /**
     * @brief Gets the total price including all plants
     * @return Total price (base price + sum of all plant prices)
     *
     * Calculates the complete cost by adding the base arrangement
     * price to the sum of all included plant prices.
     *
     * @post No modification to arrangement state
     */
    double getTotalPrice() const;

    /**
     * @brief Gets the container type
     * @return Type of container used in arrangement
     */
    std::string getContainerType() const;

    /**
     * @brief Gets reference to the plant collection
     * @return Const reference to vector of plant pointers
     * @note Returned vector should not be modified
     */
    const std::vector<Plant*>& getPlants() const;

    /**
     * @brief Gets the number of plants in arrangement
     * @return Count of plants in the arrangement
     */
    int getPlantCount() const;

    /**
     * @brief Displays complete arrangement information
     * @details Outputs name, description, container, plants, and pricing
     * @post Arrangement details displayed to standard output
     */
    void display() const;
};

#endif // PLANTARRANGEMENT_H