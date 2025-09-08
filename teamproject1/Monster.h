#pragma once
#include <string>
#include "Character.h"
#include "Item.h"

class Monster {
public:
    virtual ~Monster() = default;

    // ��� ����� ���� ���� �Լ��� ����
    virtual void interactWithCharacter(Character& character) = 0;
    virtual Item* dropItem() const = 0;
    virtual int getGoldReward() const = 0;
    virtual int getExpReward() const = 0;
    virtual void printIntro() const = 0;
    virtual bool isDead() const = 0;
    virtual void takeDamage(int dmg) = 0;

    virtual std::string getName() const = 0;
    virtual int getHealth() const = 0;
    virtual int getAttack() const = 0;
};

