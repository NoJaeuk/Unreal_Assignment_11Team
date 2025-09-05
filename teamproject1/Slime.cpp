#include "Slime.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "ItemFactory.h"


Slime::Slime(int level)
    : Monster("Slime", 0, 0) {
    health = generateStat(level, 20, 30);  // 체력: 레벨 × 20 ~ 30
    attack = generateStat(level, 5, 10);   // 공격력: 레벨 × 5 ~ 10
}

void Slime::interactWithCharacter(Character& character) {
    printIntro();
}

Item* Slime::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion(); // 드랍 성공 시 포션 생성
    }
    return nullptr; // 드랍 실패
}

int Slime::getExpReward() const {
    return 50; 
}


