#include "Character.h"

using namespace std;

Character::Character(const string& inputName) : level(1), maxHealth(200), health(maxHealth), attack(30), experience(0), gold(0) {}
// ĳ���� ������ ȿ������ ���� �ʱ�ȭ ����Ʈ�� �����ϰ� ���ڴ� ���Ÿ�԰� ������ �޴°ŷ� ����

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

void Character::useItem(int index) {
	//�̱���
} // ������ ���

void Character::visitShop() {
	/* ����
	Shop shop;
	shop.shopOpen();
	*/
} // ���� �湮

void Character::addItem(shared_ptr<Item> inputItem) {
	inventory.push_back(inputItem);
} // ������ �߰�

//getter
const string& Character::getName() {
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

//setter
void Character::setHealth(const int& inputHealth) {
	health = inputHealth;
}

void Character::setAttack(const int& inputAttack) {
	attack = inputAttack;
}

void Character::setExperience(const int& inputExperience) {
	experience = inputExperience;
}

void Character::setGold(const int& inputGold) {
	gold = inputGold;
}
