// Dyar Jankir, Caden Dye, Arthas Lee
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

/**
 * @class Product
 * @brief Represents a product with relevant details and validation functions.
 */
class Product {
public:
    /**
     * @brief Constructor for the Product class with validation checks.
     * @param productID The unique identifier for the product. Must be a valid, non-empty string.
     * @param productName The name of the product. Must be a non-empty string.
     * @param productPrice The price of the product. Must be a valid double greater than 0.
     * @param productInventory The inventory count of the product. Must be a valid integer greater than or equal to 0.
     * @throws std::invalid_argument If any validation checks fail or if the product ID is not unique.
     */
    Product(const std::string& productID, const std::string& productName, double productPrice, int productInventory);

    /**
     * @brief Retrieves the unique identifier for the product.
     * @return std::string The unique identifier of the product.
     */
    std::string getProductID() const;

    /**
     * @brief Retrieves the name of the product.
     * @return std::string The name of the product.
     */
    std::string getProductName() const;

    /**
     * @brief Retrieves the price of the product.
     * @return double The price of the product.
     */
    double getProductPrice() const;

    /**
     * @brief Retrieves the inventory count of the product.
     * @return int The inventory count of the product.
     */
    int getProductInventory() const;

    /**
     * @brief Updates the inventory count for the product by adding or removing items.
     * @param change The number of items to add to (positive value) or remove from (negative value) the inventory.
     *               If the change results in a negative inventory, the inventory is set to 0.
     */
    void updateInventory(int change);

    /**
     * @brief Validates the product's unique identifier.
     * @param productID The unique identifier for the product. The identifier must start with "Prod" followed by exactly five digits.
     * @return bool Returns true if the product ID is valid, otherwise false.
     */
    static bool isProductIDValid(const std::string& productID);
    
    /**
     * @brief Validates the product's price.
     * @param productPrice The price of the product. Must be a positive number.
     * @return bool Returns true if the product price is valid (greater than 0), otherwise false.
     */
    static bool isProductPriceValid(double productPrice);

    /**
     * @brief Validates the product's inventory count.
     * @param productInventory The inventory count of the product. Must be a non-negative integer.
     * @return bool Returns true if the product inventory is valid, otherwise false.
     */
    static bool isProductInventoryValid(int productInventory);

private:
    std::string productID;            ///< The unique identifier for the product.
    std::string productName;          ///< The name of the product.
    double productPrice;              ///< The price of the product.
    int productInventory;             ///< The inventory count of the product.

    /**
     * @brief Static list to track unique product IDs.
     */
    static std::vector<std::string> productIDs;
};

#endif // PRODUCT_H
