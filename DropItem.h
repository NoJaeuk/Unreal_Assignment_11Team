#pragma once
#include <string>
#include "Item.h"

class DropItem : public Item
{
public:
	DropItem(std::string name, int price);

	std::string getName() override;
	int getPrice() override;
	void use(Character* character) override;


private:
	std::string name;
	int price;
};

