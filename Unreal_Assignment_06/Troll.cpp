#include "Troll.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "DropItem.h"


Troll::Troll(int level)
    : Monster("Troll", 0, 0) {
    health = generateStat(level, 20, 30);  // ü��: ���� �� 20 ~ 30
    attack = generateStat(level, 5, 10);   // ���ݷ�: ���� �� 5 ~ 10
}


shared_ptr<Item> Troll::dropItem() const {
    if (rand() % 100 < 30) {
        shared_ptr<Item> dropItem = make_shared<DropItem>("Ʈ���� ��", 30);
        return dropItem;
    }
    return nullptr; // ��� ����
}

int Troll::dropExp() const {
    return 50;
}

int Troll::dropGold() const {
    int gold = rand() % 11 + 10;
    return gold;
}
