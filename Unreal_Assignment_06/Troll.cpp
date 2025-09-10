#include "Troll.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "DropItem.h"


Troll::Troll(int level)
    : Monster("Troll", 0, 0) {
    health = generateStat(level, 20, 30);  // 체력: 레벨 × 20 ~ 30
    attack = generateStat(level, 5, 10);   // 공격력: 레벨 × 5 ~ 10
}


shared_ptr<Item> Troll::dropItem() const {
    if (rand() % 100 < 30) {
        shared_ptr<Item> dropItem = make_shared<DropItem>("트롤의 피", 30);
        return dropItem;
    }
    return nullptr; // 드랍 실패
}

int Troll::dropExp() const {
    return 50;
}

int Troll::dropGold() const {
    int gold = rand() % 11 + 10;
    return gold;
}
