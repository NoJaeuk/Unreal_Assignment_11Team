#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"


// Slime Ŭ����: Monster �߻� Ŭ������ ��ӹ��� ��ü���� ���� Ŭ����
class Slime : public Monster {
public:
    // ������: ĳ������ ������ ������� Slime�� ü�°� ���ݷ��� ����
    Slime(int level);

    //������ ��� �Լ�
    shared_ptr<Item> dropItem() const override;
    int dropExp() const override;
    int dropGold() const override;


};