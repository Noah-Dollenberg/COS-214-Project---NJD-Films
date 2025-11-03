/**
 * @file ArrangementDirector.h
 * @brief Header file for the ArrangementDirector director class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef ARRANGEMENTDIRECTOR_H
#define ARRANGEMENTDIRECTOR_H

// Forward declarations
class PlantArrangementBuilder;
class PlantArrangement;

/**
 * @class ArrangementDirector
 * @brief Director class that orchestrates the plant arrangement construction process
 * @ingroup Builder
 *
 * ArrangementDirector serves as the Director in the Builder design pattern. It controls
 * the construction sequence of complex PlantArrangement objects by directing a builder
 * through specific construction steps. The director knows which steps to execute and
 * in what order, but delegates the actual work to the builder.
 *
 * The director provides high-level construction methods (like constructSimpleArrangement
 * or constructDeluxeArrangement) that execute predefined sequences of builder steps.
 * This allows client code to request standard arrangements without knowing the
 * construction details.
 *
 * The director works with any PlantArrangementBuilder implementation, making it easy
 * to use the same construction logic with different builder types (Gift, Landscape, etc.)
 * to produce different results.
 *
 * @par Design Pattern Role:
 * - Director: ArrangementDirector (this class)
 * - Builder: PlantArrangementBuilder
 * - ConcreteBuilders: GiftArrangementBuilder, LandscapeArrangementBuilder
 * - Product: PlantArrangement
 *
 * @par Director Responsibilities:
 * - Knows the construction algorithm
 * - Controls builder execution order
 * - Provides high-level construction methods
 * - Hides construction complexity from clients
 *
 * @par Usage Example:
 * @code
 * GiftArrangementBuilder giftBuilder;
 * ArrangementDirector director;
 * director.setBuilder(&giftBuilder);
 * PlantArrangement* deluxeGift = director.constructDeluxeArrangement();
 *
 * LandscapeArrangementBuilder landscapeBuilder;
 * director.setBuilder(&landscapeBuilder);
 * PlantArrangement* simpleGarden = director.constructSimpleArrangement();
 * @endcode
 *
 * @see PlantArrangementBuilder
 * @see PlantArrangement
 * @see GiftArrangementBuilder
 * @see LandscapeArrangementBuilder
 */
class ArrangementDirector {
private:
    /**
     * @brief Pointer to the current builder being directed
     * @details The builder that will execute construction steps
     */
    PlantArrangementBuilder* builder;

public:
    /**
     * @brief Default constructor
     * @post Director created with nullptr builder
     */
    ArrangementDirector();

    /**
     * @brief Virtual destructor
     * @note Does not delete builder - ownership remains with client
     */
    virtual ~ArrangementDirector();

    /**
     * @brief Sets the builder to direct
     * @param builder Pointer to PlantArrangementBuilder to use
     *
     * Assigns a builder for the director to control. The builder can be
     * changed at any time to construct different types of arrangements.
     *
     * @pre builder should be a valid PlantArrangementBuilder pointer
     * @post Director will use this builder for construction
     * @note Does not transfer ownership of builder
     */
    void setBuilder(PlantArrangementBuilder* builder);

    /**
     * @brief Constructs a simple arrangement
     * @return Pointer to completed PlantArrangement
     *
     * Directs the builder through a simplified construction sequence
     * suitable for basic, budget-friendly arrangements.
     *
     * Construction sequence:
     * 1. reset()
     * 2. setBasicInfo()
     * 3. selectContainer()
     * 4. addPlants() (minimal)
     * 5. calculatePrice()
     *
     * @pre Builder must be set
     * @return Completed PlantArrangement, or nullptr if builder not set
     * @note Caller assumes ownership of returned arrangement
     */
    PlantArrangement* constructSimpleArrangement();

    /**
     * @brief Constructs a deluxe arrangement
     * @return Pointer to completed PlantArrangement
     *
     * Directs the builder through a complete construction sequence
     * for premium, fully-featured arrangements with decorations.
     *
     * Construction sequence:
     * 1. reset()
     * 2. setBasicInfo()
     * 3. selectContainer()
     * 4. addPlants() (generous)
     * 5. addDecorations()
     * 6. calculatePrice()
     *
     * @pre Builder must be set
     * @return Completed premium PlantArrangement, or nullptr if builder not set
     * @note Caller assumes ownership of returned arrangement
     */
    PlantArrangement* constructDeluxeArrangement();

    /**
     * @brief Constructs a custom arrangement
     * @param includeDecorations Whether to add decorations
     * @return Pointer to completed PlantArrangement
     *
     * Directs the builder through a customizable construction sequence
     * where the client can specify certain options like decorations.
     *
     * Construction sequence:
     * 1. reset()
     * 2. setBasicInfo()
     * 3. selectContainer()
     * 4. addPlants()
     * 5. addDecorations() (if includeDecorations is true)
     * 6. calculatePrice()
     *
     * @pre Builder must be set
     * @param includeDecorations true to add decorative elements, false to skip
     * @return Completed customized PlantArrangement, or nullptr if builder not set
     * @note Caller assumes ownership of returned arrangement
     */
    PlantArrangement* constructCustomArrangement(bool includeDecorations);
};

#endif // ARRANGEMENTDIRECTOR_H