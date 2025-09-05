#pragma once
#include <string>
#include "Character.h"
#include "Item.h"

// Monster 클래스: 모든 몬스터의 공통적인 속성과 기능을 정의하는 추상 클래스

class Monster {
protected:
    std::string name;      //몬스터의 이름
    int health;            // 몬스터의 현재 체력
    int attack;            // 몬스터의 공격력
    // 캐릭터의 레벨과 배율 범위를 기반으로 능력치를 랜덤 생성하는 함수
    int generateStat(int level, int minMultiplier, int maxMultiplier); 


public:
    // 생성자: 몬스터의 이름, 체력, 공격력을 초기화
    Monster(const std::string& name, int health, int attack);

    // 가상 소멸자: 상속받은 클래스에서 안전하게 객체를 삭제할 수 있도록 함
    virtual ~Monster() = default;

    // 순수 가상 함수: 각 몬스터가 캐릭터와 어떻게 상호작용할지 정의해야 함
    // 이 함수는 자식 클래스에서 반드시 구현해야 함
    virtual void interactWithCharacter(Character& character) = 0;

	// 아이템 드랍 순수가상함수
    virtual Item* dropItem() const = 0;

    // 골드 보상 반환 
    virtual int getGoldReward() const = 0;

    // 경험치 보상 반환 
    virtual int getExpReward() const = 0;

    // 몬스터 등장 공통 출력 함수 
    virtual void printIntro() const; 

    // 몬스터가 죽었는지 확인하는 함수 
    bool isDead() const;
    // 몬스터가 피해를 입었을 때 체력을 감소시키는 함수
    virtual void takeDamage(int dmg);


    // 몬스터의 이름을 반환하는 함수
    std::string getName() const;
    // 몬스터의 현재 체력을 반환하는 함수
    int getHealth() const;
    // 몬스터의 공격력을 반환하는 함수
    int getAttack() const;
};
