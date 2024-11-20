// Dyar Jankir, Caden Dye, Arthas Lee
#include "Product.h"
#include <regex>
#include <iostream>
#include <stdexcept>

// Initialize static variable for storing used product IDs
std::vector<std::string> Product::productIDs = {};

/**
 * @brief Constructor for the Product class with validation checks and unique ID enforcement.
 * 
 * @param productID The unique identifier for the product. Must be a valid, non-empty string.
 * @param productName The name of the product. Must be a non-empty string.
 * @param productPrice The price of the product. Must be a valid double greater than or equal to 0.
 * @param productInventory The inventory count of the product. Must be a valid integer greater than or equal to 0.
 * 
 * @throws std::invalid_argument If any of the validation checks fail for the parameters or if the product ID is not unique.
 */
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

/**
 * @brief Retrieves the unique identifier for the product.
 * 
 * @return std::string The unique identifier of the product.
 */
std::string Product::getProductID() const { return productID; }

/**
 * @brief Retrieves the name of the product.
 * 
 * @return std::string The name of the product.
 */
std::string Product::getProductName() const { return productName; }

/**
 * @brief Retrieves the price of the product.
 * 
 * @return double The price of the product.
 */
double Product::getProductPrice() const { return productPrice; }

/**
 * @brief Retrieves the inventory count of the product.
 * 
 * @return int The inventory count of the product.
 */
int Product::getProductInventory() const { return productInventory; }


/**
 * @brief Updates the inventory count for the product by adding or removing items.
 * 
 * @param change The number of items to add to (positive value) or remove from (negative value) the inventory.
 *               If the change results in a negative inventory, the inventory is set to 0.
 */
void Product::updateInventory(int change) {
    productInventory += change;
    if (productInventory < 0) {
        productInventory = 0;  // Prevent negative inventory
    }
}


/**
 * @brief Validates the product's unique identifier.
 * 
 * @param productID The unique identifier for the product. The identifier must start with "Prod" followed by exactly five digits.
 * @return bool Returns true if the product ID is valid, otherwise false.
 */
bool Product::isProductIDValid(const std::string& productID) {
    return std::regex_match(productID, std::regex("^Prod\\d{5}$"));
}


/**
 * @brief Validates the product's price.
 * 
 * @param productPrice The price of the product. Must be a positive number.
 * @return bool Returns true if the product price is valid (greater than 0), otherwise false.
 */
bool Product::isProductPriceValid(double productPrice) {
    return productPrice > 0;
}


/**
 * @brief Validates the product's inventory count.
 * 
 * @param productInventory The inventory count of the product. Must be a non-negative integer.
 * @return bool Returns true if the product inventory is valid (greater than or equal to 0), otherwise false.
 */
bool Product::isProductInventoryValid(int productInventory) {
    return productInventory >= 0;
}

