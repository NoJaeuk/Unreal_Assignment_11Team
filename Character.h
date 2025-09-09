#pragma once
#include <string>
#include <vector>
#include <memory>
#include "healthPotion.h" // 임시 헤더 파일

using namespace std;

class Character {
private:
	string name;
	int level;
	int maxHealth;
	int health;
	int attack;
	int exp;
	int gold;
	struct itemCount {
		shared_ptr<Item> item; // 임시 Item 클래스명 변경시 수정 필요
		int count; // 아이템 개수
		itemCount(shared_ptr<Item> inputItem, int inputCount = 1); // 구조체 itemCount 생성자
	}; // 아이템 개수를 관리하기 위한 구조체 멤버 변수
	vector<itemCount> inventory;
	Character(const string& inputName); // 생성자
	~Character(); // 소멸자
	// 복사 방지
	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;
	Character(Character&&) = delete;
	Character& operator = (Character&&) = delete;
public:
	static Character& getInstance(string inputName = "");
	void displayStatus();
	void levelUp();
	void addItem(shared_ptr<Item> inputItem, int inputCount);
	void removeItem(shared_ptr<Item> inputItem);
	shared_ptr<Item> findItem(const string& inputName) const;
	void showInventory();
	void addExp(int inputExp);
	//bool isDead() const; // 캐릭터 생사여부 판단 함수
	
	// getter
	const string& getName() const;
	int getMaxHealth() const; 
	int getLevel() const;
	int getHealth() const;
	int getAttack() const;
	int getExp() const;
	int getGold() const;

	// setter
	//void setName(string val); // 필요시 추가
	//void setMaxHealth(int val); // 필요시 추가
	//void setLevel(int val); // 필요시 추가
	void setHealth(int inputHealth);
	void setAttack(int inputAttack);
	void setGold(int inputGold);
};
