/**
 * @file PlantProduct.h
 * @brief Header file for the PlantProduct abstract base class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef PLANTPRODUCT_H
#define PLANTPRODUCT_H

#include <string>

// Forward declaration
class Plant;

/**
 * @class PlantProduct
 * @brief Abstract component class for plant products in the Decorator pattern
 * @ingroup Decorator
 *
 * This class serves as the Component in the Decorator design pattern,
 * defining the interface for objects that can have responsibilities
 * added to them dynamically. It represents a plant product that can be
 * sold, either as a basic plant or with various decorations added.
 *
 * PlantProduct provides the base interface that both concrete components
 * (BasicPlant) and decorators (PlantDecorator and its subclasses) must
 * implement. This allows decorators to wrap basic plants and other
 * decorated plants transparently.
 *
 * @par Design Pattern Role:
 * - Component: PlantProduct (this class)
 * - ConcreteComponent: BasicPlant
 * - Decorator: PlantDecorator
 * - ConcreteDecorator: DecorativePotDecorator, GiftWrappingDecorator, GreetingCardDecorator
 *
 * @par Usage Example:
 * @code
 * Plant* rose = new Rose();
 * PlantProduct* product = new BasicPlant(rose);
 * product = new DecorativePotDecorator(product);
 * product = new GiftWrappingDecorator(product);
 * cout << "Price: R" << product->getPrice() << endl;
 * @endcode
 *
 * @see BasicPlant
 * @see PlantDecorator
 * @see DecorativePotDecorator
 * @see GiftWrappingDecorator
 * @see GreetingCardDecorator
 * @see Plant
 */
class PlantProduct {
protected:
    /**
     * @brief Pointer to the actual plant being sold
     * @details Maintains reference to the Plant object that forms the core of this product
     */
    Plant* plant;

public:
    /**
     * @brief Default constructor
     * @details Initializes plant product with nullptr plant
     * @post plant member is set to nullptr
     */
    PlantProduct();

    /**
     * @brief Constructor with plant parameter
     * @param p Pointer to the Plant object for this product
     *
     * @pre p should be a valid Plant pointer
     * @post PlantProduct is initialized with the given plant
     */
    explicit PlantProduct(Plant* p);

    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of derived class objects
     *
     * @note Does not delete the plant object - ownership remains with caller
     */
    virtual ~PlantProduct();

    /**
     * @brief Pure virtual method to get the total price
     * @return Total price of the product including all decorations
     *
     * This method must be implemented by all concrete components and
     * decorators. Decorators typically add their cost to the wrapped
     * product's price.
     *
     * @note For decorators, this typically returns wrappedProduct->getPrice() + decoratorCost
     * @warning Must be implemented by all derived classes
     */
    virtual double getPrice() const = 0;

    /**
     * @brief Pure virtual method to get product description
     * @return String description of the product including all decorations
     *
     * This method must be implemented by all concrete components and
     * decorators. Decorators typically append their description to the
     * wrapped product's description.
     *
     * @note For decorators, this typically returns wrappedProduct->getDescription() + decoratorDesc
     * @warning Must be implemented by all derived classes
     */
    virtual std::string getDescription() const = 0;

    /**
     * @brief Pure virtual method to display product information
     * @details Must be implemented to show product details to console
     *
     * This method provides a way to output product information in a
     * user-friendly format. Implementations should include price,
     * description, and any relevant decorations.
     *
     * @post Product information is displayed to standard output
     * @warning Must be implemented by all derived classes
     */
    virtual void display() const = 0;

    /**
     * @brief Gets the underlying plant object
     * @return Pointer to the Plant object
     *
     * Provides access to the core plant that this product wraps.
     * Useful for accessing plant-specific properties beyond the
     * product interface.
     *
     * @return Pointer to Plant, or nullptr if no plant is set
     * @note Returned pointer should not be deleted by caller
     */
    Plant* getPlant() const;

    /**
     * @brief Sets the underlying plant object
     * @param p Pointer to the Plant object to set
     *
     * Allows changing the plant associated with this product.
     *
     * @pre p should be a valid Plant pointer
     * @post plant member is updated to point to p
     * @note Previous plant is not deleted - caller retains ownership
     * @warning Does not transfer ownership of the plant
     */
    void setPlant(Plant* p);
};

#endif // PLANTPRODUCT_H