// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <stdexcept>

class Customer {
private:
    std::string customerID;
    std::string userName;
    std::string firstName;
    std::string lastName;
    int age;
    std::string creditCardNumber;
    int rewardPoints;

    bool isUserNameValid(const std::string& userName);
    bool isNameValid(const std::string& name);
    bool isAgeValid(int age);
    bool isCreditCardValid(const std::string& creditCard);

public:
    Customer(const std::string& customerID, const std::string& userName, const std::string& firstName,
             const std::string& lastName, int age, const std::string& creditCardNumber, int rewardPoints);

    std::string getCustomerID() const;
    std::string getUserName() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;
    std::string getCreditCardNumber() const;
    int getRewardPoints() const;
    void addRewardPoints(int points);
};

#endif // CUSTOMER_H
