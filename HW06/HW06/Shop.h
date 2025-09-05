#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Item.h"
#include "Inventory.h"

class Shop
{
private:

    struct ShopItem
    {
        std::shared_ptr<Item> item;
        int count;
    };

    std::vector<ShopItem> availableItems;

public:

    Shop(){}
    ~Shop(){}

    void shopOpen() {};

    void addItem(Item* item) {};

    void displayItems() {};

    void buyItem() {};

    void sellItem(Character* player, std::string& name) {};

    void randomPick() {};

};