#include "Character.h"

using namespace std;

Character::Character(string inputName) {
	name = inputName;
	level = 1;
	maxHealth = 200;
	health = maxHealth;
	attack = 30;
	experience = 0;
	gold = 0;
}

Character* Character::getInstance(string inputName) {
	if (instance == nullptr) {
		instance = new Character(inputName);
	}
	return instance;
}

void Character::displayStatus() {
	cout << "=====Status=====" << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << level << endl;
	cout << "���� ü��: " << health << "/" << maxHealth << endl;
	cout << "���ݷ�: " << attack << endl;
	cout << "����ġ: " << experience << endl;
	cout << "������: " << gold << endl;
}

void Character::levelUp() {
	experience -= 100;
	if (level >= 10) {
		level = 10;
		return;
	} // ���� ó��
	level++;
	maxHealth = (maxHealth + (level * 20));
	attack = (attack + (level * 5));
	health = maxHealth;
}

void Character::useItem(int index) {
	//�̱���
}

void Character::visitShop() {
	Shop shop;
	shop.shopOpen();
}

void Character::addItem(shared_ptr<Item> inputItem) {
	inventory.push_back(inputItem);
}

int Character::getLevel() {
	return level;
}

int Character::getHealth() {
	return health;
}

int Character::getAttack() {
	return attack;
}

int Character::getExperience() {
	return experience;
}

int Character::getGold() {
	return gold;
}

void Character::setHealth(int inputHealth) {
	health += inputHealth;
}

void Character::setAttack(int inputAttack) {
	attack += inputAttack;
}

void Character::setExperience(int inputExperience) {
	experience += inputExperience;
}

void Character::setGold(int inputGold) {
	gold += inputGold;
}
