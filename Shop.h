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
        std::shared_ptr<Item> item_; //������ Ÿ�� ������ ����, ���ӸŴ������� �޾ƿ��¿뵵
        int count_;//�� �������� �����
    };

    std::vector<ShopItem> availableItems_; //�����۰� ������ ���ļ� ������ �� �ִ� ����

public:

    Shop(){}
    ~Shop(){}

    void addItem(std::shared_ptr<Item> item, int count);
   
    void displayItems();

    void buyItem(const std::string& name, Character* character);

    void sellItem(const std::string& name, Character* character);

    void randomPick(Character* character);

};