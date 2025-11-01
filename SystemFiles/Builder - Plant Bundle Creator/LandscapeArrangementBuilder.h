/**
 * @file LandscapeArrangementBuilder.h
 * @brief Header file for the LandscapeArrangementBuilder concrete builder class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef LANDSCAPEARRANGEMENTBUILDER_H
#define LANDSCAPEARRANGEMENTBUILDER_H
#include <string>

#include "PlantArrangementBuilder.h"
#include <vector>

// Forward declaration
class Plant;

/**
 * @class LandscapeArrangementBuilder
 * @brief Concrete builder for constructing landscape-style plant arrangements
 * @ingroup Builder
 *
 * LandscapeArrangementBuilder is a ConcreteBuilder in the Builder design pattern
 * that specializes in creating outdoor garden and landscape arrangements. It implements
 * construction steps to create practical, themed plantings suitable for gardens,
 * patios, and outdoor spaces.
 *
 * This builder creates arrangements focused on landscaping functionality and outdoor
 * aesthetics, supporting various themes like desert, tropical, and formal gardens.
 * It handles plant selection appropriate for outdoor environments and uses containers
 * like planters and garden boxes.
 *
 * @par Design Pattern Role:
 * - ConcreteBuilder: LandscapeArrangementBuilder (this class)
 * - Builder: PlantArrangementBuilder
 * - Product: PlantArrangement
 * - Director: ArrangementDirector
 *
 * @par Supported Landscape Themes:
 * - "desert" - Cacti and succulents for arid environments
 * - "tropical" - Lush, moisture-loving plants
 * - "formal" - Structured, traditional garden plants
 * - "cottage" - Casual, mixed garden style
 *
 * @par Usage Example:
 * @code
 * LandscapeArrangementBuilder builder;
 * builder.setTheme("desert");
 * ArrangementDirector director;
 * director.setBuilder(&builder);
 * PlantArrangement* garden = director.constructSimpleArrangement();
 * @endcode
 *
 * @see PlantArrangementBuilder
 * @see PlantArrangement
 * @see GiftArrangementBuilder
 * @see ArrangementDirector
 */
class LandscapeArrangementBuilder : public PlantArrangementBuilder {
private:
    /** @brief Pool of available plants for selection */
    std::vector<Plant*> availablePlants;

    /** @brief Theme for landscape (desert, tropical, formal, etc.) */
    std::string landscapeTheme;

public:
    /**
     * @brief Default constructor
     * @post LandscapeArrangementBuilder created with default settings
     */
    LandscapeArrangementBuilder();

    /**
     * @brief Virtual destructor
     * @note Does not delete plants or arrangement
     */
    virtual ~LandscapeArrangementBuilder();

    /**
     * @brief Sets available plants pool
     * @param plants Vector of plant pointers to choose from
     * @post Available plants list is updated
     */
    void setAvailablePlants(const std::vector<Plant*>& plants);

    /**
     * @brief Sets the landscape theme
     * @param theme Theme name (desert, tropical, formal, cottage)
     * @post Landscape theme is set for plant selection
     */
    void setTheme(const std::string& theme);

    /**
     * @brief Resets builder and creates new arrangement
     * @post Fresh arrangement ready for construction
     */
    void reset() override;

    /**
     * @brief Sets landscape arrangement name and description
     * @post Arrangement has theme-appropriate name and description
     */
    void setBasicInfo() override;

    /**
     * @brief Selects outdoor-appropriate container
     * @post Arrangement has garden planter or box specified
     */
    void selectContainer() override;

    /**
     * @brief Adds theme-appropriate outdoor plants
     * @post Plants suitable for landscape theme added
     */
    void addPlants() override;

    /**
     * @brief Adds landscape decorations (rocks, mulch, etc.)
     * @post Landscape decorative elements added
     */
    void addDecorations() override;

    /**
     * @brief Calculates price for landscape arrangement
     * @post Arrangement has final landscape price set
     */
    void calculatePrice() override;
};

#endif // LANDSCAPEARRANGEMENTBUILDER_H