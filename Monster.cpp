#include "Monster.h"
#include <iostream>

// Monster Ŭ������ ������: �̸�, ü��, ���ݷ��� �ʱ�ȭ
Monster::Monster(const std::string& name, int health, int attack)
    : name(name), health(health), attack(attack) {
    // ��� ���� �ʱ�ȭ ����Ʈ�� ����� ȿ�������� �� ����
    std::cout << this->getName() << " ��(��) ��Ÿ����!\n";
}


int Monster::generateStat(int level, int minMultiplier, int maxMultiplier) {
    int min = level * minMultiplier;
    int max = level * maxMultiplier;
    return rand() % (max - min + 1) + min;
}

// ���� ���� ���� ��� �Լ� ����
void Monster::printIntro() const {
    std::cout << name << "�� �����߽��ϴ�! ü��: " << health << ", ���ݷ�: " << attack << "\n";
}


// ���Ͱ� ���ظ� �Ծ��� �� ü���� ���ҽ�Ű�� �Լ�
// ���� ü���� ���� �ʵ��� 0���� ����
void Monster::takeDamage(int dmg) { //dmg�� ĳ������ ���ݷ�
    health -= dmg;
    if (health < 0) health = 0;
}

// ������ �̸��� ��ȯ�ϴ� �Լ�
std::string Monster::getName() const {
    return name;
}

// ������ ���� ü���� ��ȯ�ϴ� �Լ�
int Monster::getHealth() const {
    return health;
}

// ������ ���ݷ��� ��ȯ�ϴ� �Լ�
int Monster::getAttack() const {
    return attack;
}