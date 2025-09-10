#include "BossMonster.h"
#include <iostream>
#include "Character.h"


// BossMonster ������: ĳ������ ������ ������� ���� ������ ü�°� ���ݷ��� ����
BossMonster::BossMonster(int level)
    : Monster("Dragon", 0, 0)
{       //���� �̸� ����
        // �Ϲ� ���ͺ��� 1.5�� ���� ���� ����
    health = generateStat(level, 30, 45);  // ü��: ���� �� 30 ~ 45
    attack = generateStat(level, 7, 15);   // ���ݷ�:���� �� 7 ~ 15

}

shared_ptr<Item> BossMonster::dropItem() const { return nullptr; }
int BossMonster::dropExp() const { return 0; }
int BossMonster::dropGold() const { return 0; }