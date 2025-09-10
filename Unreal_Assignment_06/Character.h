#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Item.h"

using namespace std;

class Character
{
private:
	//�����ڿ� �Ҹ���
	Character(string name);
	~Character();

	//�̱��� ����, ���� ����
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

	//���Լ�
	std::string getName();
	int getLevel();
	int getHealth();
	int getMaxHealth();
	int getAttack();
	int getExp();
	int getGold();

	//add�Լ�
	void setHealth(int health);
	void setGold(int gold);
	//set�Լ�
	void setAttack(int attack);

	//����ġ ȹ��
	void addExp(int exp);


	//ĳ���� ����Լ�
	void displayStatus();
	void levelUp();
	void removeItem(const string& itemName);
	void showInventory();

	shared_ptr<Item> findItem(const string& itemName);

	void addInventory(shared_ptr<Item> item, int count);

	//struct�� ����ؼ� ������ ���� ����
	struct InventoryItem
	{
		//�޸� ���� ������ shared_ptr
		std::shared_ptr<Item> item;
		int count;
	};
	vector<InventoryItem> inventory;



};

