#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Item.h"

using namespace std;

class Character
{
private:
	//생성자와 소멸자
	Character(string name);
	~Character();

	//싱글턴 복사, 대입 방지
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int exp;
	int gold;


public:
	static Character& getInstance(const std::string& name = "DefaultName");

	//겟함수
	std::string getName();
	int getLevel();
	int getHealth();
	int getMaxHealth();
	int getAttack();
	int getExp();
	int getGold();

	//add함수
	void setHealth(int health);
	void setGold(int gold);
	//set함수
	void setAttack(int attack);

	//경험치 획득
	void addExp(int exp);


	//캐릭터 기능함수
	void displayStatus();
	void levelUp();
	void removeItem(const string& itemName);
	void showInventory();

	shared_ptr<Item> findItem(const string& itemName);

	void addInventory(shared_ptr<Item> item, int count);

	//struct를 사용해서 아이템 갯수 관리
	struct InventoryItem
	{
		//메모리 누수 방지용 shared_ptr
		std::shared_ptr<Item> item;
		int count;
	};
	vector<InventoryItem> inventory;



};

