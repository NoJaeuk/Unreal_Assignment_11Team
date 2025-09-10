#pragma once  

#include "Monster.h"  
#include "Character.h"

// BossMonster Ŭ����: ������ ���� ���� ���͸� �����ϴ� Ŭ����
// Monster �߻� Ŭ������ ��ӹ޾� ü��, ���ݷ�, ���� ��� ���� ������
class BossMonster : public Monster {
public:
    // ������: ĳ������ ������ ������� ���� ������ �ɷ�ġ�� ����
    // �Ϲ� ���ͺ��� �� ���� ������ ü�°� ���ݷ��� ������
    BossMonster(int level);

    shared_ptr<Item> dropItem() const override;
    int dropExp() const override;
    int dropGold() const override;

};