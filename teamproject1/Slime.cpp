#include "Slime.h"
#include "ItemFactory.h"
#include <iostream>
#include <cstdlib>

Slime::Slime(int level)
    : name("Goblin"), health(generateStat(level, 20, 30)), attack(generateStat(level, 5, 10)) {
}

int Slime::generateStat(int level, int minMultiplier, int maxMultiplier) {
    int min = level * minMultiplier;
    int max = level * maxMultiplier;
    return rand() % (max - min + 1) + min;
}


Item* Slime::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion();
    }
    return nullptr;
}

int Slime::getGoldReward() const {
    return 20;
}

int Slime::getExpReward() const {
    return 50;
}

void Slime::printIntro() const {
    std::cout << name << "이 등장했습니다! 체력: " << health << ", 공격력: " << attack << "\n";
}

bool Slime::isDead() const {
    return health <= 0;
}

void Slime::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}

std::string Slime::getName() const {
    return name;
}

int Slime::getHealth() const {
    return health;
}

int Slime::getAttack() const {
    return attack;
}
