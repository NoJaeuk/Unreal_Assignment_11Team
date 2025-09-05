#pragma once
#include "Monster.h"
#include "Character.h"
#include "Item.h"


// Slime 클래스: Monster 추상 클래스를 상속받은 구체적인 몬스터 클래스
class Slime : public Monster {
public:
    // 생성자: 캐릭터의 레벨을 기반으로 Slime의 체력과 공격력을 설정
    Slime(int level);

    // 캐릭터와 상호작용하는 함수 (전투 시작 시 호출됨)
    // Monster 클래스의 순수 가상 함수를 오버라이딩함
    void interactWithCharacter(Character& character) override;
	//아이템 드랍 함수
    Item* dropItem() const override; 
	// 골드 보상 반환 함수 
    int getExpReward() const override;

};
