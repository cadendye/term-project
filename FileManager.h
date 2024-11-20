// Dyar Jankir, Caden Dye, Arthas Lee
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Customer.h"
#include "Product.h"

<<<<<<< HEAD
struct Transaction {
    std::string transactionID;
    std::string customerID;
    std::string productIDs;  // Comma-separated string of product IDs
    double totalAmount;
    int rewardPoints;

    Transaction(const std::string& id, const std::string& custID, const std::string& products, 
                double total, int points)
        : transactionID(id), customerID(custID), productIDs(products), 
          totalAmount(total), rewardPoints(points) {}

    // Getters
    std::string getTransactionID() const { return transactionID; }
    std::string getCustomerID() const { return customerID; }
    std::string getProductIDs() const { return productIDs; }
    double getTotalAmount() const { return totalAmount; }
    int getRewardPoints() const { return rewardPoints; }

    // Setters
    void setTransactionID(const std::string& id) { transactionID = id; }
    void setCustomerID(const std::string& custID) { customerID = custID; }
    void setProductIDs(const std::string& products) { productIDs = products; }
    void setTotalAmount(double total) { totalAmount = total; }
    void setRewardPoints(int points) { rewardPoints = points; }
};

class FileManager {
public:
    static void saveTransactions(const std::vector<Transaction>& transactions, const std::string& filename = "transactions.txt");
    static std::vector<Transaction> loadTransactions(const std::string& filename = "transactions.txt");


=======
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
>>>>>>> 35eed9c0d663255ecc1dce6e9048faace03fc9d7
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
