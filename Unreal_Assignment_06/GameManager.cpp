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

//랜덤숫자
int getRandom(int first, int second) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dist(first, second);
	return dist(gen);  
}

//몬스터 생성
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



//전투 실행
void GameManager::battle(Character* character)
{
	Monster* monster = generateMonster(character->getLevel());
	bool battlefinish = false;
	int originalAttack = character->getAttack();
	const int monsterHP = monster->getHealth();
	while (!battlefinish) {
		int order;
		std::cout << "==================================================\n";
		std::cout << "적 정보 : [" << monster->getName() << "] HP : [" << monster->getHealth() << "/" << monsterHP << "] 공격력 : [" << monster->getAttack() << "]\n";
		std::cout << "==================================================\n";
		std::cout << "\n==================================================\n";
		std::cout << "내 정보 : [" << character->getName() << "] HP : [" << character->getHealth() << "/" << character->getMaxHealth() << "] 공격력 : [" << character->getAttack() << "]\n";
		std::cout << "==================================================\n";
		std::cout << "\n [1. 공격]   [2. 아이템] \n";
		std::cout << "==================================================\n";
		std::cout << "숫자 입력 : ";
		std::cin >> order;
		if (cin.fail()) {
			cin.clear(); // cin 상태 초기화
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기
			std::cout << "잘못된 입력입니다! 숫자를 입력하세요.\n";
			continue;
		}
		if (order != 1 && order != 2) {
			std::cout << "잘못된 입력입니다!\n";
			continue;
		}
		switch (order)
		{
		case 1:
			monster->takeDamage(character->getAttack());
			std::cout << character->getName() << " 의 공격! " << character->getAttack() << " 의 데미지!\n";
			break;
		case 2:
			std::string	itemName;
			bool itemUsing = true;
			character->showInventory();
			while (itemUsing)
			{
				std::cout << "사용하실 아이템의 이름을 입력(cancel을 입력해 취소) : ";
				getline(std::cin >> std::ws, itemName);
				//std::cin >> itemName;
				if (character->findItem(itemName) == nullptr && itemName != "cancel") { std::cout << "입력된 아이템을 찾을 수 없습니다!\n"; }
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
		//몬스터가 쓰러진 경우
		if (monster->getHealth() == 0) {
			battlefinish = true;
			std::cout << monster->getName() << "이(가) 쓰러졌습니다!\n";
			if (character->getLevel() == 10) {
				std::cout << "게임에서 승리하셨습니다! 감사합니다!\n";
				gameFinish = true;
				battlefinish = true;
				delete monster;
			}
			else {
				character->setAttack(originalAttack);	//원래 공격력으로 돌리기
				int dropG = monster->dropGold();
				std::cout << "경험치 : " << monster->dropExp() << "   골드 : " << dropG << " G 획득!\n";
				shared_ptr<Item> item = monster->dropItem();
				if (item != nullptr) {
					std::cout << item->getName() << " 을(를) 획득했다!\n";
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
		//몬스터의 반격
		std::cout << monster->getName() << " 의 공격! " << monster->getAttack() << " 의 데미지!\n";
		character->setHealth(character->getHealth() - monster->getAttack());
		//캐릭터가 쓰러진 경우
		if (character->getHealth() == 0) {
			std::cout << character->getName() << " 이(가) 쓰러졌습니다!\n";
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

//상점 오픈
void GameManager::visitShop(Character* character, Shop* shop) 
{
	int buyorsell;
	std::string buyname;
	std::string sellname;
	bool buyfinish = false;
	bool sellfinish = false;
	bool shopfinish = false;
	std::cout << "\n[상점을 방문합니다!]\n";

	while (!shopfinish)
	{
		buyfinish = false;
		sellfinish = false;
		std::cout << "\n1. 구입\n" << "2. 판매\n" << "3. 나가기\n";
		std::cout << "\n입력 : ";
		std::cin >> buyorsell;
		if (cin.fail()) {
			cin.clear(); // cin 상태 초기화
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기
			std::cout << "\n잘못된 입력입니다! 숫자를 입력하세요.\n";
			continue;
		}
		if (buyorsell != 1 && buyorsell != 2 && buyorsell != 3) {
			std::cout << "잘못된 값을 입력하셨습니다!\n";
			continue;
		}
		switch (buyorsell)
		{
		case 1:
			while (!buyfinish)
			{
				shop->displayItems();
				std::cout << "보유중인 골드 : " << character->getGold() << "\n";
				cout << "\n구입하실 물품의 이름을 입력합니다(finish 입력시 구입을 마칩니다) : ";
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
				std::cout << "보유중인 골드 : " << character->getGold() << "\n";
				std::cout << "\n판매하실 물품의 이름을 입력합니다(finish 입력시 판매를 마칩니다) : ";
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
			kill.count++; // 이미 있으면 수량만 증가
			return; // 끝내기
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