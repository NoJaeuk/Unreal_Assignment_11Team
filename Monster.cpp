#include "Monster.h"
#include <iostream>

// Monster 클래스의 생성자: 이름, 체력, 공격력을 초기화
Monster::Monster(const std::string& name, int health, int attack)
    : name(name), health(health), attack(attack) {
    // 멤버 변수 초기화 리스트를 사용해 효율적으로 값 설정
    std::cout << this->getName() << " 이(가) 나타났다!\n";
}


int Monster::generateStat(int level, int minMultiplier, int maxMultiplier) {
    int min = level * minMultiplier;
    int max = level * maxMultiplier;
    return rand() % (max - min + 1) + min;
}

// 몬스터 등장 공통 출력 함수 선언
void Monster::printIntro() const {
    std::cout << name << "이 등장했습니다! 체력: " << health << ", 공격력: " << attack << "\n";
}


// 몬스터가 피해를 입었을 때 체력을 감소시키는 함수
// 음수 체력이 되지 않도록 0으로 고정
void Monster::takeDamage(int dmg) { //dmg는 캐릭터의 공격력
    health -= dmg;
    if (health < 0) health = 0;
}

// 몬스터의 이름을 반환하는 함수
std::string Monster::getName() const {
    return name;
}

// 몬스터의 현재 체력을 반환하는 함수
int Monster::getHealth() const {
    return health;
}

// 몬스터의 공격력을 반환하는 함수
int Monster::getAttack() const {
    return attack;
}