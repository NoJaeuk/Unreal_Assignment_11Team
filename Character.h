#pragma once
#include <string>
#include <vector>
#include <memory>
#include "healthPotion.h" // �ӽ� ��� ����
#include "shop.h" // �ӽ� ��� ����

using namespace std;

//class Item; // �ӽ� Item Ŭ���� ���� ����(����� ���� �ʿ�)

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
	struct itemCount {
		shared_ptr<Item> item; // �ӽ� Item Ŭ������ ����� ���� �ʿ�
		int count; // ������ ����
		itemCount(shared_ptr<Item> inputItem, int inputCount = 1); // ������
	}; // ������ ��ü�� ������ �����ϴ� sturct ��� ����
	vector<itemCount> inventory; // itemCount ����� �κ��丮
	Character(const string& inputName); // ������
	// ���� ����
	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;
	Character(Character&&) = delete;
	Character& operator = (Character&&) = delete;
public:
	static Character* getInstance(string inputName = ""); // name ������ �ߺ����� ���� �޸տ��� ������ inputName ���� �ٲ�
	void displayStatus(); // ĳ���� ����â Ȯ�� �Լ�
	void levelUp(); // ĳ���� ������ ���� �Լ�
	//void useItem(int index); // Ȯ�强�� ���� ������ ���� �Լ��� ��ü
	void visitShop(); // ���� �湮 �Լ� �̱���(���� �ʿ�)
	void addItem(shared_ptr<Item> inputItem); // ������ �߰� �Լ�
	void removeItem(shared_ptr<Item> inputItem); // ������ ���� �Լ�
	bool isDead() const; // ĳ���� ���翩�� �Ǵ� �Լ�
	// getter
	const string& getName() const; // ȿ������ ���� ����� �������� ��ȯ�ϰ� ����
	//int getMaxHealth(); // �ʿ�� �߰�
	int getLevel() const; // �������� ���� �б� �������� ����
	int getHealth() const;
	int getAttack() const;
	int getExperience() const;
	int getGold() const;
	// setter
	//void setName(string val); // �ʿ�� �߰�
	//void setMaxHealth(int val); // �ʿ�� �߰�
	//void setLevel(int val); // �ʿ�� �߰�
	void setHealth(int inputHealth);
	void setAttack(int inputAttack);
	void setExperience(int inputExperience);
	void setGold(int inputGold);
};
