#include "Character.h"
#include <iostream>
//#include <algorithm>

using namespace std;

Character::Character(const string& inputName) : name(inputName), level(1), maxHealth(200), health(maxHealth), attack(30), experience(0), gold(0) {}
// ĳ���� ������ ȿ������ ���� �ʱ�ȭ ����Ʈ�� �����ϰ� string ��ü�� ���Ÿ�԰� ������ �޴°ŷ� ����

Character::itemCount::itemCount(shared_ptr<Item> inputItem, int inputCount, int inputPrice) : item(inputItem), count(inputCount), price(inputPrice) {}
// ������ �ʱ�ȭ ����Ʈ

Character* Character::getInstance(string inputName) {
	if (instance == nullptr) {
		instance = new Character(inputName);
	}
	return instance;
} // �̱��� ����

void Character::displayStatus() {
	cout << "=====Status=====" << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << level << endl;
	cout << "���� ü��: " << health << "/" << maxHealth << endl;
	cout << "���ݷ�: " << attack << endl;
	cout << "����ġ: " << experience << endl;
	cout << "������: " << gold << endl;
} // ����â ����

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
} // ������ �Լ�

void Character::visitShop() {
	// �ӽ� Shop Ŭ������ ����� ���� �ʿ�
	//Shop shop;
	//shop.shopOpen();
} // ���� �湮

void Character::addItem(shared_ptr<Item> inputItem) { // �ӽ� Item Ŭ������ ����� ���� �ʿ�
	if (inventory.empty()) {
		inventory.emplace_back(inputItem, 1); // emplace_back ���� ��ü �����Ͽ� ����
		cout << "[" << inputItem->getName() << "] �� ���Ӱ� �߰��Ǿ����ϴ�." << endl;
		cout << "[" << inputItem->getName() << "] �� ���� ����: 1��" << endl;
		return;
	} // ó�� ������ �߰��� ��������� �ߺ� üũ���� �ٷ� �߰�
	for (auto& invItem : inventory) {
		if (invItem.item->getName() == inputItem->getName()) {
			invItem.count++;
			cout << "������ �߰� -> [" << invItem.item->getName() << "] ���� ����: " << invItem.count << "��" << endl;
			return;
		}
	} // �ߺ� ������ üũ�� ���� ��� count ����
	inventory.emplace_back(inputItem, 1);
	cout << "[" << inputItem->getName() << "] �� ���Ӱ� �߰��Ǿ����ϴ�." << endl;
	cout << "[" << inputItem->getName() << "] �� ���� ����: 1��" << endl;
	// �ߺ��Ǵ� ������ ���� ��� �߰�
} // ������ �߰�

void Character::removeItem(shared_ptr<Item> inputItem) {
	if (inventory.empty()) {
		cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
		return;
	} // ���� ó��
	for (auto it = inventory.begin(); it != inventory.end(); it++) {
		if (it->item->getName() == inputItem->getName()) {
			it->count--;
			cout << "������ ���� -> [" << it->item->getName() << "] ���� ����: " << it->count << "��" << endl;
			if (it->count <= 0) {
				cout << "[" << it->item->getName() << "] �ش� �������� ���� ����Ͽ����ϴ�." << endl;
				inventory.erase(it);
			}
			return;
		}
	}// �ߺ� ������ üũ�� ���� ��� count ����
	cout << "�ش� �������� �κ��丮�� �����ϴ�." << endl; // ���� ó��
} // ������ ����

bool Character::isDead() const {
	return health <= 0;
} // ĳ���� ���翩�� �Ǵ� �Լ� �ʿ�� ��Ȱ���� ���� �߰��ؼ� Ȯ�� ����

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

