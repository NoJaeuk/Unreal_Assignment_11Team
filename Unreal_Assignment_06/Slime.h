#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"


// Slime 클래스: Monster 추상 클래스를 상속받은 구체적인 몬스터 클래스
class Slime : public Monster {
public:
    // 생성자: 캐릭터의 레벨을 기반으로 Slime의 체력과 공격력을 설정
    Slime(int level);

    //아이템 드랍 함수
    shared_ptr<Item> dropItem() const override;
    int dropExp() const override;
    int dropGold() const override;


};