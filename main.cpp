#include <iostream>
#include "GameManager.h"
#include "Character.h"
#include "Shop.h"

int main(void) {
	std::string name;
	bool gameFinish = false;
	int gameOrder;
	GameManager gm = GameManager();
	Shop* shop =new Shop();


	//캐릭터 생성
	std::cout << "==================================================\n";
	std::cout << "게임을 시작합니다! 당신의 캐릭터를 생성합니다\n";
	std::cout << "==================================================\n";
	std::cout << "\n캐릭터의 이름을 입력합니다 : ";
	std::cin >> name;
	Character& player = Character::getInstance(name);
	std::cout << endl;
	player.displayStatus();

	//상점 채우기
	gm.restockShop(shop);


	//게임시작
	while (!gameFinish)
	{

		std::cout << "\n==================================================\n";
		std::cout << "다음 행동을 입력해주세요! (숫자만 입력 가능)\n";
		std::cout << "[1. 전투]  [2. 상점]  [3. 인벤토리]  [4. 스탯]  [5. 킬로그]\n";
		std::cout << "==================================================\n";
		std::cout << "\n입력 : ";
		std::cin >> gameOrder;
		if (cin.fail()) {
			cin.clear(); // cin 상태 초기화
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기
			std::cout << "\n잘못된 입력입니다! 숫자를 입력하세요.\n";
			continue;
		}
		if (gameOrder != 1 && gameOrder != 2 && gameOrder != 3 && gameOrder != 4 && gameOrder != 5) {
			std::cout << "잘못된 명령입니다!\n";
			continue;
		}
		switch (gameOrder)
		{
		case 1:
			gm.battle(&player);
			break;

		case 2:
			gm.visitShop(&player, shop);
			break;

		case 3:
			player.showInventory();
			break;

		case 4:
			player.displayStatus();
			break;

		case 5:
			gm.showKillLog();
			break;

		}
		if (gm.gameFinish) { gameFinish = true;  break; }
	}

	return 0;
}