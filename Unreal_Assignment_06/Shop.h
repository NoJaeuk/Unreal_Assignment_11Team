#pragma once
#include<vector>
#include<memory>
#include<string>
#include "Item.h"

class Character;

class Shop
{
private:

	struct ShopItem
	{
		//메모리 누수 방지용 shared_ptr
		std::shared_ptr<Item> item;
		int count;
	};
	std::vector<ShopItem> availableItems_;

public:
	Shop() {}
	~Shop() {}

	void addItem(std::shared_ptr<Item> item, int count);
	void displayItems();
	void buyItem(const std::string& name, Character* character);
	void sellItem(const std::string& name, Character* character);

	void randomPick(Character* character);
};

