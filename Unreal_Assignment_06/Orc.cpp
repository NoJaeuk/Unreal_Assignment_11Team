#include "Orc.h"
#include "Character.h"
#include "Item.h"
#include "DropItem.h"

Orc::Orc(int level)
    : Monster("Orc", 0, 0) {
    health = generateStat(level, 20, 30);  // 체력: 레벨 × 20 ~ 30
    attack = generateStat(level, 5, 10);   // 공격력: 레벨 × 5 ~ 10
}



shared_ptr<Item> Orc::dropItem() const {
    if (rand() % 100 < 30) {
        shared_ptr<Item> dropItem = make_shared<DropItem>("나무몽둥이", 20);
        return dropItem;
    }
    return nullptr; // 드랍 실패
}

int Orc::dropExp() const {
    return 50;
}

int Orc::dropGold() const {
    int gold = rand() % 11 + 10;
    return gold;
}