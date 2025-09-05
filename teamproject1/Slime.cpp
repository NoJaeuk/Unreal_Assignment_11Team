#include "Slime.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "ItemFactory.h"


Slime::Slime(int level)
    : Monster("Slime", 0, 0) {
    health = generateStat(level, 20, 30);  // ü��: ���� �� 20 ~ 30
    attack = generateStat(level, 5, 10);   // ���ݷ�: ���� �� 5 ~ 10
}

void Slime::interactWithCharacter(Character& character) {
    printIntro();
}

Item* Slime::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion(); // ��� ���� �� ���� ����
    }
    return nullptr; // ��� ����
}

int Slime::getExpReward() const {
    return 50; 
}


