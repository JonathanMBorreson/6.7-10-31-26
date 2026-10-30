#include "item.h"

// the default being 1 means that there's no discount until it's changed
double item::discountMultiplier = 1.0;

// this thing's the constructor
item::item(const std::string& name, double price)
    : itemName(name), originalPrice(price)
{
}

// this jawn sets the store-wide discount
// like if percent = 20 then discountMultiplier = 0.80
void item::setDiscount(double percent)
{
    discountMultiplier = 1.0 - (percent / 100.0);
}

// this thingy returns the item's name
std::string item::getName() const
{
    return itemName;
}

// THIS THINGY returns the item's first price
double item::getOPrice() const
{
    return originalPrice;
}

// this thingamabob returns the price after applying the discount
double item::getDiscPrice() const
{
    return originalPrice * discountMultiplier;
}