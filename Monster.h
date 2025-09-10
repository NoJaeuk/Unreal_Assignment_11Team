#pragma once
#include <string>
#include "Character.h"
#include "Item.h"

// Monster Ŭ����: ��� ������ �������� �Ӽ��� ����� �����ϴ� �߻� Ŭ����

class Monster {
protected:
    std::string name;      //������ �̸�
    int health;            // ������ ���� ü��
    int attack;            // ������ ���ݷ�
    // ĳ������ ������ ���� ������ ������� �ɷ�ġ�� ���� �����ϴ� �Լ�
    int generateStat(int level, int minMultiplier, int maxMultiplier);


public:
    // ������: ������ �̸�, ü��, ���ݷ��� �ʱ�ȭ
    Monster(const std::string& name, int health, int attack);

    // ���� �Ҹ���: ��ӹ��� Ŭ�������� �����ϰ� ��ü�� ������ �� �ֵ��� ��
    virtual ~Monster() = default;

    // ������ ��� ���������Լ�
    virtual shared_ptr<Item> dropItem() const = 0;
    virtual int dropExp() const = 0;
    virtual int dropGold() const = 0;

    // ���� ���� ���� ��� �Լ� 
    virtual void printIntro() const;

    // ���Ͱ� ���ظ� �Ծ��� �� ü���� ���ҽ�Ű�� �Լ�
    virtual void takeDamage(int dmg);


    // ������ �̸��� ��ȯ�ϴ� �Լ�
    std::string getName() const;
    // ������ ���� ü���� ��ȯ�ϴ� �Լ�
    int getHealth() const;
    // ������ ���ݷ��� ��ȯ�ϴ� �Լ�
    int getAttack() const;
};
