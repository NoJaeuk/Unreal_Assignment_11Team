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


	//ĳ���� ����
	std::cout << "==================================================\n";
	std::cout << "������ �����մϴ�! ����� ĳ���͸� �����մϴ�\n";
	std::cout << "==================================================\n";
	std::cout << "\nĳ������ �̸��� �Է��մϴ� : ";
	std::cin >> name;
	Character& player = Character::getInstance(name);
	std::cout << endl;
	player.displayStatus();

	//���� ä���
	gm.restockShop(shop);


	//���ӽ���
	while (!gameFinish)
	{

		std::cout << "\n==================================================\n";
		std::cout << "���� �ൿ�� �Է����ּ���! (���ڸ� �Է� ����)\n";
		std::cout << "[1. ����]  [2. ����]  [3. �κ��丮]  [4. ����]  [5. ų�α�]\n";
		std::cout << "==================================================\n";
		std::cout << "\n�Է� : ";
		std::cin >> gameOrder;
		if (cin.fail()) {
			cin.clear(); // cin ���� �ʱ�ȭ
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���� ����
			std::cout << "\n�߸��� �Է��Դϴ�! ���ڸ� �Է��ϼ���.\n";
			continue;
		}
		if (gameOrder != 1 && gameOrder != 2 && gameOrder != 3 && gameOrder != 4 && gameOrder != 5) {
			std::cout << "�߸��� ����Դϴ�!\n";
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