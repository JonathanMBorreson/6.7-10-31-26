using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include "../class file for 6.7.h"

void addItemsToList(vector<item>& inventory)
{
    int itemcount;
    cout << "how many items would you like to add?";
    cin >> itemcount;
    for (int i = 0; i < itemcount; i++)
    {
        string name;
        double price;

        cout << "Enter name of item " << i + 1 << ": ";
        cin >> name;   // use getline if names can contain spaces
        cout << "Enter original price of " << name << ": ";
        cin >> price;

        inventory.push_back(item(name, price));
    }


}

// prints the name, original price, and discounted price of every item
void printInventory(const vector<item>& inventory)
{
    cout << fixed;
    cout.precision(2);   // show prices like 25.00

    for (const item& i : inventory)
    {
        cout << i.getName()
             << " | Original: $" << i.getOPrice()
             << " | Discounted: $" << i.getDiscPrice() << "\n";
    }
}

// the default being 1 means that there's no discount until it's changed
double item::discountMultiplier = 1.0;

// constructor
item::item(const std::string& name, double price)
    : itemName(name), originalPrice(price)
{
}

// sets the store-wide discount
// like if percent = 20 then discountMultiplier = 0.80
void item::setDiscount(double percent)
{
    discountMultiplier = 1.0 - (percent / 100.0);
}

// returns the item's name
std::string item::getName() const
{
    return itemName;
}

// returns the item's original price
double item::getOPrice() const
{
    return originalPrice;
}

// returns the price after applying the discount
double item::getDiscPrice() const
{
    return originalPrice * discountMultiplier;
}

int main()
{
    vector<item> inventory;
    addItemsToList(inventory);

    item::setDiscount(20);

    printInventory(inventory);
}