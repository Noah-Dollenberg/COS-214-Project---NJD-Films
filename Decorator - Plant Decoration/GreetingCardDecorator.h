/**
 * @file GreetingCardDecorator.h
 * @brief Header file for the GreetingCardDecorator concrete decorator class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef GREETINGCARDDECORATOR_H
#define GREETINGCARDDECORATOR_H

#include "PlantDecorator.h"
#include <string>

/**
 * @class GreetingCardDecorator
 * @brief Concrete decorator that adds a personalized greeting card to plant products
 * @ingroup Decorator
 *
 * GreetingCardDecorator is a ConcreteDecorator in the Decorator pattern that enhances
 * plant products by including a personalized greeting card. This adds a personal touch
 * to gifts, allowing customers to include custom messages for various occasions.
 *
 * The decorator supports multiple card types (birthday, thank_you, get_well,
 * congratulations, custom) and allows for personalized messages with recipient
 * and sender information. It's perfect for completing gift packages by adding
 * a heartfelt personal message.
 *
 * @par Design Pattern Role:
 * - ConcreteDecorator: GreetingCardDecorator (this class)
 * - Decorator: PlantDecorator
 * - Component: PlantProduct
 *
 * @par Available Card Types:
 * - "birthday" - Birthday celebration card (default)
 * - "thank_you" - Thank you appreciation card
 * - "get_well" - Get well soon card
 * - "congratulations" - Congratulations card
 * - "custom" - Custom message card
 *
 * @par Usage Example:
 * @code
 * PlantProduct* product = new BasicPlant(rose);
 * product = new DecorativePotDecorator(product);
 * product = new GiftWrappingDecorator(product);
 * product = new GreetingCardDecorator(product, "birthday",
 *                                      "Happy Birthday!", "Mom", "Sarah");
 * product->display();  // Shows complete gift package with card
 * @endcode
 *
 * @see PlantDecorator
 * @see PlantProduct
 * @see DecorativePotDecorator
 * @see GiftWrappingDecorator
 */
class GreetingCardDecorator : public PlantDecorator {
private:
    /** @brief Type of greeting card (birthday, thank_you, get_well, etc.) */
    std::string cardType;

    /** @brief Personalized message on the card */
    std::string message;

    /** @brief Name of the card recipient */
    std::string recipient;

    /** @brief Name of the card sender */
    std::string sender;

    /** @brief Price of the greeting card (R15 standard) */
    double cardPrice;

public:
    /**
     * @brief Default constructor
     * @post Creates decorator with birthday card at R15
     */
    GreetingCardDecorator();

    /**
     * @brief Constructor with customization parameters
     * @param product Pointer to the PlantProduct to decorate
     * @param type Card type (birthday, thank_you, get_well, congratulations, custom)
     * @param msg Personalized message for the card
     * @param to Recipient's name
     * @param from Sender's name
     *
     * Creates a decorator that adds a greeting card with the specified
     * type and personalized message details.
     *
     * @pre product should be a valid PlantProduct pointer
     * @post Decorator wraps product with personalized greeting card
     * @note Empty strings for msg, to, from are allowed for later customization
     */
    GreetingCardDecorator(PlantProduct* product,
                          const std::string& type = "birthday",
                          const std::string& msg = "",
                          const std::string& to = "",
                          const std::string& from = "");

    /**
     * @brief Virtual destructor
     * @note Does not delete wrapped product
     */
    virtual ~GreetingCardDecorator();

    /**
     * @brief Gets total price including greeting card
     * @return Base product price plus card price (R15)
     */
    double getPrice() const override;

    /**
     * @brief Gets description including card details
     * @return Product description with card type and personalization info
     */
    std::string getDescription() const override;

    /**
     * @brief Displays product with greeting card information
     * @post Product and card information displayed to console
     */
    void display() const override;

    /**
     * @brief Gets the card type
     * @return Current card type
     */
    std::string getCardType() const;

    /**
     * @brief Sets the card type
     * @param type New card type
     * @post cardType is updated
     */
    void setCardType(const std::string& type);

    /**
     * @brief Gets the card message
     * @return Current personalized message
     */
    std::string getMessage() const;

    /**
     * @brief Sets the card message
     * @param msg New personalized message
     * @post message is updated
     */
    void setMessage(const std::string& msg);

    /**
     * @brief Gets the recipient name
     * @return Current recipient name
     */
    std::string getRecipient() const;

    /**
     * @brief Sets the recipient name
     * @param to New recipient name
     * @post recipient is updated
     */
    void setRecipient(const std::string& to);

    /**
     * @brief Gets the sender name
     * @return Current sender name
     */
    std::string getSender() const;

    /**
     * @brief Sets the sender name
     * @param from New sender name
     * @post sender is updated
     */
    void setSender(const std::string& from);

    /**
     * @brief Gets the card price
     * @return Greeting card price (R15)
     * @note This is the added cost, not total product price
     */
    double getCardPrice() const;
};

#endif // GREETINGCARDDECORATOR_H
