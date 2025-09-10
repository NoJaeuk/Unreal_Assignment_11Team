#include <string>
#include <iostream>
#include "DropItem.h"

DropItem::DropItem(std::string name, int price) {
	this->name = name;
	this->price = price;
}

std::string DropItem::getName() {
	return name;
}

int DropItem::getPrice() {
	return price;
}

void DropItem::use(Character* character) {
	std::cout << this->name << "을(를) 사용했지만 아무 일도 일어나지 않았습니다!\n";
}
