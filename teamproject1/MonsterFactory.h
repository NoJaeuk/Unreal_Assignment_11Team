#pragma once
#include <memory> // std::unique_ptr ����� ���� ��� (���� ��ü ����)
#include <string>
#include "Monster.h"

// MonsterFactory Ŭ����: ���� ��ü�� �����ϴ� ���丮 Ŭ����
// ĳ������ ������ ������� ������ ���͸� �����ϰ� �����Ͽ� ��ȯ��
class MonsterFactory {
public:
    // ���� ���� �Լ� (���� �޼���)
	// ����Ʈ �����͸� ����Ͽ� ���� �޸� ������ �ڵ�ȭ
    // level: ĳ������ ���� ����
    // ��ȯ��: Monster�� ��ӹ��� ���� ��ü�� unique_ptr�� ��ȯ
    // ������ 10 �̻��̸� BossMonster�� �����ϰ�, �׷��� ������ �Ϲ� ���� �� �ϳ��� ���� ����
    static std::unique_ptr<Monster> createMonster(int level);
};
