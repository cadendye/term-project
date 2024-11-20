// Dyar Jankir, Caden Dye, Arthas Lee
#include "Customer.h"
#include <regex>

/**
 * @brief Constructor for the Customer class with validation checks.
 * 
 * @param customerID The unique identifier for the customer. Must be a valid, non-empty string.
 * @param userName The username chosen by the customer. Must be a valid string according to `isUserNameValid`.
 * @param firstName The first name of the customer. Must be a valid string according to `isNameValid`.
 * @param lastName The last name of the customer. Must be a valid string according to `isNameValid`.
 * @param age The age of the customer. Must be a valid integer according to `isAgeValid`.
 * @param creditCardNumber The credit card number of the customer. Must be a valid string according to `isCreditCardValid`.
 * @param rewardPoints The number of reward points the customer has. Must be a valid integer.
 * 
 * @throws std::invalid_argument If any of the validation checks fail for the parameters.
 */
Customer::Customer(const std::string& customerID, const std::string& userName, const std::string& firstName,
                   const std::string& lastName, int age, const std::string& creditCardNumber, int rewardPoints)
                   : customerID(customerID), rewardPoints(rewardPoints) {
    if (!isUserNameValid(userName) || !isNameValid(firstName) || !isNameValid(lastName) ||
        !isAgeValid(age) || !isCreditCardValid(creditCardNumber)) {
        throw std::invalid_argument("Invalid customer data provided.");
    }
    else {
        // do nothing
    }
    
    this->userName = userName;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->creditCardNumber = creditCardNumber;
}


/**
 * @brief Validates the customer's username.
 * 
 * @param userName The username chosen by the customer. The username must start with 'U', followed by up to three digits, 
 *                 and then at least six alphanumeric characters.
 * @return bool Returns true if the username is valid, otherwise false.
 */
bool Customer::isUserNameValid(const std::string& userName) {
    return std::regex_match(userName, std::regex("^U\\d{0,3}[A-Za-z0-9]{6,}$"));
}


/**
 * @brief Validates the customer's first or last name.
 * 
 * @param name The name of the customer, either first or last name. The name must consist of 1 to 12 alphabetic characters.
 * @return bool Returns true if the name is valid, otherwise false.
 */
bool Customer::isNameValid(const std::string& name) {
    return std::regex_match(name, std::regex("^[A-Za-z]{1,12}$"));
}


/**
 * @brief Validates the customer's age.
 * 
 * @param age The age of the customer. Must be an integer between 18 and 100, inclusive.
 * @return bool Returns true if the age is valid, otherwise false.
 */
bool Customer::isAgeValid(int age) {
    return age >= 18 && age <= 100;
}


/**
 * @brief Validates the customer's credit card number.
 * 
 * @param creditCard The credit card number of the customer. The credit card number must follow the format of 
 *                   four digits (not starting with 0), followed by a hyphen, then four digits, another hyphen, 
 *                   and four more digits (e.g., 1234-5678-1234).
 * @return bool Returns true if the credit card number is valid, otherwise false.
 */
bool Customer::isCreditCardValid(const std::string& creditCard) {
    return std::regex_match(creditCard, std::regex("^[1-9]\\d{3}-\\d{4}-\\d{4}$"));
}


/**
 * @brief Retrieves the unique identifier for the customer.
 * 
 * @return std::string The unique identifier of the customer.
 */
std::string Customer::getCustomerID() const { return customerID; }

/**
 * @brief Retrieves the username of the customer.
 * 
 * @return std::string The username of the customer.
 */
std::string Customer::getUserName() const { return userName; }

/**
 * @brief Retrieves the first name of the customer.
 * 
 * @return std::string The first name of the customer.
 */
std::string Customer::getFirstName() const { return firstName; }

/**
 * @brief Retrieves the last name of the customer.
 * 
 * @return std::string The last name of the customer.
 */
std::string Customer::getLastName() const { return lastName; }

/**
 * @brief Retrieves the age of the customer.
 * 
 * @return int The age of the customer.
 */
int Customer::getAge() const { return age; }

/**
 * @brief Retrieves the credit card number of the customer.
 * 
 * @return std::string The credit card number of the customer.
 */
std::string Customer::getCreditCardNumber() const { return creditCardNumber; }

/**
 * @brief Retrieves the reward points of the customer.
 * 
 * @return int The reward points of the customer.
 */
int Customer::getRewardPoints() const { return rewardPoints; }

/**
 * @brief Adds reward points to the customer's account. Can also subtract points if a negative value is passed.
 * 
 * @param points The number of points to add (or subtract if negative) to the customer's reward points.
 */
void Customer::addRewardPoints(int points) {
    rewardPoints += points; // Adds (or subtracts if points are negative) to the reward points
}

