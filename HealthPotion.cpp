#include "HealthPotion.h"
#include <iostream>
using namespace std;

HealthPotion::HealthPotion(int heal) : healAmount(heal) {} // 회복량 초기화

std::string HealthPotion::GetName() const 
{
    return "Health Potion"; // 아이템 이름 반환
}

void HealthPotion::Use(Character& character) 
{
    character.Heal(healAmount); // 캐릭터 체력 회복

    cout << "체력 포션 사용! HP가 " << healAmount << " 회복되었습니다." << endl;
}
