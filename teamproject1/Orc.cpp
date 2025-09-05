#include "Orc.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "ItemFactory.h"

Orc::Orc(int level)
    : Monster("Orc", 0, 0) {
    health = generateStat(level, 20, 30);  // ü��: ���� �� 20 ~ 30
    attack = generateStat(level, 5, 10);   // ���ݷ�: ���� �� 5 ~ 10
}

// Monster Ŭ������ ���� ��� �Լ� ȣ��
void Orc::interactWithCharacter(Character& character) {
    printIntro();
}

Item* Orc::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion(); // ��� ���� �� ���� ����
    }
    return nullptr; // ��� ����
}

int Orc::getExpReward() const {
    return 50; 
}
