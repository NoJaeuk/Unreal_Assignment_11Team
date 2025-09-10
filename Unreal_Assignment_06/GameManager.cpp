#include <iostream>
#include <random>
#include <limits>
#include "GameManager.h"
#include "Monster.h"
#include "BossMonster.h"
#include "Character.h"
#include "Shop.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Slime.h"
#include "Dragon.h"


GameManager::GameManager() { gameFinish = false; }

//��������
int getRandom(int first, int second) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dist(first, second);
	return dist(gen);  
}

//���� ����
Monster* GameManager::generateMonster(const int level)
{
	if (level == 10) {
		Monster* monster = generateBossMonster(level);
		return monster;
	}
	int random = getRandom(0, 3);
	Monster* monster = nullptr;
	switch (random)
	{
	case 0: monster = new Goblin(level); break;
	case 1: monster = new Slime(level); break;
	case 2: monster = new Orc(level); break;
	case 3: monster = new Troll(level); break;
	}
	return monster;
}

BossMonster* GameManager::generateBossMonster(const int level)
{
	BossMonster* monster = new BossMonster(level);
	return monster;
}



//���� ����
void GameManager::battle(Character* character)
{
	Monster* monster = generateMonster(character->getLevel());
	bool battlefinish = false;
	int originalAttack = character->getAttack();
	const int monsterHP = monster->getHealth();
	while (!battlefinish) {
		int order;
		std::cout << "==================================================\n";
		std::cout << "�� ���� : [" << monster->getName() << "] HP : [" << monster->getHealth() << "/" << monsterHP << "] ���ݷ� : [" << monster->getAttack() << "]\n";
		std::cout << "==================================================\n";
		std::cout << "\n==================================================\n";
		std::cout << "�� ���� : [" << character->getName() << "] HP : [" << character->getHealth() << "/" << character->getMaxHealth() << "] ���ݷ� : [" << character->getAttack() << "]\n";
		std::cout << "==================================================\n";
		std::cout << "\n [1. ����]   [2. ������] \n";
		std::cout << "==================================================\n";
		std::cout << "���� �Է� : ";
		std::cin >> order;
		if (cin.fail()) {
			cin.clear(); // cin ���� �ʱ�ȭ
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���� ����
			std::cout << "�߸��� �Է��Դϴ�! ���ڸ� �Է��ϼ���.\n";
			continue;
		}
		if (order != 1 && order != 2) {
			std::cout << "�߸��� �Է��Դϴ�!\n";
			continue;
		}
		switch (order)
		{
		case 1:
			monster->takeDamage(character->getAttack());
			std::cout << character->getName() << " �� ����! " << character->getAttack() << " �� ������!\n";
			break;
		case 2:
			std::string	itemName;
			bool itemUsing = true;
			character->showInventory();
			while (itemUsing)
			{
				std::cout << "����Ͻ� �������� �̸��� �Է�(cancel�� �Է��� ���) : ";
				getline(std::cin >> std::ws, itemName);
				//std::cin >> itemName;
				if (character->findItem(itemName) == nullptr && itemName != "cancel") { std::cout << "�Էµ� �������� ã�� �� �����ϴ�!\n"; }
				else if (itemName != "cancel") {
					character->findItem(itemName)->use(character);
					character->removeItem(itemName);
					itemUsing = false;
					break;
				}
				if (itemName == "cancel") { itemUsing = false;  break; }
			}
			if (itemName == "cancel") { continue; }
		}
		//���Ͱ� ������ ���
		if (monster->getHealth() == 0) {
			battlefinish = true;
			std::cout << monster->getName() << "��(��) ���������ϴ�!\n";
			if (character->getLevel() == 10) {
				std::cout << "���ӿ��� �¸��ϼ̽��ϴ�! �����մϴ�!\n";
				gameFinish = true;
				battlefinish = true;
				delete monster;
			}
			else {
				character->setAttack(originalAttack);	//���� ���ݷ����� ������
				int dropG = monster->dropGold();
				std::cout << "����ġ : " << monster->dropExp() << "   ��� : " << dropG << " G ȹ��!\n";
				shared_ptr<Item> item = monster->dropItem();
				if (item != nullptr) {
					std::cout << item->getName() << " ��(��) ȹ���ߴ�!\n";
					character->addInventory(item, 1);
				}
				addKillLog(monster->getName());
				character->addExp(monster->dropExp());
				character->setGold(character->getGold() + dropG);
				battlefinish = true;
				delete monster;
			}
			break;
		}
		//������ �ݰ�
		std::cout << monster->getName() << " �� ����! " << monster->getAttack() << " �� ������!\n";
		character->setHealth(character->getHealth() - monster->getAttack());
		//ĳ���Ͱ� ������ ���
		if (character->getHealth() == 0) {
			std::cout << character->getName() << " ��(��) ���������ϴ�!\n";
			std::cout << "Game Over\n";
			battlefinish = true;
			delete monster;
			gameFinish = true;
			break;
		}
	}
}

void GameManager::restockShop(Shop* shop) {
	std::string name;
	auto potion = std::make_shared<HealthPotion>("HealthPotion", 20, 50);
	auto boost = std::make_shared<AttackBoost>("AttackBoost", 30, 30);
	shop->addItem(potion, 5);
	shop->addItem(boost, 5);
}

//���� ����
void GameManager::visitShop(Character* character, Shop* shop) 
{
	int buyorsell;
	std::string buyname;
	std::string sellname;
	bool buyfinish = false;
	bool sellfinish = false;
	bool shopfinish = false;
	std::cout << "\n[������ �湮�մϴ�!]\n";

	while (!shopfinish)
	{
		buyfinish = false;
		sellfinish = false;
		std::cout << "\n1. ����\n" << "2. �Ǹ�\n" << "3. ������\n";
		std::cout << "\n�Է� : ";
		std::cin >> buyorsell;
		if (cin.fail()) {
			cin.clear(); // cin ���� �ʱ�ȭ
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���� ����
			std::cout << "\n�߸��� �Է��Դϴ�! ���ڸ� �Է��ϼ���.\n";
			continue;
		}
		if (buyorsell != 1 && buyorsell != 2 && buyorsell != 3) {
			std::cout << "�߸��� ���� �Է��ϼ̽��ϴ�!\n";
			continue;
		}
		switch (buyorsell)
		{
		case 1:
			while (!buyfinish)
			{
				shop->displayItems();
				std::cout << "�������� ��� : " << character->getGold() << "\n";
				cout << "\n�����Ͻ� ��ǰ�� �̸��� �Է��մϴ�(finish �Է½� ������ ��Ĩ�ϴ�) : ";
				std::cin >> buyname;
				if (buyname == "finish") { buyfinish = true; break; }
				if (buyname == "Random") { shop->randomPick(character); continue; }
				shop->buyItem(buyname, character);
			}
			break;

		case 2:
			while (!sellfinish)
			{
				character->showInventory();
				std::cout << "�������� ��� : " << character->getGold() << "\n";
				std::cout << "\n�Ǹ��Ͻ� ��ǰ�� �̸��� �Է��մϴ�(finish �Է½� �ǸŸ� ��Ĩ�ϴ�) : ";
				getline(std::cin >> std::ws, sellname);
				//std::cin >> sellname;
				if (sellname == "finish") { sellfinish = true; break; }
				shop->sellItem(sellname, character);
			}
			break;

		case 3:
			shopfinish = true;
			break;
		}
	}

}

void GameManager::addKillLog(std::string name) {
	for (auto& kill : killLog) {
		if (kill.name == name) {
			kill.count++; // �̹� ������ ������ ����
			return; // ������
		}
	}
	KillLog kill;
	kill.name = name;
	kill.count = 1;
	killLog.push_back(kill);
}

void GameManager::showKillLog() {
	std::cout << "\n==================================================\n";
	std::cout << "[KILL LOG]\n";
	for (auto& kill : killLog) {
		std::cout << "[" << kill.name << "] : " << kill.count << " kill\n";
	}
	std::cout << "==================================================\n";
}