#include "AttackPotion.h"

#include <iostream>
using namespace std;

AttackPotion::AttackPotion(int boost) : boostAmount(boost) {} // 증가량 초기화

std::string AttackPotion::GetName() const 
{
    return "Attack Boost"; // 아이템 이름 반환
}

void AttackPotion::Use(Character& character) {
    character.IncreaseAttack(boostAmount); // 캐릭터 공격력 증가
    cout << "공격력 증가 아이템 사용! 공격력이 " << boostAmount << " 올랐습니다." << endl;
}



