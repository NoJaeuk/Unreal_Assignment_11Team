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
	std::cout << "���ݷ� " << boostpower << "��!\n";
	character->setAttack(character->getAttack() + boostpower);
}