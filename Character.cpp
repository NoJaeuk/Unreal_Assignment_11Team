#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(const string& inputName) : name(inputName), level(1), maxHealth(200), health(maxHealth), attack(30), exp(0), gold(0) {}
Character::~Character() {
	//cout << "Character ��ü �Ҹ��� ȣ��" << endl; // ������ �޼���
}
// ĳ���� ������ ȿ������ ���� �ʱ�ȭ ����Ʈ�� �����ϰ� string ��ü�� ���Ÿ�԰� ������ �޴°ŷ� ����

Character::itemCount::itemCount(shared_ptr<Item> inputItem, int inputCount) : item(inputItem), count(inputCount) {}
// ������ �ʱ�ȭ ����Ʈ

Character& Character::getInstance(string inputName) {
	static Character instance(inputName);
	return instance;
} // �̱��� ����

void Character::displayStatus() {
	cout << "=====Status=====" << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << level << endl;
	cout << "���� ü��: " << health << "/" << maxHealth << endl;
	cout << "���ݷ�: " << attack << endl;
	cout << "����ġ: " << exp << endl;
	cout << "������: " << gold << endl;
	cout << "================" << endl;
} // ����â ����

void Character::levelUp() {
	cout << "���� ��" << endl;
	exp -= 100;
	if (level >= 10) {
		level = 10;
		return;
	} // ���� ó��
	level++;
	maxHealth = (maxHealth + (level * 20));
	attack = (attack + (level * 5));
	health = maxHealth;
} // ������ �Լ�

void Character::addItem(shared_ptr<Item> inputItem, int inputCount) { // �ӽ� Item Ŭ������ ����� ���� �ʿ�
	if (inventory.empty()) {
		inventory.emplace_back(inputItem, inputCount); // emplace_back ���� ��ü �����Ͽ� ���� push_back ���� ����
		cout << "[" << inputItem->getName() << "] (��)�� " << inputCount << "�� ���Ӱ� �߰��Ǿ����ϴ�." << endl;
		cout << "[" << inputItem->getName() << "] x" << inputCount << endl;
		return;
	} // ó�� ������ �߰��� ��������� �ߺ� üũ���� �ٷ� �߰�
	for (auto& invItem : inventory) {
		if (invItem.item->getName() == inputItem->getName()) {
			invItem.count += inputCount;
			cout << "[" << invItem.item->getName() << "] (��)�� " << inputCount << "�� �߰��Ǿ����ϴ�." << endl;
			cout << "[" << invItem.item->getName() << "] x" << invItem.count << endl;
			return;
		}
	} // �ߺ� ������ üũ�� ���� ��� count ����
	inventory.emplace_back(inputItem, inputCount);
	cout << "[" << inputItem->getName() << "] (��)�� " << inputCount << "�� ���Ӱ� �߰��Ǿ����ϴ�." << endl;
	cout << "[" << inputItem->getName() << "] x" << inputCount << endl;
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
			cout << "������ ����: [" << it->item->getName() << "]" << endl;
			cout << "[" << it->item->getName() << "] x" << it->count << endl;
			if (it->count <= 0) {
				cout << "[" << it->item->getName() << "] �ش� �������� ���� ����Ͽ����ϴ�." << endl;
				inventory.erase(it);
			}
			return;
		}
	}// �ߺ� ������ üũ�� ���� ��� count ����
	cout << "�ش� �������� �κ��丮�� �����ϴ�." << endl; // ���� ó��
} // ������ ����

//bool Character::isDead() const {
//	return health <= 0;
//} // ĳ���� ���翩�� �Ǵ� �Լ� �ʿ�� ��Ȱ���� ���� �߰��ؼ� Ȯ�� ����

shared_ptr<Item> Character::findItem(const string& inputName) {
	for (const auto& invItem : inventory) {
		if (invItem.item->getName() == inputName) return invItem.item;
	} // ���ڷ� ���� �̸��� ������ �������� �ִ��� ã���� ã�Ҵٸ� �ش� ������ �����͸� �Ѱ���
	return nullptr; // ���ٸ� nullptr
}

void Character::showInventory() {
	if (inventory.empty()) {
		cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
		return;
	} // ���� ó��
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
//	experience = inputExperience; // �̸��� addExp�� ���� exp 100 �̻��̸� levelUp()ȣ��
//}

void Character::setGold(int inputGold) {
	gold = inputGold;
}

