#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"

// Orc Ŭ����: Monster �߻� Ŭ������ ��ӹ��� ��ü���� ���� Ŭ����
class Orc : public Monster {
public:
    // ������: ĳ������ ������ ������� Orc�� ü�°� ���ݷ��� ����
    Orc(int level);

    // ĳ���Ϳ� ��ȣ�ۿ��ϴ� �Լ� (���� ���� �� ȣ���)
    // Monster Ŭ������ ���� ���� �Լ��� �������̵���
    void interactWithCharacter(Character& character) override;
    Item* dropItem() const override;
    // ��� ���� ��ȯ �Լ� 
    int getExpReward() const override;
};
