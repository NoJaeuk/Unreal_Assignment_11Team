#pragma once
#include "Item.h"
#include "Character.h"
#include <string>

class AttackBoost : public Item
{
public:
	AttackBoost(std::string name, int price, int boostpower);
	std::string getName() override;
	int getPrice() override;
	void use(Character* character) override;

private:
	std::string name;
	int boostpower;
	int price;
};