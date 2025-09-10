#include "Goblin.h"
#include "Character.h"
#include "Item.h"
#include "DropItem.h"


// Goblin 생성자: 캐릭터의 레벨을 기반으로 Goblin의 체력과 공격력을 랜덤하게 설정
Goblin::Goblin(int level)
    : Monster("Goblin", 0, 0) {
    health = generateStat(level, 20, 30);  // 체력: 레벨 × 20 ~ 30
    attack = generateStat(level, 5, 10);   // 공격력: 레벨 × 5 ~ 10
}


shared_ptr<Item> Goblin::dropItem() const {
    if (rand() % 100 < 30) {
        shared_ptr<Item> dropItem = make_shared<DropItem>("천조각", 10);
        return dropItem;
    }
    return nullptr; // 드랍 실패
}

int Goblin::dropExp() const {
    return 50;
}

int Goblin::dropGold() const {
    int gold = rand() % 11 + 10;
    return gold;
}