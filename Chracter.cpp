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
} // 캐릭터 생성자

Character* Character::getInstance(string inputName) {
	if (instance == nullptr) {
		instance = new Character(inputName);
	}
	return instance;
} // 싱글톤 구현

void Character::displayStatus() {
	cout << "=====Status=====" << endl;
	cout << "이름: " << name << endl;
	cout << "레벨: " << level << endl;
	cout << "현재 체력: " << health << "/" << maxHealth << endl;
	cout << "공격력: " << attack << endl;
	cout << "경험치: " << experience << endl;
	cout << "소지금: " << gold << endl;
} // 상태창 보기

void Character::levelUp() {
	experience -= 100;
	if (level >= 10) {
		level = 10;
		return;
	} // 예외 처리
	level++;
	maxHealth = (maxHealth + (level * 20));
	attack = (attack + (level * 5));
	health = maxHealth;
} // 레벨업 함수

void Character::useItem(int index) {
	//미구현
} // 아이템 사용

void Character::visitShop() {
	Shop shop;
	shop.shopOpen();
} // 상점 방문

void Character::addItem(shared_ptr<Item> inputItem) {
	inventory.push_back(inputItem);
} // 아이템 추가

//getter
string Character::getName()
{
	return name;
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

//setter
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
