#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance; // 싱글톤 생성
	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;
	vector<Item*> inventory;
	Character(string inputName);
	//복사 방지
	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;
	Character(Character&&) = delete;
	Character& operator = (Character&&) = delete;
public:
	static Character* getInstance(string inputName = ""); // name 변수명 중복으로 생길 휴먼에러 방지차 inputName 으로 바꿈
	void displayStatus();
	void levelUp();
	void useItem(int index);
	void visitShop();
};
