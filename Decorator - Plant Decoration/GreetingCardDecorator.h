#ifndef GREETINGCARDDECORATOR_H
#define GREETINGCARDDECORATOR_H

#include "PlantDecorator.h"
#include <string>

/**
 * @brief Adds a greeting card to a plant product
 *
 * Card types: birthday, thank_you, get_well, congratulations, custom
 */
class GreetingCardDecorator : public PlantDecorator {
private:
    std::string cardType;
    std::string message;
    std::string recipient;
    std::string sender;
    double cardPrice;

public:
    GreetingCardDecorator();
    GreetingCardDecorator(PlantProduct* product,
                          const std::string& type = "birthday",
                          const std::string& msg = "",
                          const std::string& to = "",
                          const std::string& from = "");
    virtual ~GreetingCardDecorator();

    double getPrice() const override;
    std::string getDescription() const override;
    void display() const override;

    // Card-specific methods
    std::string getCardType() const;
    void setCardType(const std::string& type);

    std::string getMessage() const;
    void setMessage(const std::string& msg);

    std::string getRecipient() const;
    void setRecipient(const std::string& to);

    std::string getSender() const;
    void setSender(const std::string& from);

    double getCardPrice() const;
};

#endif // GREETINGCARDDECORATOR_H
