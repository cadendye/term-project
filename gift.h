// Dyar Jankir, Caden Dye, Arthas Lee
#ifndef GIFT_H
#define GIFT_H

#include <string>

/**
 * @class Gift
 * @brief Represents a gift that can be redeemed with reward points.
 */
class Gift {
private:
    std::string giftName;   ///< The name of the gift.
    int requiredPoints;     ///< The number of reward points required to redeem the gift.

public:
    /**
     * @brief Constructor for the Gift class.
     * @param giftName The name of the gift.
     * @param requiredPoints The number of reward points needed to redeem the gift.
     */
    Gift(const std::string& giftName, int requiredPoints)
        : giftName(giftName), requiredPoints(requiredPoints) {}

    /**
     * @brief Retrieves the name of the gift.
     * @return std::string The name of the gift.
     */
    std::string getGiftName() const { return giftName; }

    /**
     * @brief Retrieves the number of reward points required to redeem the gift.
     * @return int The number of required reward points.
     */
    int getRequiredPoints() const { return requiredPoints; }
};

#endif // GIFT_H
