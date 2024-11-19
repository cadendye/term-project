// Dyar Jankir, Caden Dye, Arthas Lee
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Customer.h"
#include "Product.h"

/**
 * @class FileManager
 * @brief Provides file management functionalities for logging transactions and saving/loading customer and product data.
 */
class FileManager {
public:
    /**
     * @brief Logs a customer's transaction to a file.
     * 
     * @param customerID The unique identifier for the customer making the transaction.
     * @param cart A vector of pairs, where each pair contains a product ID and the quantity of that product purchased.
     * @param totalCost The total cost of the transaction.
     * @param rewardPoints The number of reward points earned from the transaction.
     */
    static void logTransaction(const std::string& customerID, const std::vector<std::pair<std::string, int>>& cart, double totalCost, int rewardPoints);

    /**
     * @brief Saves customer information to a file.
     * 
     * @param customers A vector of Customer objects to be saved.
     * @param filename The name of the file where customer information will be saved. Defaults to "customers.txt".
     * @throws std::runtime_error If the file cannot be opened for writing.
     */
    static void saveCustomers(const std::vector<Customer>& customers, const std::string& filename = "customers.txt");

    /**
     * @brief Loads customer information from a file.
     * 
     * @param filename The name of the file from which customer information will be loaded. Defaults to "customers.txt".
     * @return std::vector<Customer> A vector of Customer objects loaded from the file.
     * @throws std::runtime_error If the file cannot be opened for reading or if there is an error parsing customer data.
     */
    static std::vector<Customer> loadCustomers(const std::string& filename = "customers.txt");

    /**
     * @brief Saves product information to a file.
     * 
     * @param products A vector of Product objects to be saved.
     * @param filename The name of the file where product information will be saved. Defaults to "products.txt".
     * @throws std::runtime_error If the file cannot be opened for writing.
     */
    static void saveProducts(const std::vector<Product>& products, const std::string& filename = "products.txt");

    /**
     * @brief Loads product information from a file.
     * 
     * @param filename The name of the file from which product information will be loaded. Defaults to "products.txt".
     * @return std::vector<Product> A vector of Product objects loaded from the file.
     * @throws std::runtime_error If the file cannot be opened for reading or if there is an error parsing product data.
     */
    static std::vector<Product> loadProducts(const std::string& filename = "products.txt");
};

#endif // FILEMANAGER_H
