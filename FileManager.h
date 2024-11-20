#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Customer.h"
#include "Product.h"

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


    static void logTransaction(const std::string& customerID, const std::vector<std::pair<std::string, int>>& cart, double totalCost, int rewardPoints);

    static void saveCustomers(const std::vector<Customer>& customers, const std::string& filename = "customers.txt");
    static std::vector<Customer> loadCustomers(const std::string& filename = "customers.txt");

    static void saveProducts(const std::vector<Product>& products, const std::string& filename = "products.txt");
    static std::vector<Product> loadProducts(const std::string& filename = "products.txt");
};

#endif // FILEMANAGER_H