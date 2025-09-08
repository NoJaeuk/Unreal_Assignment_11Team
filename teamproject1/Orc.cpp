#include "Orc.h"
#include "ItemFactory.h"
#include <iostream>
#include <cstdlib>

Orc::Orc(int level)
    : name("Goblin"), health(generateStat(level, 20, 30)), attack(generateStat(level, 5, 10)) {
}

int Orc::generateStat(int level, int minMultiplier, int maxMultiplier) {
    int min = level * minMultiplier;
    int max = level * maxMultiplier;
    return rand() % (max - min + 1) + min;
}


Item* Orc::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion();
    }
    return nullptr;
}

int Orc::getGoldReward() const {
    return 20;
}

int Orc::getExpReward() const {
    return 50;
}

void Orc::printIntro() const {
    std::cout << name << "이 등장했습니다! 체력: " << health << ", 공격력: " << attack << "\n";
}

bool Orc::isDead() const {
    return health <= 0;
}

void Orc::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}

std::string Orc::getName() const {
    return name;
}

int Orc::getHealth() const {
    return health;
}

int Orc::getAttack() const {
    return attack;
}