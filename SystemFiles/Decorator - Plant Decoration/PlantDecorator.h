/**
 * @file PlantDecorator.h
 * @brief Header file for the PlantDecorator abstract decorator class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "PlantProduct.h"

/**
 * @class PlantDecorator
 * @brief Abstract decorator class for adding features to plant products
 * @ingroup Decorator
 *
 * PlantDecorator serves as the Decorator in the Decorator design pattern.
 * It wraps a PlantProduct (either a BasicPlant or another decorator) and
 * provides a base for concrete decorators to add additional features like
 * decorative pots, gift wrapping, or greeting cards.
 *
 * This class maintains a reference to the wrapped product and delegates
 * operations to it while allowing subclasses to enhance or modify the
 * behavior. It provides the foundation for the transparent decoration
 * of plant products.
 *
 * PlantDecorator inherits from PlantProduct, making it interchangeable
 * with the objects it decorates. This allows decorators to be nested,
 * creating complex combinations of features.
 *
 * @par Design Pattern Role:
 * - Decorator: PlantDecorator (this class)
 * - Component: PlantProduct
 * - ConcreteComponent: BasicPlant
 * - ConcreteDecorators: DecorativePotDecorator, GiftWrappingDecorator, GreetingCardDecorator
 *
 * @par Key Decorator Pattern Features:
 * - Wraps a PlantProduct reference
 * - Maintains same interface as PlantProduct
 * - Allows dynamic addition of responsibilities
 * - Enables decorator nesting/stacking
 *
 * @par Usage Example:
 * @code
 * PlantProduct* product = new BasicPlant(rose);
 * product = new DecorativePotDecorator(product);  // Add pot
 * product = new GiftWrappingDecorator(product);   // Add wrapping
 * product = new GreetingCardDecorator(product);   // Add card
 * cout << "Total: R" << product->getPrice() << endl;
 * @endcode
 *
 * @see PlantProduct
 * @see BasicPlant
 * @see DecorativePotDecorator
 * @see GiftWrappingDecorator
 * @see GreetingCardDecorator
 */
class PlantDecorator : public PlantProduct {
protected:
    /**
     * @brief Pointer to the wrapped product being decorated
     * @details Maintains reference to the PlantProduct this decorator enhances
     */
    PlantProduct* wrappedProduct;

public:
    /**
     * @brief Default constructor
     * @details Creates a decorator with no wrapped product
     * @post PlantDecorator is created with nullptr wrappedProduct
     */
    PlantDecorator();

    /**
     * @brief Constructor with product parameter
     * @param product Pointer to the PlantProduct to wrap/decorate
     *
     * Creates a decorator that wraps the specified product. This is
     * the typical way decorators are constructed.
     *
     * @pre product should be a valid PlantProduct pointer
     * @post PlantDecorator is initialized wrapping the given product
     */
    explicit PlantDecorator(PlantProduct* product);

    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of decorator objects
     *
     * @note Does not delete wrappedProduct - ownership chain must be
     *       managed by the client code
     */
    virtual ~PlantDecorator();

    /**
     * @brief Pure virtual method to get decorated price
     * @return Total price including this decorator's cost
     *
     * Must be implemented by concrete decorators. Typically returns
     * wrappedProduct->getPrice() + decorator's additional cost.
     *
     * @note Concrete decorators implement: return wrapped->getPrice() + myCost
     * @warning Must be implemented by all concrete decorator classes
     */
    virtual double getPrice() const override = 0;

    /**
     * @brief Pure virtual method to get decorated description
     * @return Complete description including this decorator's addition
     *
     * Must be implemented by concrete decorators. Typically returns
     * wrappedProduct->getDescription() + decorator's description.
     *
     * @note Concrete decorators implement: return wrapped->getDescription() + myDesc
     * @warning Must be implemented by all concrete decorator classes
     */
    virtual std::string getDescription() const override = 0;

    /**
     * @brief Displays the decorated product information
     * @details Default implementation delegates to wrapped product
     *
     * Outputs the complete product information including all nested
     * decorations. Can be overridden by concrete decorators for
     * custom display formatting.
     *
     * @post Product information with all decorations is displayed
     * @note Default delegates to wrappedProduct->display()
     */
    virtual void display() const override;

    /**
     * @brief Gets the wrapped product reference
     * @return Pointer to the wrapped PlantProduct
     *
     * Provides access to the product this decorator wraps. Useful for
     * accessing the decoration chain or unwrapping decorators.
     *
     * @return Pointer to wrapped PlantProduct, or nullptr if none
     * @note Returned pointer should not be deleted by caller
     */
    PlantProduct* getWrappedProduct() const;

    /**
     * @brief Sets the wrapped product reference
     * @param product Pointer to the PlantProduct to wrap
     *
     * Allows changing the product this decorator wraps. Use with
     * caution as it can break the decoration chain.
     *
     * @pre product should be a valid PlantProduct pointer
     * @post wrappedProduct is updated to point to product
     * @note Previous wrapped product is not deleted
     * @warning Does not transfer ownership
     */
    void setWrappedProduct(PlantProduct* product);
};

#endif // PLANTDECORATOR_H