#pragma once
#include "Character.h"
#include "Monster.h"

// BattleManager Ŭ����: ĳ���Ϳ� ���� ���� ������ �����ϴ� Ŭ����
// ������ �帧�� �����ϰ�, ���� ���, ���� ���� ���� �����
class BattleManager {
public:
    // ���� ���� �Լ� (���� �޼���)
    // character: �÷��̾� ĳ���� ��ü
    // monster: ���� ��� ���� ��ü
    // �� �Լ��� ������ �����ϰ� ����� ����ϰų� ���� ���¸� ������
    static void startBattle(Character& character, Monster& monster);
};
