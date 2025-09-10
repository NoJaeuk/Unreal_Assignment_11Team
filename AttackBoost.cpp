#include "AttackBoost.h"
#include "Character.h"
#include <iostream>


AttackBoost::AttackBoost(std::string name, int price, int boostpower) {
	this->name = name;
	this->price = price;
	this->boostpower = boostpower;
}

std::string AttackBoost::getName() {
	return name;
}

int AttackBoost::getPrice() {
	return price;
}

void AttackBoost::use(Character* character) {
	std::cout << "공격력 " << boostpower << "업!\n";
	character->setAttack(character->getAttack() + boostpower);
}