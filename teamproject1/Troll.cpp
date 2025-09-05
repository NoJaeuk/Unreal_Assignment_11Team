#include "Troll.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "ItemFactory.h"


Troll::Troll(int level)
    : Monster("Troll", 0, 0) {
    health = generateStat(level, 20, 30);  // ü��: ���� �� 20 ~ 30
    attack = generateStat(level, 5, 10);   // ���ݷ�: ���� �� 5 ~ 10
}


void Troll::interactWithCharacter(Character& character) {
    printIntro();
}


Item* Troll::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion(); // ��� ���� �� ���� ����
    }
    return nullptr; // ��� ����
}

int Troll::getExpReward() const {
    return 50; 
}

