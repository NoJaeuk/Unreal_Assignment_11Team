#include "Goblin.h"
#include "Character.h"
#include "Item.h"
#include "DropItem.h"


// Goblin ������: ĳ������ ������ ������� Goblin�� ü�°� ���ݷ��� �����ϰ� ����
Goblin::Goblin(int level)
    : Monster("Goblin", 0, 0) {
    health = generateStat(level, 20, 30);  // ü��: ���� �� 20 ~ 30
    attack = generateStat(level, 5, 10);   // ���ݷ�: ���� �� 5 ~ 10
}


shared_ptr<Item> Goblin::dropItem() const {
    if (rand() % 100 < 30) {
        shared_ptr<Item> dropItem = make_shared<DropItem>("õ����", 10);
        return dropItem;
    }
    return nullptr; // ��� ����
}

int Goblin::dropExp() const {
    return 50;
}

int Goblin::dropGold() const {
    int gold = rand() % 11 + 10;
    return gold;
}