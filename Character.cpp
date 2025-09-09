#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(const string& inputName) : name(inputName), level(1), maxHealth(200), health(maxHealth), attack(30), exp(0), gold(0) {}
Character::~Character() {
	//cout << "Character 객체 소멸자 호출" << endl; // 디버깅용 메세지
}
// 캐릭터 생성자 효율성을 위해 초기화 리스트로 변경하고 string 객체는 상수타입과 참조로 받는거로 변경

Character::itemCount::itemCount(shared_ptr<Item> inputItem, int inputCount) : item(inputItem), count(inputCount) {}
// 아이템 초기화 리스트

Character& Character::getInstance(string inputName) {
	static Character instance(inputName);
	return instance;
} // 싱글톤 구현

void Character::displayStatus() {
	cout << "=====Status=====" << endl;
	cout << "이름: " << name << endl;
	cout << "레벨: " << level << endl;
	cout << "현재 체력: " << health << "/" << maxHealth << endl;
	cout << "공격력: " << attack << endl;
	cout << "경험치: " << exp << endl;
	cout << "소지금: " << gold << endl;
	cout << "================" << endl;
} // 상태창 보기

void Character::levelUp() {
	cout << "레벨 업" << endl;
	exp -= 100;
	if (level >= 10) {
		level = 10;
		return;
	} // 예외 처리
	level++;
	maxHealth = (maxHealth + (level * 20));
	attack = (attack + (level * 5));
	health = maxHealth;
} // 레벨업 함수

void Character::addItem(shared_ptr<Item> inputItem, int inputCount) { // 임시 Item 클래스명 변경시 수정 필요
	if (inventory.empty()) {
		inventory.emplace_back(inputItem, inputCount); // emplace_back 으로 객체 생성하여 삽입 push_back 수정 가능
		cout << "[" << inputItem->getName() << "] (이)가 " << inputCount << "개 새롭게 추가되었습니다." << endl;
		cout << "[" << inputItem->getName() << "] x" << inputCount << endl;
		return;
	} // 처음 아이템 추가시 비어있으면 중복 체크없이 바로 추가
	for (auto& invItem : inventory) {
		if (invItem.item->getName() == inputItem->getName()) {
			invItem.count += inputCount;
			cout << "[" << invItem.item->getName() << "] (이)가 " << inputCount << "개 추가되었습니다." << endl;
			cout << "[" << invItem.item->getName() << "] x" << invItem.count << endl;
			return;
		}
	} // 중복 아이템 체크후 있을 경우 count 증가
	inventory.emplace_back(inputItem, inputCount);
	cout << "[" << inputItem->getName() << "] (이)가 " << inputCount << "개 새롭게 추가되었습니다." << endl;
	cout << "[" << inputItem->getName() << "] x" << inputCount << endl;
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
			cout << "아이템 감소: [" << it->item->getName() << "]" << endl;
			cout << "[" << it->item->getName() << "] x" << it->count << endl;
			if (it->count <= 0) {
				cout << "[" << it->item->getName() << "] 해당 아이템을 전부 사용하였습니다." << endl;
				inventory.erase(it);
			}
			return;
		}
	}// 중복 아이템 체크후 있을 경우 count 감소
	cout << "해당 아이템이 인벤토리에 없습니다." << endl; // 예외 처리
} // 아이템 제거

//bool Character::isDead() const {
//	return health <= 0;
//} // 캐릭터 생사여부 판단 함수 필요시 부활조건 등을 추가해서 확장 가능

shared_ptr<Item> Character::findItem(const string& inputName) {
	for (const auto& invItem : inventory) {
		if (invItem.item->getName() == inputName) return invItem.item;
	} // 인자로 받은 이름과 동일한 아이템이 있는지 찾은후 찾았다면 해당 아이템 포인터를 넘겨줌
	return nullptr; // 없다면 nullptr
}

void Character::showInventory() {
	if (inventory.empty()) {
		cout << "인벤토리가 비어있습니다." << endl;
		return;
	} // 예외 처리
	cout << "=====Inventory=====" << endl;
	for (const auto& invItem : inventory) {
		cout << "[" << invItem.item->getName() << "] x" << invItem.count << endl;
	}
	cout << "===================" << endl;
}

void Character::addExp(int inputExp) {
	exp = inputExp;
	if (exp >= 100) levelUp();
}

// getter
const string& Character::getName() const {
	return name;
}

int Character::getMaxHealth() const {
	return maxHealth;
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
	return exp;
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

//void Character::setExperience(int inputExperience) {
//	experience = inputExperience; // 이름은 addExp로 수정 exp 100 이상이면 levelUp()호출
//}

void Character::setGold(int inputGold) {
	gold = inputGold;
}

