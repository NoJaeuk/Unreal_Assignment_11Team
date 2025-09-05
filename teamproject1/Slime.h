#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"


// Slime Ŭ����: Monster �߻� Ŭ������ ��ӹ��� ��ü���� ���� Ŭ����
class Slime : public Monster {
public:
    // ������: ĳ������ ������ ������� Slime�� ü�°� ���ݷ��� ����
    Slime(int level);

    // ĳ���Ϳ� ��ȣ�ۿ��ϴ� �Լ� (���� ���� �� ȣ���)
    // Monster Ŭ������ ���� ���� �Լ��� �������̵���
    void interactWithCharacter(Character& character) override;
	//������ ��� �Լ�
    Item* dropItem() const override; 
	// ��� ���� ��ȯ �Լ� 
    int getExpReward() const override;

};
