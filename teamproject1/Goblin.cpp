#include "Goblin.h"
#include "ItemFactory.h"
#include <iostream>
#include <cstdlib>

Goblin::Goblin(int level)
    : name("Goblin"), health(generateStat(level, 20, 30)), attack(generateStat(level, 5, 10)) {
}

int Goblin::generateStat(int level, int minMultiplier, int maxMultiplier) {
    int min = level * minMultiplier;
    int max = level * maxMultiplier;
    return rand() % (max - min + 1) + min;
}


Item* Goblin::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion();
    }
    return nullptr;
}

int Goblin::getGoldReward() const {
    return 20;
}

int Goblin::getExpReward() const {
    return 50;
}

void Goblin::printIntro() const {
    std::cout << name << "이 등장했습니다! 체력: " << health << ", 공격력: " << attack << "\n";
}

bool Goblin::isDead() const {
    return health <= 0;
}

void Goblin::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}

std::string Goblin::getName() const {
    return name;
}

int Goblin::getHealth() const {
    return health;
}

int Goblin::getAttack() const {
    return attack;
}