#include "Orc.h"
#include "Character.h"
#include "Item.h"
#include "DropItem.h"

Orc::Orc(int level)
    : Monster("Orc", 0, 0) {
    health = generateStat(level, 20, 30);  // ü��: ���� �� 20 ~ 30
    attack = generateStat(level, 5, 10);   // ���ݷ�: ���� �� 5 ~ 10
}



shared_ptr<Item> Orc::dropItem() const {
    if (rand() % 100 < 30) {
        shared_ptr<Item> dropItem = make_shared<DropItem>("����������", 20);
        return dropItem;
    }
    return nullptr; // ��� ����
}

int Orc::dropExp() const {
    return 50;
}

int Orc::dropGold() const {
    int gold = rand() % 11 + 10;
    return gold;
}