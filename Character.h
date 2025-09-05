#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "shop.h"

using namespace std;

class Character {
private:
	static Character* instance; // 싱글톤 생성
	string name;
	int level;
	int maxHealth;
	int health;
	int attack;
	int experience;
	int gold;
	vector<shared_ptr<Item>> inventory;
	Character(const string& inputName);
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
	void addItem(shared_ptr<Item> inputItem);
	//getter
	const string& getName(); // 효율성을 위해 상수와 참조값을 반환하게 변경
	//int getMaxHealth(); // 필요시 추가
	int getLevel() const; // 안정성을 위해 읽기 전용으로 변경
	int getHealth() const;
	int getAttack() const;
	int getExperience() const;
	int getGold() const;
	//setter
	//void setName(string val); // 필요시 추가
	//void setMaxHealth(int val); // 필요시 추가
	//void setLevel(int val); // 필요시 추가
	void setHealth(int inputHealth);
	void setAttack(int inputAttack);
	void setExperience(int inputExperience);
	void setGold(int inputGold);
};
