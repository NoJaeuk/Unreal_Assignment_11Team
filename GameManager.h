#pragma once
#include "Monster.h"
#include "BossMonster.h"
#include "Character.h"
#include "Shop.h"

//게임 메니저에서는 게임을 플레이하는 동안 발생하는 텍스트를 관리하고
//게임의 핵심 시스템을 구현한다.
//또한 인스턴스의 생성도 이곳에서 관리한다.

class GameManager
{
public:
	GameManager();

	bool gameFinish;

	//몬스터 생성
	Monster* generateMonster(const int level);
	BossMonster* generateBossMonster(const int level);

	//전투 실행
	void battle(Character* character);

	//상점 오픈
	void visitShop(Character* character, Shop* shop);

	//상점 리필
	void restockShop(Shop* shop);

	//킬로그 관리
	void addKillLog(std::string name);

	//킬로그 출력
	void showKillLog();

private:
	struct KillLog {
		std::string name;
		int count;
	};
	std::vector<KillLog> killLog;
};

