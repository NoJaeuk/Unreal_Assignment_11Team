#pragma once  

#include "Monster.h"  
#include "Character.h"

// BossMonster 클래스: 게임의 최종 보스 몬스터를 정의하는 클래스
// Monster 추상 클래스를 상속받아 체력, 공격력, 전투 방식 등을 구현함
class BossMonster : public Monster {
public:
    // 생성자: 캐릭터의 레벨을 기반으로 보스 몬스터의 능력치를 설정
    // 일반 몬스터보다 더 높은 배율로 체력과 공격력이 설정됨
    BossMonster(int level);

    shared_ptr<Item> dropItem() const override;
    int dropExp() const override;
    int dropGold() const override;

};