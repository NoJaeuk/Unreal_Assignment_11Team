#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"


// Goblin Ŭ����: Monster �߻� Ŭ������ ��ӹ��� ��ü���� ���� Ŭ����
class Goblin : public Monster {
public:
    // ������: ĳ������ ������ ������� Goblin�� ü�°� ���ݷ��� ����
    Goblin(int level);

    // ĳ���Ϳ� ��ȣ�ۿ��ϴ� �Լ� (���� ���� �� ȣ���)
    // Monster Ŭ������ ���� ���� �Լ��� �������̵���
    void interactWithCharacter(Character& character) override;
    Item* dropItem() const override;
    // ��� ���� ��ȯ �Լ� 
    int getExpReward() const override;
};
