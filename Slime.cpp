#include "Slime.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "DropItem.h"

Slime::Slime(int level)
    : Monster("Slime", 0, 0) {
    health = generateStat(level, 20, 30);  // ü��: ���� �� 20 ~ 30
    attack = generateStat(level, 5, 10);   // ���ݷ�: ���� �� 5 ~ 10
}



shared_ptr<Item> Slime::dropItem() const {
    if (rand() % 100 < 30) {
        shared_ptr<Item> dropItem = make_shared<DropItem>("����������", 15);
        return dropItem;
    }
    return nullptr; // ��� ����
}

int Slime::dropExp() const {
    return 50;
}

int Slime::dropGold() const {
    int gold = rand() % 11 + 10;
    return gold;
}