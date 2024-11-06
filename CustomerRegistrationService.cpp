#include <string>
#include <stdexcept>
#include <random>
#include <algorithm>

class ValidationError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

/**
 * Represents a customer in the system with their personal and account information
 */
class Customer {
    std::string username;
    std::string firstName;
    std::string lastName;
    int age;
    std::string creditCard;
    std::string customerId;
    double rewardPoints = 0.0;

public:
    /**
     * Creates a new customer with the specified details
     * @param un Username in U_XXX format
     * @param fn First name (alphabetic characters only)
     * @param ln Last name (alphabetic characters only)
     * @param a Age between 18 and 100
     * @param cc Credit card number in XXXX-XXXXX-XXXX format
     * @param cid Unique customer ID
     */
    Customer(const std::string& un, const std::string& fn, const std::string& ln,
            int a, const std::string& cc, const std::string& cid)
        : username(un), firstName(fn), lastName(ln),
          age(a), creditCard(cc), customerId(cid) {}
    
    const std::string& getId() const { 
        return customerId; 
    }

    const std::string& getUsername() const { 
        return username; 
    }

    const std::string& getCreditCard() const { 
        return creditCard; 
    }

    double getRewardPoints() const { 
        return rewardPoints; 
    }

    void setRewardPoints(double points) { 
        rewardPoints = points; 
    }
};

class CustomerRegistry {
private:
    Customer** customers;
    int capacity;
    int count;

    /**
     * Doubles the capacity of the customers array
     */
    void expandCapacity() {
        int newCapacity = capacity * 2;
        Customer** newArray = new Customer*[newCapacity];
        
        for (int i = 0; i < count; i++) {
            newArray[i] = customers[i];
        }
        
        delete[] customers;
        customers = newArray;
        capacity = newCapacity;
    }

    /**
     * Validates a name contains only alphabetic characters
     * @param name The name to validate
     * @return True if name is valid, false otherwise
     */
    bool isNameValid(const std::string& name) {
        if (name.empty() || name.length() > 12) {
            return false;
        }
        else {
            return std::all_of(name.begin(), name.end(), isalpha);
        }
    }

    /**
     * Checks if a username is unique in the system
     * @param username The username to check
     * @return True if username is unique, false otherwise
     */
    bool isUsernameUnique(const std::string& username) {
        for (int i = 0; i < count; i++) {
            if (customers[i]->getUsername() == username) {
                return false;
            }
        }
        return true;
    }

    /**
     * Validates username format (U_XXX where X is a digit)
     * @param username The username to validate
     * @return True if username format is valid, false otherwise
     */
    bool isUsernameValid(const std::string& username) {
        if (username.length() < 3 || username.length() > 5) {
            return false;
        }
        else if (username.substr(0, 2) != "U_") {
            return false;
        }
        else {
            std::string numbers = username.substr(2);
            return std::all_of(numbers.begin(), numbers.end(), isdigit);
        }
    }

    /**
     * Checks if a credit card number is unique in the system
     * @param card The credit card number to check
     * @return True if credit card is unique, false otherwise
     */
    bool isCreditCardUnique(const std::string& card) {
        for (int i = 0; i < count; i++) {
            if (customers[i]->getCreditCard() == card) {
                return false;
            }
        }
        return true;
    }

    /**
     * Validates credit card format (XXXX-XXXXX-XXXX)
     * @param card The credit card number to validate
     * @return True if credit card format is valid, false otherwise
     */
    bool isCreditCardValid(const std::string& card) {
        if (card.length() != 14) {
            return false;
        }
        else if (card[4] != '-' || card[9] != '-') {
            return false;
        }
        else if (card[0] == '0') {
            return false;
        }
        else {
            return std::all_of(card.begin(), card.end(), 
                             [](char c) { return isdigit(c) || c == '-'; });
        }
    }

    /**
     * Generates a unique customer ID
     * @return A unique customer ID string
     */
    std::string generateCustomerId() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(1000000000, 9999999999);
        
        std::string id;
        bool isUnique;
        
        do {
            id = "CustID" + std::to_string(dis(gen));
            isUnique = true;
            
            for (int i = 0; i < count; i++) {
                if (customers[i]->getId() == id) {
                    isUnique = false;
                    break;
                }
            }
        } while (!isUnique);
        
        return id;
    }

    /**
     * Validates all customer registration parameters
     * @param username The username to validate
     * @param firstName The first name to validate
     * @param lastName The last name to validate
     * @param age The age to validate
     * @param creditCard The credit card to validate
     * @throws ValidationError if any parameter is invalid
     */
    void validateRegistrationParams(const std::string& username, 
                                  const std::string& firstName,
                                  const std::string& lastName, 
                                  int age,
                                  const std::string& creditCard) {
        if (!isUsernameValid(username)) {
            throw ValidationError("Invalid username format");
        }
        else if (!isUsernameUnique(username)) {
            throw ValidationError("Username already exists");
        }
        else if (!isNameValid(firstName)) {
            throw ValidationError("Invalid first name");
        }
        else if (!isNameValid(lastName)) {
            throw ValidationError("Invalid last name");
        }
        else if (age < 18 || age > 100) {
            throw ValidationError("Invalid age");
        }
        else if (!isCreditCardValid(creditCard)) {
            throw ValidationError("Invalid credit card format");
        }
        else if (!isCreditCardUnique(creditCard)) {
            throw ValidationError("Credit card already registered");
        }
    }

public:
    /**
     * Creates a new customer registry with specified initial capacity
     * @param initialCapacity The initial size of the customers array
     */
    CustomerRegistry(int initialCapacity = 10) : capacity(initialCapacity), count(0) {
        customers = new Customer*[capacity];
    }

    /**
     * Cleans up all allocated memory
     */
    ~CustomerRegistry() {
        for (int i = 0; i < count; i++) {
            delete customers[i];
        }
        delete[] customers;
    }

    /**
     * Registers a new customer in the system
     * @param username Customer's username
     * @param firstName Customer's first name
     * @param lastName Customer's last name
     * @param age Customer's age
     * @param creditCard Customer's credit card number
     * @return The generated customer ID
     * @throws ValidationError if any parameter is invalid
     */
    std::string registerCustomer(const std::string& username, 
                               const std::string& firstName,
                               const std::string& lastName, 
                               int age,
                               const std::string& creditCard) {
        validateRegistrationParams(username, firstName, lastName, age, creditCard);

        if (count == capacity) {
            expandCapacity();
        }

        std::string customerId = generateCustomerId();
        
        customers[count] = new Customer(username, firstName, lastName,
                                      age, creditCard, customerId);
        count++;
        
        return customerId;
    }

    /**
     * Updates a customer's reward points
     * @param customerId The customer's unique ID
     * @param points The new reward points value
     * @throws ValidationError if points are negative or customer not found
     */
    void updateRewardPoints(const std::string& customerId, double points) {
        if (points < 0) {
            throw ValidationError("Reward points must be positive");
        }
        else {
            bool found = false;
            
            for (int i = 0; i < count && !found; i++) {
                if (customers[i]->getId() == customerId) {
                    customers[i]->setRewardPoints(points);
                    found = true;
                }
            }
            
            if (!found) {
                throw ValidationError("Customer not found");
            }
        }
    }

    /**
     * Retrieves a customer by their ID
     * @param customerId The customer's unique ID
     * @return Pointer to the customer or nullptr if not found
     */
    const Customer* getCustomer(const std::string& customerId) const {
        for (int i = 0; i < count; i++) {
            if (customers[i]->getId() == customerId) {
                return customers[i];
            }
        }
        return nullptr;
    }

    /**
     * Removes a customer from the registry
     * @param customerId The customer's unique ID
     * @throws ValidationError if customer not found
     */
    void removeCustomer(const std::string& customerId) {
        bool found = false;
        
        for (int i = 0; i < count && !found; i++) {
            if (customers[i]->getId() == customerId) {
                delete customers[i];
                
                for (int j = i; j < count - 1; j++) {
                    customers[j] = customers[j + 1];
                }
                
                count--;
                found = true;
            }
        }
        
        if (!found) {
            throw ValidationError("Customer not found");
        }
    }
};