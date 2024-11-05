# High Level Overview of all Functions that should be implemented

## 1. main.cpp (Main Program and Menu System)
void displayMenu(): Displays the menu options to the user. <br>
void handleMenuSelection(int choice): Calls the appropriate function based on user input. <br>
void loadData(): Loads customers, products, and transactions from files. <br>
void saveData(): Saves all data to files before exiting. <br>

## 2. Customer.cpp and Customer.h (Customer Management)
Customer registerCustomer(string username, string firstName, string lastName, int age, string creditCard): Registers a new customer and validates inputs. <br>
bool validateUsername(string username): Ensures the username meets requirements and is unique. <br>
bool validateName(string name): Checks that the name has no special characters and fits length requirements. <br>
bool validateAge(int age): Confirms age is within the required range. <br>
bool validateCreditCard(string creditCard): Checks format and uniqueness of credit card numbers. <br>
Customer getCustomerByID(string customerID): Retrieves a customer’s details by ID. <br>
void removeCustomer(string customerID): Removes a customer from the system. <br>
void saveToFile(): Saves all customer data to customers.txt. <br>
void loadFromFile(): Loads customer data from customers.txt. <br>

## 3. Product.cpp and Product.h (Product Management) 
Product addProduct(string name, double price, int quantity): Adds a new product with validations. <br>
bool validateProductID(string productID): Checks product ID format and uniqueness. <br>
void removeProduct(string productID): Removes a product from inventory. <br>
Product getProductByID(string productID): Retrieves product details by ID. <br>
void saveToFile(): Saves product data to products.txt. <br>
void loadFromFile(): Loads product data from products.txt. <br>

## 4. RewardSystem.cpp and RewardSystem.h (Reward Management)
void setRewardPoints(int points, double amount): Sets the number of reward points earned per shopping amount. <br>
void addRewardItem(string rewardID, string description, int requiredPoints): Adds a reward item that can be redeemed. <br>
bool redeemReward(string customerID, string rewardID): Allows a customer to redeem points for a reward. <br>
void saveToFile(): Saves reward settings to rewards.txt. <br>
void loadFromFile(): Loads reward settings from rewards.txt. <br>

## 5. Transaction.cpp and Transaction.h (Transaction Management)
void logTransaction(string customerID, vector<string> productIDs, double totalAmount, int rewardPoints): Logs a shopping transaction with products purchased. <br>
double calculateTotalAmount(vector<string> productIDs): Calculates the total cost of a transaction. <br>
int calculateRewardPoints(double amount): Determines the reward points based on the purchase amount.<br>
void saveToFile(): Saves transactions to transactions.txt. <br>
void loadFromFile(): Loads previous transactions from transactions.txt.
