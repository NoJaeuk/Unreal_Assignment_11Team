#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"


// Troll Ŭ���� : Monster �߻� Ŭ������ ��ӹ��� ��ü���� ���� Ŭ����
class Troll : public Monster {
public:
    // ������: ĳ������ ������ ������� Troll�� ü�°� ���ݷ��� ����
    Troll(int level);

    // ĳ���Ϳ� ��ȣ�ۿ��ϴ� �Լ� (���� ���� �� ȣ���)
    // Monster Ŭ������ ���� ���� �Լ��� �������̵���
    void interactWithCharacter(Character& character) override;
	Item* dropItem() const override;
    // ��� ���� ��ȯ �Լ� 
    int getExpReward() const override;
};
