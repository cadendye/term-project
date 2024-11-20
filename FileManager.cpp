#include "FileManager.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

void FileManager::logTransaction(const std::string& customerID,
                                 const std::vector<std::pair<std::string, int>>& cart,
                                 double totalCost,
                                 int rewardPoints) {
    std::ofstream logFile("transactions.txt", std::ios::app); // Open file in append mode
    if (logFile.is_open()) {
        logFile << "Customer ID: " << customerID << "\n";
        logFile << "Items Purchased:\n";
        for (const auto& [productID, quantity] : cart) {
            logFile << "  - Product ID: " << productID << ", Quantity: " << quantity << "\n";
        }
        logFile << "Total Cost: $" << totalCost << "\n";
        logFile << "Reward Points Earned: " << rewardPoints << "\n\n";
        logFile.close();
    } else {
        std::cerr << "Error: Unable to open transactions.txt for writing." << std::endl;
    }
}

void FileManager::saveTransactions(const std::vector<Transaction>& transactions, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Cannot open file for saving transactions.");


    for (const auto& transaction : transactions) {
        file << transaction.getTransactionID() << "\n"
             << transaction.getCustomerID() << "\n"
             << transaction.getProductIDs() << "\n"
             << transaction.getTotalAmount() << "\n"
             << transaction.getRewardPoints() << "\n\n";
    }
    file.close();
}

std::vector<Transaction> FileManager::loadTransactions(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open transactions.txt for loading.");
    }

    std::vector<Transaction> transactions;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        // Read transaction fields
        std::string transactionID = line;
        std::getline(file, line);
        std::string customerID = line;
        std::getline(file, line);
        std::string productIDs = line;
        std::getline(file, line);
        double totalAmount = std::stod(line);
        std::getline(file, line);
        int rewardPoints = std::stoi(line);

        // Create a Transaction object and add it to the vector
        transactions.emplace_back(transactionID, customerID, productIDs, totalAmount, rewardPoints);

        // Skip the blank line between transactions
        std::getline(file, line);
    }

    file.close();
    return transactions;
}

// Save customers to file
void FileManager::saveCustomers(const std::vector<Customer>& customers, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for saving customers.");
    }
    for (const auto& customer : customers) {
        file << customer.getCustomerID() << "\n"
             << customer.getUserName() << "\n"
             << customer.getFirstName() << "\n"
             << customer.getLastName() << "\n"
             << customer.getAge() << "\n"
             << customer.getCreditCardNumber() << "\n"
             << customer.getRewardPoints() << "\n\n";
    }
}

// Load customers from file
std::vector<Customer> FileManager::loadCustomers(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for loading customers.");
    }

    std::vector<Customer> customers;
    std::string customerID, userName, firstName, lastName, ageStr, creditCardNumber, rewardPointsStr;

    while (std::getline(file, customerID)) {
        std::getline(file, userName);
        std::getline(file, firstName);
        std::getline(file, lastName);
        std::getline(file, ageStr);
        std::getline(file, creditCardNumber);
        std::getline(file, rewardPointsStr);

        try {
            int age = std::stoi(ageStr);
            int rewardPoints = std::stoi(rewardPointsStr);

            // Construct the Customer object and add it to the vector
            customers.emplace_back(customerID, userName, firstName, lastName, age, creditCardNumber, rewardPoints);
        } catch (const std::invalid_argument& e) {
            throw std::runtime_error("Error parsing customer data: " + std::string(e.what()));
        }
    }
    return customers;
}

// Save products to file
void FileManager::saveProducts(const std::vector<Product>& products, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for saving products.");
    }
    for (const auto& product : products) {
        file << product.getProductID() << "\n"
             << product.getProductName() << "\n"
             << product.getProductPrice() << "\n"
             << product.getProductInventory() << "\n\n";
    }
}

// Load products from file
std::vector<Product> FileManager::loadProducts(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for loading products.");
    }

    std::vector<Product> products;
    std::string productID, productName, productPriceStr, productInventoryStr;

    while (std::getline(file, productID)) {
        std::getline(file, productName);
        std::getline(file, productPriceStr);
        std::getline(file, productInventoryStr);

        try {
            double productPrice = std::stod(productPriceStr);
            int productInventory = std::stoi(productInventoryStr);

            // Construct the Product object and add it to the vector
            products.emplace_back(productID, productName, productPrice, productInventory);
        } catch (const std::invalid_argument& e) {
            throw std::runtime_error("Error parsing product data: " + std::string(e.what()));
        }
    }
    return products;
}