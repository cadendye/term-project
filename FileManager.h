#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Customer.h"
#include "Product.h"

class FileManager {
public:
    static void logTransaction(const std::string& transaction);

    static void saveCustomers(const std::vector<Customer>& customers, const std::string& filename = "customers.txt");
    static std::vector<Customer> loadCustomers(const std::string& filename = "customers.txt");

    static void saveProducts(const std::vector<Product>& products, const std::string& filename = "products.txt");
    static std::vector<Product> loadProducts(const std::string& filename = "products.txt");
};

#endif // FILEMANAGER_H