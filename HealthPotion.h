#pragma once
#include "Item.h"
// 체력 회복 아이템 클래스
class HealthPotion : public Item 
{
private:
    int healAmount; // 회복량

public:
    HealthPotion(int heal);// 생성자 (회복량 설정)
    std::string GetName() const override; // 이름 반환
    void Use(Character& character) override; // 캐릭터에게 효과 적용
};
