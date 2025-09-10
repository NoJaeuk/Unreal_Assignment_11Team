#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"


// Goblin Ŭ����: Monster �߻� Ŭ������ ��ӹ��� ��ü���� ���� Ŭ����
class Goblin : public Monster {
public:
    // ������: ĳ������ ������ ������� Goblin�� ü�°� ���ݷ��� ����
    Goblin(int level);

    shared_ptr<Item> dropItem() const override;
    int dropExp() const override;
    int dropGold() const override;
};
