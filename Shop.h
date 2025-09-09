#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Item.h"
#include "Character.h"

class Shop
{
private:

    struct ShopItem
    {
        std::shared_ptr<Item> item_; //아이템 타입 포인터 만듬, 게임매니저에서 받아오는용도
        int count_;//그 아이템이 몇개인지
    };

    std::vector<ShopItem> availableItems_; //아이템과 갯수를 합쳐서 관리할 수 있는 벡터

public:

    Shop(){}
    ~Shop(){}

    void addItem(std::shared_ptr<Item> item, int count);
   
    void displayItems();

    void buyItem(const std::string& name, Character* character);

    void sellItem(const std::string& name, Character* character);

    void randomPick(Character* character);

};