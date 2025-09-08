#include "Character.h"
#include <iostream>
//#include <algorithm>

using namespace std;

Character::Character(const string& inputName) : name(inputName), level(1), maxHealth(200), health(maxHealth), attack(30), experience(0), gold(0) {}
// 캐릭터 생성자 효율성을 위해 초기화 리스트로 변경하고 string 객체는 상수타입과 참조로 받는거로 변경

Character::itemCount::itemCount(shared_ptr<Item> inputItem, int inputCount, int inputPrice) : item(inputItem), count(inputCount), price(inputPrice) {}
// 아이템 초기화 리스트

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

void Character::visitShop() {
	// 임시 Shop 클래스명 변경시 수정 필요
	//Shop shop;
	//shop.shopOpen();
} // 상점 방문

void Character::addItem(shared_ptr<Item> inputItem) { // 임시 Item 클래스명 변경시 수정 필요
	if (inventory.empty()) {
		inventory.emplace_back(inputItem, 1); // emplace_back 으로 객체 생성하여 삽입
		cout << "[" << inputItem->getName() << "] 가 새롭게 추가되었습니다." << endl;
		cout << "[" << inputItem->getName() << "] 의 현재 개수: 1개" << endl;
		return;
	} // 처음 아이템 추가시 비어있으면 중복 체크없이 바로 추가
	for (auto& invItem : inventory) {
		if (invItem.item->getName() == inputItem->getName()) {
			invItem.count++;
			cout << "아이템 추가 -> [" << invItem.item->getName() << "] 현재 개수: " << invItem.count << "개" << endl;
			return;
		}
	} // 중복 아이템 체크후 있을 경우 count 증가
	inventory.emplace_back(inputItem, 1);
	cout << "[" << inputItem->getName() << "] 가 새롭게 추가되었습니다." << endl;
	cout << "[" << inputItem->getName() << "] 의 현재 개수: 1개" << endl;
	// 중복되는 아이템 없을 경우 추가
} // 아이템 추가

void Character::removeItem(shared_ptr<Item> inputItem) {
	if (inventory.empty()) {
		cout << "인벤토리가 비어있습니다." << endl;
		return;
	} // 예외 처리
	for (auto it = inventory.begin(); it != inventory.end(); it++) {
		if (it->item->getName() == inputItem->getName()) {
			it->count--;
			cout << "아이템 감소 -> [" << it->item->getName() << "] 현재 개수: " << it->count << "개" << endl;
			if (it->count <= 0) {
				cout << "[" << it->item->getName() << "] 해당 아이템을 전부 사용하였습니다." << endl;
				inventory.erase(it);
			}
			return;
		}
	}// 중복 아이템 체크후 있을 경우 count 감소
	cout << "해당 아이템이 인벤토리에 없습니다." << endl; // 예외 처리
} // 아이템 제거

bool Character::isDead() const {
	return health <= 0;
} // 캐릭터 생사여부 판단 함수 필요시 부활조건 등을 추가해서 확장 가능

// getter
const string& Character::getName() const {
	return name;
}

int Character::getLevel() const {
	return level;
}

int Character::getHealth() const {
	return health;
}

int Character::getAttack() const {
	return attack;
}

int Character::getExperience() const {
	return experience;
}

int Character::getGold() const {
	return gold;
}

// setter
void Character::setHealth(int inputHealth) {
	health = inputHealth;
}

void Character::setAttack(int inputAttack) {
	attack = inputAttack;
}

void Character::setExperience(int inputExperience) {
	experience = inputExperience;
}

void Character::setGold(int inputGold) {
	gold = inputGold;
}

