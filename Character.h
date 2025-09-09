#pragma once
#include <string>
#include <vector>
#include <memory>
#include "healthPotion.h" // �ӽ� ��� ����

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
		shared_ptr<Item> item; // �ӽ� Item Ŭ������ ����� ���� �ʿ�
		int count; // ������ ����
		itemCount(shared_ptr<Item> inputItem, int inputCount = 1); // ����ü itemCount ������
	}; // ������ ������ �����ϱ� ���� ����ü ��� ����
	vector<itemCount> inventory;
	Character(const string& inputName); // ������
	~Character(); // �Ҹ���
	// ���� ����
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
	//bool isDead() const; // ĳ���� ���翩�� �Ǵ� �Լ�
	
	// getter
	const string& getName() const;
	int getMaxHealth() const; 
	int getLevel() const;
	int getHealth() const;
	int getAttack() const;
	int getExp() const;
	int getGold() const;

	// setter
	//void setName(string val); // �ʿ�� �߰�
	//void setMaxHealth(int val); // �ʿ�� �߰�
	//void setLevel(int val); // �ʿ�� �߰�
	void setHealth(int inputHealth);
	void setAttack(int inputAttack);
	void setGold(int inputGold);
};
