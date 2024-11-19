#ifndef GIFT_H
#define GIFT_H

#include <string>

class Gift {
private:
    std::string giftName;
    int requiredPoints;

public:
    Gift(const std::string& giftName, int requiredPoints)
        : giftName(giftName), requiredPoints(requiredPoints) {}

    std::string getGiftName() const { return giftName; }
    int getRequiredPoints() const { return requiredPoints; }
};

#endif
