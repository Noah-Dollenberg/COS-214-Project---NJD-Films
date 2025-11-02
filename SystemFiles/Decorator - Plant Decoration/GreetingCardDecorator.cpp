#include "GreetingCardDecorator.h"
#include <iostream>
#include <iomanip>

GreetingCardDecorator::GreetingCardDecorator()
    : PlantDecorator(), cardType("birthday"), message(""),
      recipient(""), sender(""), cardPrice(15.0) {}

GreetingCardDecorator::GreetingCardDecorator(PlantProduct* product,
                                             const std::string& type,
                                             const std::string& msg,
                                             const std::string& to,
                                             const std::string& from)
    : PlantDecorator(product), cardType(type), message(msg),
      recipient(to), sender(from) {

    // Set price based on card type
    if (type == "birthday") cardPrice = 15.0;
    else if (type == "thank_you") cardPrice = 12.0;
    else if (type == "get_well") cardPrice = 12.0;
    else if (type == "congratulations") cardPrice = 15.0;
    else if (type == "custom") cardPrice = 25.0;
    else cardPrice = 10.0;
}

GreetingCardDecorator::~GreetingCardDecorator() {}

double GreetingCardDecorator::getPrice() const {
    double basePrice = wrappedProduct ? wrappedProduct->getPrice() : 0.0;
    return basePrice + cardPrice;
}

std::string GreetingCardDecorator::getDescription() const {
    std::string baseDesc = wrappedProduct ? wrappedProduct->getDescription() : "Unknown";
    return baseDesc + " + " + cardType + " card";
}

void GreetingCardDecorator::display() const {
    if (wrappedProduct) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "PLANT WITH GREETING CARD" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Base Product: " << wrappedProduct->getDescription() << std::endl;
        std::cout << "Base Price: R" << std::fixed << std::setprecision(2)
                  << wrappedProduct->getPrice() << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Card Type: " << cardType << std::endl;
        if (!recipient.empty()) std::cout << "To: " << recipient << std::endl;
        if (!sender.empty()) std::cout << "From: " << sender << std::endl;
        if (!message.empty()) {
            std::cout << "Message: \"" << message << "\"" << std::endl;
        }
        std::cout << "Card Price: R" << std::fixed << std::setprecision(2)
                  << cardPrice << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "TOTAL PRICE: R" << std::fixed << std::setprecision(2)
                  << getPrice() << std::endl;
        std::cout << "========================================\n" << std::endl;
    }
}

std::string GreetingCardDecorator::getCardType() const { return cardType; }
void GreetingCardDecorator::setCardType(const std::string& type) { cardType = type; }

std::string GreetingCardDecorator::getMessage() const { return message; }
void GreetingCardDecorator::setMessage(const std::string& msg) { message = msg; }

std::string GreetingCardDecorator::getRecipient() const { return recipient; }
void GreetingCardDecorator::setRecipient(const std::string& to) { recipient = to; }

std::string GreetingCardDecorator::getSender() const { return sender; }
void GreetingCardDecorator::setSender(const std::string& from) { sender = from; }

double GreetingCardDecorator::getCardPrice() const { return cardPrice; }
