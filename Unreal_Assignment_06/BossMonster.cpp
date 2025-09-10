#include "BossMonster.h"
#include <iostream>
#include "Character.h"


// BossMonster 생성자: 캐릭터의 레벨을 기반으로 보스 몬스터의 체력과 공격력을 설정
BossMonster::BossMonster(int level)
    : Monster("Dragon", 0, 0)
{       //몬스터 이름 설정
        // 일반 몬스터보다 1.5배 높은 배율 적용
    health = generateStat(level, 30, 45);  // 체력: 레벨 × 30 ~ 45
    attack = generateStat(level, 7, 15);   // 공격력:레벨 × 7 ~ 15

}

shared_ptr<Item> BossMonster::dropItem() const { return nullptr; }
int BossMonster::dropExp() const { return 0; }
int BossMonster::dropGold() const { return 0; }