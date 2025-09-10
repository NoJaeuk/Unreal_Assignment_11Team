#include "HealthPotion.h"
#include "Character.h"
#include <iostream>


HealthPotion::HealthPotion(std::string name, int price, int healthpower) {
	this->name = name;
	this->price = price;
	this->healthRestore = healthpower;
}

std::string HealthPotion::getName() {
	return name;
}

int HealthPotion::getPrice() {
	return price;
}

void HealthPotion::use(Character* character) {
	std::cout << "HP 20 È¸º¹!!";
	character->setHealth(character->getHealth()+healthRestore);
}