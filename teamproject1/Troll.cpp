#include "Troll.h"
#include "ItemFactory.h"
#include <iostream>
#include <cstdlib>

Troll::Troll(int level)
    : name("Goblin"), health(generateStat(level, 20, 30)), attack(generateStat(level, 5, 10)) {
}

int Troll::generateStat(int level, int minMultiplier, int maxMultiplier) {
    int min = level * minMultiplier;
    int max = level * maxMultiplier;
    return rand() % (max - min + 1) + min;
}


Item* Troll::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion();
    }
    return nullptr;
}

int Troll::getGoldReward() const {
    return 20;
}

int Troll::getExpReward() const {
    return 50;
}

void Troll::printIntro() const {
    std::cout << name << "이 등장했습니다! 체력: " << health << ", 공격력: " << attack << "\n";
}

bool Troll::isDead() const {
    return health <= 0;
}

void Troll::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}

std::string Troll::getName() const {
    return name;
}

int Troll::getHealth() const {
    return health;
}

int Troll::getAttack() const {
    return attack;
}