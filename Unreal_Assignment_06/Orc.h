#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"

class Orc : public Monster {
public:
    // 생성자: 캐릭터의 레벨을 기반으로 Orc의 체력과 공격력을 설정
    Orc(int level);

    // 캐릭터와 상호작용하는 함수 (전투 시작 시 호출됨)

    shared_ptr<Item> dropItem() const override;
    int dropExp() const override;
    int dropGold() const override;

};