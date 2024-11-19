// Dyar Jankir, Caden Dye, Arthas Lee
#include "Customer.h"
#include "Product.h"
#include "Gift.h"
#include "FileManager.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <random>
#include <set> // For tracking used IDs

// Function to display the main menu and return the selected option
int displayMenu() {
    int choice;
    std::cout << "\n--- Customer Reward System Menu ---\n";
    std::cout << "1. Customer Registration\n";
    std::cout << "2. Customer Removal\n";
    std::cout << "3. Product Addition\n";
    std::cout << "4. Product Removal\n";
    std::cout << "5. Shopping\n";
    std::cout << "6. View Customer by Customer ID\n";
    std::cout << "7. Redeem Rewards\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
    std::cin >> choice;

    // Check for valid integer input
    if (std::cin.fail()) {
        std::cin.clear();  // clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard invalid input
        return -1;  // return an invalid option if the input is not an integer
    }

    return choice;
}

void registerCustomer(std::vector<Customer>& customers, std::set<std::string>& usedIDs) {
    std::string userName, firstName, lastName, creditCardNumber;
    int age, rewardPoints = 0;

    std::cout << "Enter username (format: 'U' followed by 3 numbers, then 6+ characters): ";
    std::cin >> userName;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter age (18-100): ";
    std::cin >> age;
    std::cout << "Enter credit card number (format: xxxx-xxxx-xxxx): ";
    std::cin >> creditCardNumber;

    // Generate unique Customer ID
    std::string customerID;
    do {
        std::random_device rd; // Seed generator
        std::mt19937 gen(rd()); // Random number generator
        std::uniform_int_distribution<> dist(1000000000, 9999999999); // 10-digit numbers
        customerID = "CustID" + std::to_string(dist(gen)); // Generate ID
    } while (usedIDs.find(customerID) != usedIDs.end()); // Ensure uniqueness

    usedIDs.insert(customerID); // Mark ID as used

    try {
        Customer newCustomer(customerID, userName, firstName, lastName, age, creditCardNumber, rewardPoints);
        std::cout << "Customer registered successfully.\n";
        customers.push_back(newCustomer);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
// Function to remove a customer by customerID
void removeCustomer(std::vector<Customer>& customers) {
    std::string customerID;
    bool found = false;

    std::cout << "Enter the Customer ID to remove: ";
    std::cin >> customerID;

    // Search for the customer by customerID
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->getCustomerID() == customerID) {
            customers.erase(it);  // Remove the customer
            std::cout << "Customer removed successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Customer with ID " << customerID << " not found.\n";
    }
}

// Function to remove a product by productID
void removeProduct(std::vector<Product>& products) {
    std::string productID;
    bool found = false;

    std::cout << "Enter the Product ID to remove: ";
    std::cin >> productID;

    // Search for the product by productID
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getProductID() == productID) {
            products.erase(it);  // Remove the product
            std::cout << "Product removed successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Product with ID " << productID << " not found.\n";
    }
}

// Function to add a new product to the inventory
void addProduct(std::vector<Product>& products) {  // Pass the vector by reference
    std::string productID, productName;
    double productPrice;
    int productInventory;

    // Input Product ID
    std::cout << "Enter Product ID (format 'Prod' followed by 5 digits): ";
    std::cin >> productID;

    // Input Product Name
    std::cout << "Enter Product Name: ";
    std::cin.ignore();  // To clear the input buffer
    std::getline(std::cin, productName);

    // Input Product Price
    std::cout << "Enter Product Price: ";
    std::cin >> productPrice;

    // Input Product Inventory
    std::cout << "Enter Product Inventory: ";
    std::cin >> productInventory;

    try {
        // Create a Product object, which validates inputs through its constructor
        Product newProduct(productID, productName, productPrice, productInventory);

        // Add the product to the product list
        products.push_back(newProduct);

        std::cout << "Product added successfully.\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void viewCustomerByID(const std::vector<Customer>& customers) {
    std::string customerID;
    std::cout << "Enter Customer ID: ";
    std::cin >> customerID;

    // Search for the customer in the vector
    bool found = false;
    for (const auto& customer : customers) {
        if (customer.getCustomerID() == customerID) {
            std::cout << "\n--- Customer Details ---\n";
            std::cout << "Customer ID: " << customer.getCustomerID() << "\n";
            std::cout << "Username: " << customer.getUserName() << "\n";
            std::cout << "First Name: " << customer.getFirstName() << "\n";
            std::cout << "Last Name: " << customer.getLastName() << "\n";
            std::cout << "Age: " << customer.getAge() << "\n";
            std::cout << "Credit Card Number: " << customer.getCreditCardNumber() << "\n";
            std::cout << "Reward Points: " << customer.getRewardPoints() << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Customer ID not found.\n";
    }
}

void setPointsPerDollar(int& pointsPerDollar) {
    std::cout << "Enter the number of points awarded per dollar spent: ";
    std::cin >> pointsPerDollar;
    std::cout << "Points per dollar updated to: " << pointsPerDollar << "\n";
}

void addGift(std::vector<Gift>& gifts) {
    std::string giftName;
    int requiredPoints;

    std::cout << "Enter gift name: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, giftName);

    std::cout << "Enter points required to redeem this gift: ";
    std::cin >> requiredPoints;

    gifts.emplace_back(giftName, requiredPoints);
    std::cout << "Gift added: " << giftName << " (requires " << requiredPoints << " points).\n";
}

void redeemReward(std::vector<Customer>& customers, std::vector<Gift>& gifts) {
    std::string customerID;
    std::cout << "Enter Customer ID: ";
    std::cin >> customerID;

    // Find the customer
    auto it = std::find_if(customers.begin(), customers.end(), [&](const Customer& c) {
        return c.getCustomerID() == customerID;
    });

    if (it == customers.end()) {
        std::cout << "Customer ID not found.\n";
        return;
    }

    Customer& customer = *it;

    // Display available gifts
    if (gifts.empty()) {
        std::cout << "No gifts available for redemption.\n";
        return;
    }

    std::cout << "\n--- Available Gifts ---\n";
    for (size_t i = 0; i < gifts.size(); ++i) {
        std::cout << i + 1 << ". " << gifts[i].getGiftName()
                  << " (requires " << gifts[i].getRequiredPoints() << " points)\n";
    }

    // Display customer's points
    std::cout << "\nYou have " << customer.getRewardPoints() << " reward points.\n";

    // Select a gift
    int choice;
    std::cout << "Enter the number of the gift to redeem (0 to cancel): ";
    std::cin >> choice;

    if (choice == 0) {
        std::cout << "Redemption canceled.\n";
        return;
    }

    if (choice < 1 || choice > static_cast<int>(gifts.size())) {
        std::cout << "Invalid choice.\n";
        return;
    }

    const Gift& selectedGift = gifts[choice - 1];
    if (customer.getRewardPoints() >= selectedGift.getRequiredPoints()) {
        customer.addRewardPoints(-selectedGift.getRequiredPoints());
        std::cout << "Successfully redeemed: " << selectedGift.getGiftName() << "\n";
        std::cout << "Remaining points: " << customer.getRewardPoints() << "\n";
    } else {
        std::cout << "Insufficient reward points to redeem this gift.\n";
    }
}

/**
 * "Shopping functionality in menu system"
 * 
 * @param customers References registered customers.
 * @param products References available products.
 * @param pointsPerDollar The number of reward points earned per dollar spent.
 * @throws std::runtime_error if file operations fail.
 */
void shopping(std::vector<Customer>& customers, std::vector<Product>& products, double pointsPerDollar) {
    std::string customerID;
    std::cout << "Enter Customer ID: ";
    std::cin >> customerID;

    // Find customer
    auto customerIt = std::find_if(customers.begin(), customers.end(),
                                   [&customerID](const Customer& c) { return c.getCustomerID() == customerID; });
    if (customerIt == customers.end()) {
        std::cout << "Customer not found.\n";
        return;
    }

    std::vector<std::pair<std::string, int>> cart;
    double totalCost = 0.0;

    while (true) {
        // Display products
        std::cout << "\nAvailable Products:\n";
        for (const auto& product : products) {
            std::cout << product.getProductID() << " - " << product.getProductName()
                      << " ($" << product.getProductPrice()
                      << "), Available: " << product.getProductInventory() << "\n";
        }

        // Select product
        std::string productID;
        int quantity;
        std::cout << "Enter Product ID to purchase (or 'done' to finish): ";
        std::cin >> productID;

        if (productID == "done") break;

        auto productIt = std::find_if(products.begin(), products.end(),
                                      [&productID](const Product& p) { return p.getProductID() == productID; });

        if (productIt == products.end()) {
            std::cout << "Invalid Product ID. Try again.\n";
            continue;
        }

        // Validate quantity
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        if (quantity <= 0 || quantity > productIt->getProductInventory()) {
            std::cout << "Invalid quantity.\n";
            continue;
        }

        // Update cart and inventory
        cart.emplace_back(productID, quantity);
        totalCost += quantity * productIt->getProductPrice();
        productIt->updateInventory(-quantity);
    }

    if (cart.empty()) {
        std::cout << "No products selected.\n";
        return;
    }

    // Calculate reward points using pointsPerDollar
    int rewardPoints = static_cast<int>(totalCost * pointsPerDollar); // Reward points based on pointsPerDollar
    customerIt->addRewardPoints(rewardPoints);

    // Log transaction
    FileManager::logTransaction(customerID, cart, totalCost, rewardPoints);

    std::cout << "Purchase complete. Total: $" << totalCost
              << ", Earned Rewards: " << rewardPoints << "\n";
}

// Function to add dummy customers and products for testing purposes
int main() {
    int choice;
    std::vector<Customer> customers;  // Create vector to store all customers
    std::vector<Product> products;    // Create vector to store all products

    int pointsPerDollar = 10; // Default points per dollar
    std::vector<Gift> gifts; // Empty vector of gifts

    std::set<std::string> usedIDs; 

    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                registerCustomer(customers, usedIDs);
                break;
            case 2:
                removeCustomer(customers);
                break;
            case 3:
                addProduct(products);  // Call the function to add a product
                break;
            case 4:
                removeProduct(products);  // Pass the products vector to remove a product
                break;
            case 5:
                shopping(customers, products, pointsPerDollar);
                FileManager::saveCustomers(customers); // Persist updated customers
                FileManager::saveProducts(products);   // Persist updated products
            case 6:
                viewCustomerByID(customers);
                break;
            case 7: {
                int subChoice;
                std::cout << "\n--- Redeem Rewards Menu ---\n";
                std::cout << "1. Set Points per Dollar\n";
                std::cout << "2. Add Gift\n";
                std::cout << "3. Redeem Reward\n";
                std::cout << "0. Back to Main Menu\n";
                std::cout << "Select an option: ";
                std::cin >> subChoice;

                switch (subChoice) {
                    case 1:
                        setPointsPerDollar(pointsPerDollar);
                        break;
                    case 2:
                        addGift(gifts);
                        break;
                    case 3:
                        redeemReward(customers, gifts);
                        break;
                    case 0:
                        break;
                    default:
                        std::cout << "Invalid option. Please try again.\n";
                }
                break;
            }
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
