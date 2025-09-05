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

    // 캐릭터와 상호작용하는 함수 (전투 시작 시 호출됨)
    // Monster 클래스의 순수 가상 함수를 오버라이딩함
    // 보스 몬스터의 등장 메시지를 출력하거나 특수 행동을 정의할 수 있음
    void interactWithCharacter(Character& character) override;
};
