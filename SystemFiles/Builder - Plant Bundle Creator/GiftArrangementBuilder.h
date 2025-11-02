/**
 * @file GiftArrangementBuilder.h
 * @brief Header file for the GiftArrangementBuilder concrete builder class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef GIFTARRANGEMENTBUILDER_H
#define GIFTARRANGEMENTBUILDER_H
#include "PlantArrangementBuilder.h"
#include <vector>

// Forward declaration
class Plant;

/**
 * @class GiftArrangementBuilder
 * @brief Concrete builder for constructing gift-style plant arrangements
 * @ingroup Builder
 *
 * GiftArrangementBuilder is a ConcreteBuilder in the Builder design pattern that
 * specializes in creating romantic, decorative plant arrangements suitable for gifts.
 * It implements the construction steps to create beautiful gift packages with roses,
 * decorative containers, and gift-appropriate styling.
 *
 * This builder creates arrangements focused on aesthetic appeal and gift presentation,
 * typically featuring roses in decorative baskets with romantic themes. It handles
 * the complete construction process including container selection, plant arrangement,
 * and pricing specific to gift products.
 *
 * @par Design Pattern Role:
 * - ConcreteBuilder: GiftArrangementBuilder (this class)
 * - Builder: PlantArrangementBuilder
 * - Product: PlantArrangement
 * - Director: ArrangementDirector
 *
 * @par Typical Gift Arrangement Features:
 * - Romantic rose selections
 * - Decorative gift baskets
 * - Aesthetic presentation focus
 * - Gift-appropriate pricing
 *
 * @par Usage Example:
 * @code
 * GiftArrangementBuilder builder;
 * ArrangementDirector director;
 * director.setBuilder(&builder);
 * PlantArrangement* gift = director.constructDeluxeArrangement();
 * @endcode
 *
 * @see PlantArrangementBuilder
 * @see PlantArrangement
 * @see LandscapeArrangementBuilder
 * @see ArrangementDirector
 */
class GiftArrangementBuilder : public PlantArrangementBuilder {
private:
    /** @brief Pool of available plants to select from for arrangement */
    std::vector<Plant*> availablePlants;

public:
    /**
     * @brief Default constructor
     * @post GiftArrangementBuilder created with empty available plants list
     */
    GiftArrangementBuilder();

    /**
     * @brief Virtual destructor
     * @note Does not delete plants or arrangement
     */
    virtual ~GiftArrangementBuilder();

    /**
     * @brief Sets the pool of available plants for selection
     * @param plants Vector of plant pointers to choose from
     * @post Available plants list is updated
     * @note Does not transfer ownership of plants
     */
    void setAvailablePlants(const std::vector<Plant*>& plants);

    /**
     * @brief Resets builder state and creates new arrangement
     * @post Fresh PlantArrangement object ready for construction
     */
    void reset() override;

    /**
     * @brief Sets gift arrangement name and description
     * @post Arrangement has romantic/gift-themed name and description
     */
    void setBasicInfo() override;

    /**
     * @brief Selects decorative gift basket container
     * @post Arrangement has gift-appropriate container specified
     */
    void selectContainer() override;

    /**
     * @brief Adds roses and gift-appropriate plants
     * @post Romantic plants added to arrangement
     */
    void addPlants() override;

    /**
     * @brief Adds decorative elements like ribbons
     * @post Gift decorations added to arrangement
     */
    void addDecorations() override;

    /**
     * @brief Calculates total price for gift arrangement
     * @post Arrangement has final gift price set
     */
    void calculatePrice() override;
};

#endif // GIFTARRANGEMENTBUILDER_H