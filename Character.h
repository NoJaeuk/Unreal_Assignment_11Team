#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "shop.h"

using namespace std;

class Character {
private:
	static Character* instance; // �̱��� ����
	string name;
	int level;
	int maxHealth;
	int health;
	int attack;
	int experience;
	int gold;
	vector<shared_ptr<Item>> inventory;
	Character(const string& inputName);
	//���� ����
	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;
	Character(Character&&) = delete;
	Character& operator = (Character&&) = delete;
public:
	static Character* getInstance(string inputName = ""); // name ������ �ߺ����� ���� �޸տ��� ������ inputName ���� �ٲ�
	void displayStatus();
	void levelUp();
	void useItem(int index);
	void visitShop();
	void addItem(shared_ptr<Item> inputItem);
	//getter
	const string& getName(); // ȿ������ ���� ����� �������� ��ȯ�ϰ� ����
	//int getMaxHealth(); // �ʿ�� �߰�
	int getLevel() const; // �������� ���� �б� �������� ����
	int getHealth() const;
	int getAttack() const;
	int getExperience() const;
	int getGold() const;
	//setter
	//void setName(string val); // �ʿ�� �߰�
	//void setMaxHealth(int val); // �ʿ�� �߰�
	//void setLevel(int val); // �ʿ�� �߰�
	void setHealth(int inputHealth);
	void setAttack(int inputAttack);
	void setExperience(int inputExperience);
	void setGold(int inputGold);
};
