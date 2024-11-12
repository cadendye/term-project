// Customer.cpp
#include "Customer.h"
#include <regex>

// Constructor with validation checks
Customer::Customer(const std::string& customerID, const std::string& userName, const std::string& firstName,
                   const std::string& lastName, int age, const std::string& creditCardNumber, int rewardPoints)
                   : customerID(customerID), rewardPoints(rewardPoints) {
    if (!isUserNameValid(userName) || !isNameValid(firstName) || !isNameValid(lastName) ||
        !isAgeValid(age) || !isCreditCardValid(creditCardNumber)) {
        throw std::invalid_argument("Invalid customer data provided.");
    }
    this->userName = userName;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->creditCardNumber = creditCardNumber;
}

// Validation functions
bool Customer::isUserNameValid(const std::string& userName) {
    return std::regex_match(userName, std::regex("^U\\d{0,3}[A-Za-z0-9]{6,}$"));
}

bool Customer::isNameValid(const std::string& name) {
    return std::regex_match(name, std::regex("^[A-Za-z]{1,12}$"));
}

bool Customer::isAgeValid(int age) {
    return age >= 18 && age <= 100;
}

bool Customer::isCreditCardValid(const std::string& creditCard) {
    return std::regex_match(creditCard, std::regex("^[1-9]\\d{3}-\\d{4}-\\d{4}$"));
}

// Getters
std::string Customer::getCustomerID() const { return customerID; }
std::string Customer::getUserName() const { return userName; }
std::string Customer::getFirstName() const { return firstName; }
std::string Customer::getLastName() const { return lastName; }
int Customer::getAge() const { return age; }
std::string Customer::getCreditCardNumber() const { return creditCardNumber; }
int Customer::getRewardPoints() const { return rewardPoints; }

// Add reward points
void Customer::addRewardPoints(int points) {
    if (points > 0) rewardPoints += points;
}
