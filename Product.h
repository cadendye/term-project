#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

class Product {
public:
    // Constructor with validation checks
    Product(const std::string& productID, const std::string& productName, double productPrice, int productInventory);

    // Getters for the product details
    std::string getProductID() const;
    std::string getProductName() const;
    double getProductPrice() const;
    int getProductInventory() const;

    // Update inventory (for adding or removing items)
    void updateInventory(int change);

    // Validation function for product ID
    static bool isProductIDValid(const std::string& productID);
    
    // Validation function for product price (positive number)
    static bool isProductPriceValid(double productPrice);

    // Validation function for product inventory (positive integer)
    static bool isProductInventoryValid(int productInventory);

private:
    std::string productID;
    std::string productName;
    double productPrice;
    int productInventory;

    // Static list to track unique product IDs
    static std::vector<std::string> productIDs;
};

#endif // PRODUCT_H
