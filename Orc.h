#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"

class Orc : public Monster {
public:
    // ������: ĳ������ ������ ������� Orc�� ü�°� ���ݷ��� ����
    Orc(int level);

    // ĳ���Ϳ� ��ȣ�ۿ��ϴ� �Լ� (���� ���� �� ȣ���)

    shared_ptr<Item> dropItem() const override;
    int dropExp() const override;
    int dropGold() const override;

};