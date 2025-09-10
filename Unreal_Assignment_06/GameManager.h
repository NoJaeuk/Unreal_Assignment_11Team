#pragma once
#include "Monster.h"
#include "BossMonster.h"
#include "Character.h"
#include "Shop.h"

//���� �޴��������� ������ �÷����ϴ� ���� �߻��ϴ� �ؽ�Ʈ�� �����ϰ�
//������ �ٽ� �ý����� �����Ѵ�.
//���� �ν��Ͻ��� ������ �̰����� �����Ѵ�.

class GameManager
{
public:
	GameManager();

	bool gameFinish;

	//���� ����
	Monster* generateMonster(const int level);
	BossMonster* generateBossMonster(const int level);

	//���� ����
	void battle(Character* character);

	//���� ����
	void visitShop(Character* character, Shop* shop);

	//���� ����
	void restockShop(Shop* shop);

	//ų�α� ����
	void addKillLog(std::string name);

	//ų�α� ���
	void showKillLog();

private:
	struct KillLog {
		std::string name;
		int count;
	};
	std::vector<KillLog> killLog;
};

