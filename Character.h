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
	int exp; // exp
	int gold;
	struct itemCount {
		shared_ptr<Item> item; // �ӽ� Item Ŭ������ ����� ���� �ʿ�
		int count; // ������ ����
		itemCount(shared_ptr<Item> inputItem, int inputCount = 1); // ����ü itemCount ������
	}; // ������ ��ü�� ������ �����ϴ� sturct ��� ����
	vector<itemCount> inventory; // itemCount ����� �κ��丮
	Character(const string& inputName); // ������
	~Character(); // �Ҹ���
	// ���� ����
	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;
	Character(Character&&) = delete;
	Character& operator = (Character&&) = delete;
public:
	static Character& getInstance(string inputName = ""); // name ������ �ߺ����� ���� �޸տ��� ������ inputName ���� �ٲ�
	void displayStatus(); // ĳ���� ����â Ȯ�� �Լ�
	void levelUp(); // ĳ���� ������ ���� �Լ�
	void addItem(shared_ptr<Item> inputItem, int inputCount); // ������ �߰� �Լ�, ���ڷ� ī��Ʈ �߰�
	void removeItem(shared_ptr<Item> inputItem); // ������ ���� �Լ�
	//bool isDead() const; // ĳ���� ���翩�� �Ǵ� �Լ�
	shared_ptr<Item> findItem(const string& inputName) const; // ������ ��ü �˻��� ��ȯ�ϴ� �Լ� ������ nullptr
	void showInventory(); // void �κ��丮 ������ �� ���
	void addExp(int inputExp); // sexExperience -> addExp�� ���� ����ġ���� 100�� �ʰ��ϸ� levelUp() ȣ��
	// getter
	const string& getName() const; // ȿ������ ���� ����� �������� ��ȯ�ϰ� ����
	int getMaxHealth() const; 
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
	//void setExperience(int inputExperience); // addExp
	void setGold(int inputGold);
};
