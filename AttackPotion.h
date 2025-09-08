#pragma once
#include "Item.h"
// 공격력 증가 아이템 클래스

class AttackPotion : public Item 
{
private:
    int boostAmount; // 증가할 공격력 수치

public:
    AttackPotion(int boost);// 생성자 (증가량 설정)
    std::string GetName() const override; // 이름 반환
    void Use(Character& character) override; // 캐릭터에게 효과 적용
};
