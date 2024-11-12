#include "Product.h"
#include <regex>
#include <iostream>
#include <stdexcept>

// Initialize static variable for storing used product IDs
std::vector<std::string> Product::productIDs = {};

// Constructor with validation checks
Product::Product(const std::string& productID, const std::string& productName, double productPrice, int productInventory)
    : productID(productID), productName(productName), productPrice(productPrice), productInventory(productInventory) {

    // Validate the inputs
    if (!isProductIDValid(productID) || !isProductPriceValid(productPrice) || !isProductInventoryValid(productInventory)) {
        throw std::invalid_argument("Invalid product data provided.");
    }

    // Check if the product ID is unique
    for (const auto& existingID : productIDs) {
        if (existingID == productID) {
            throw std::invalid_argument("Product ID must be unique.");
        }
    }
    
    // Add the product ID to the list of existing IDs
    productIDs.push_back(productID);
}

// Getters for the product details
std::string Product::getProductID() const { return productID; }
std::string Product::getProductName() const { return productName; }
double Product::getProductPrice() const { return productPrice; }
int Product::getProductInventory() const { return productInventory; }

// Update inventory (for adding or removing items)
void Product::updateInventory(int change) {
    productInventory += change;
    if (productInventory < 0) {
        productInventory = 0;  // Prevent negative inventory
    }
}

// Validation function for product ID
bool Product::isProductIDValid(const std::string& productID) {
    return std::regex_match(productID, std::regex("^Prod\\d{5}$"));
}

// Validation function for product price (positive number)
bool Product::isProductPriceValid(double productPrice) {
    return productPrice > 0;
}

// Validation function for product inventory (positive integer)
bool Product::isProductInventoryValid(int productInventory) {
    return productInventory >= 0;
}
