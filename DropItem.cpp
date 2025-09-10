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
	std::cout << this->name << "��(��) ��������� �ƹ� �ϵ� �Ͼ�� �ʾҽ��ϴ�!\n";
}
