#include "Goblin.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "ItemFactory.h"


// Goblin ������: ĳ������ ������ ������� Goblin�� ü�°� ���ݷ��� �����ϰ� ����
Goblin::Goblin(int level)
    : Monster("Goblin", 0, 0) {
    health = generateStat(level, 20, 30);  // ü��: ���� �� 20 ~ 30
    attack = generateStat(level, 5, 10);   // ���ݷ�: ���� �� 5 ~ 10
}


// ĳ���Ϳ��� ��ȣ�ۿ� �Լ�: Goblin�� �������� �� �ֿܼ� ���¸� ���
void Goblin::interactWithCharacter(Character& character) {
    printIntro();
}

Item* Goblin::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion(); // ��� ���� �� ���� ����
    }
    return nullptr; // ��� ����
}

int Goblin::getExpReward() const {
    return 50; 
}
