#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"


// Troll Ŭ���� : Monster �߻� Ŭ������ ��ӹ��� ��ü���� ���� Ŭ����
class Troll : public Monster {
public:
    // ������: ĳ������ ������ ������� Troll�� ü�°� ���ݷ��� ����
    Troll(int level);

    shared_ptr<Item> dropItem() const override;
    int dropExp() const override;
    int dropGold() const override;
};