#pragma once
#include "Item.h"
#include "Character.h"
#include <string>

class HealthPotion : public Item
{
public:
	HealthPotion(std::string name, int price, int healthpower);
	std::string getName() override;
	int getPrice() override;
	void use(Character* character) override;

private:
	std::string name;
	int healthRestore;
	int price;
};

