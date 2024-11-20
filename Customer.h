// Dyar Jankir, Caden Dye, Arthas Lee
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <stdexcept>

/**
 * @class Customer
 * @brief Represents a customer with relevant attributes and validation.
 */
class Customer {
private:
    std::string customerID;          ///< Unique identifier for the customer.
    std::string userName;            ///< Username chosen by the customer.
    std::string firstName;           ///< First name of the customer.
    std::string lastName;            ///< Last name of the customer.
    int age;                         ///< Age of the customer.
    std::string creditCardNumber;    ///< Credit card number of the customer.
    int rewardPoints;                ///< Reward points accumulated by the customer.

    /**
     * @brief Validates the customer's username.
     * @param userName The username to validate.
     * @return bool True if the username is valid, false otherwise.
     */
    bool isUserNameValid(const std::string& userName);

    /**
     * @brief Validates a name (first or last).
     * @param name The name to validate.
     * @return bool True if the name is valid, false otherwise.
     */
    bool isNameValid(const std::string& name);

    /**
     * @brief Validates the customer's age.
     * @param age The age to validate.
     * @return bool True if the age is within the valid range, false otherwise.
     */
    bool isAgeValid(int age);

    /**
     * @brief Validates the customer's credit card number.
     * @param creditCard The credit card number to validate.
     * @return bool True if the credit card number is valid, false otherwise.
     */
    bool isCreditCardValid(const std::string& creditCard);

public:
    /**
     * @brief Constructor for the Customer class with validation checks.
     * @param customerID The unique identifier for the customer.
     * @param userName The username chosen by the customer.
     * @param firstName The first name of the customer.
     * @param lastName The last name of the customer.
     * @param age The age of the customer.
     * @param creditCardNumber The credit card number of the customer.
     * @param rewardPoints The number of reward points the customer has.
     * @throws std::invalid_argument If any validation checks fail.
     */
    Customer(const std::string& customerID, const std::string& userName, const std::string& firstName,
             const std::string& lastName, int age, const std::string& creditCardNumber, int rewardPoints);

    /**
     * @brief Retrieves the unique identifier for the customer.
     * @return std::string The unique identifier.
     */
    std::string getCustomerID() const;

    /**
     * @brief Retrieves the username of the customer.
     * @return std::string The username.
     */
    std::string getUserName() const;

    /**
     * @brief Retrieves the first name of the customer.
     * @return std::string The first name.
     */
    std::string getFirstName() const;

    /**
     * @brief Retrieves the last name of the customer.
     * @return std::string The last name.
     */
    std::string getLastName() const;

    /**
     * @brief Retrieves the age of the customer.
     * @return int The age.
     */
    int getAge() const;

    /**
     * @brief Retrieves the credit card number of the customer.
     * @return std::string The credit card number.
     */
    std::string getCreditCardNumber() const;

    /**
     * @brief Retrieves the reward points of the customer.
     * @return int The reward points.
     */
    int getRewardPoints() const;

    /**
     * @brief Adds reward points to the customer's account.
     * @param points The number of points to add (or subtract if negative).
     */
    void addRewardPoints(int points);
};

#endif // CUSTOMER_H
