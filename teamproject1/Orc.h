#pragma once
#include "Monster.h"

class Orc : public Monster {
private:
    std::string name;
    int health;
    int attack;

public:
    Orc(int level);

    void interactWithCharacter(Character& character) override;
    Item* dropItem() const override;
    int getGoldReward() const override;
    int getExpReward() const override;
    void printIntro() const override;
    bool isDead() const override;
    void takeDamage(int dmg) override;

    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;

private:
    int generateStat(int level, int minMultiplier, int maxMultiplier);
};

