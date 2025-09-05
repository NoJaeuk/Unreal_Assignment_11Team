#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance; // �̱��� ����
	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;
	vector<Item*> inventory;
	Character(string inputName);
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
};
