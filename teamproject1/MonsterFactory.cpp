#include "MonsterFactory.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Slime.h"
#include "BossMonster.h"
#include <cstdlib>   // rand() �Լ� ����� ���� ǥ�� ���̺귯��

// ���� ���� �Լ�: ĳ������ ������ ������� ������ ���͸� �����Ͽ� ��ȯ
std::unique_ptr<Monster> MonsterFactory::createMonster(int level) {
    // ĳ���Ͱ� 10���� �̻��̸� ���� ���͸� ����
    if (level >= 10) {
        return std::make_unique<BossMonster>(level); // ���� ���� ����
    }

    // �Ϲ� ���� �� �ϳ��� �����ϰ� ����
    int r = rand() % 4; // 0~3 ������ ���� ���� ����

    // ���� ���ڿ� ���� ���� ���� ����
    switch (r) {
    case 0: return std::make_unique<Goblin>(level); // ��� ����
    case 1: return std::make_unique<Orc>(level);    // ��ũ ����
    case 2: return std::make_unique<Troll>(level);  // Ʈ�� ����
    case 3: return std::make_unique<Slime>(level);  // ������ ����
    }

    // ���� ��Ȳ: ���� ���� ������ ��� ��� nullptr ��ȯ (�����δ� �߻����� ����)
    return nullptr;
}
