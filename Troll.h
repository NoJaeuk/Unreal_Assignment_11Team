#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"


// Troll 클래스 : Monster 추상 클래스를 상속받은 구체적인 몬스터 클래스
class Troll : public Monster {
public:
    // 생성자: 캐릭터의 레벨을 기반으로 Troll의 체력과 공격력을 설정
    Troll(int level);

    shared_ptr<Item> dropItem() const override;
    int dropExp() const override;
    int dropGold() const override;
};