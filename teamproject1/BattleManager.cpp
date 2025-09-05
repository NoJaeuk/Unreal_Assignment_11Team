#include "BattleManager.h"
#include "BossMonster.h"
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>      // rand() �Լ� ����� ���� ǥ�� ���̺귯��

// ���� ���� �Լ�: ĳ���Ϳ� ���� ���� ������ �����ϰ� ����� ó����
void BattleManager::startBattle(Character& character, Monster& monster) {
    // ���� ���� �޽��� ���
    std::cout << "���� " << monster.getName() << " ����! ü��: "
        << monster.getHealth() << ", ���ݷ�: " << monster.getAttack() << "\n";

    // ���� ����: �� �� �ϳ��� ���� ������ �ݺ�
    while (!monster.isDead() && !character.isDead()) {
        // ĳ���� ����
        std::cout << character.getName() << "�� " << monster.getName() << "�� �����մϴ�!\n";
        monster.takeDamage(character.getAttack());// ���� ü�� ����
        std::cout << monster.getName() << " ü��: " << monster.getHealth() << "\n";

        // ���Ͱ� �׾����� ���� ����
        if (monster.isDead()) break;

        // ���� ����
        std::cout << monster.getName() << "�� " << character.getName() << "�� �����մϴ�!\n";
        character.takeDamage(monster.getAttack());
        std::cout << character.getName() << " ü��: " << character.getHealth() << "\n";

        // ������ ���� ���
        if (character.shouldUseItem()) {
            std::cout << "�̷� �� ������!\n";
            character.useRandomItem(); // ������ ��� (������ ����� ���� �ʿ�)
        }

    }

    // ���� óġ �� ���� ó��
    if (monster.isDead()) {
        int exp = monster.getExpReward();     // ���Ͱ� �ִ� ����ġ
        int gold = monster.getGoldReward();   // ���Ͱ� �ִ� ���

        character.addExp(exp);                // ĳ���Ͱ� ����ġ ȹ��
        character.addGold(gold);              // ĳ���Ͱ� ��� ȹ��

        std::cout << character.getName() << "�� "
            << exp << " EXP�� "
            << gold << " ��带 ȹ���߽��ϴ�.\n";

        // ������ ��� ó��
        Item* item = monster.dropItem();
        if (item != nullptr) {
            character.obtainItem(item);
        }

        // ������ üũ
		if (character.canLevelUp()) { //ĳ���� ������ ���� ���� �ʿ�
            character.levelUp();
        }

        // ���� ���� óġ �� ���� Ŭ���� �޽��� ���
        //monster�� BossMonsterŸ���� �ƴ� ��� nullptr ��ȯ
		//monster�� BossMonsterŸ���� ��� BossMonster* Ÿ�� ��ȯ
		if (character.getLevel() >= 10 && dynamic_cast<BossMonster*>(&monster) != nullptr) { 
            std::cout << "�����մϴ�! ����"<<monster.getName()<<"�� óġ�ϰ� ������ Ŭ�����߽��ϴ�!\n";
        }
    }

    // ĳ���Ͱ� �׾��� ��� ���� ���� ó��
    else {
        std::cout << character.getName() << "�� ����߽��ϴ�. ���� ����!\n";
    }
}
