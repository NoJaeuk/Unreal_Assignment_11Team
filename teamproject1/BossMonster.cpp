#include "BossMonster.h"
#include <iostream>
#include "Character.h"


// BossMonster 생성자: 캐릭터의 레벨을 기반으로 보스 몬스터의 체력과 공격력을 설정
BossMonster::BossMonster(int level)
    : Monster("Dragon",0,0) 
{       //몬스터 이름 설정
        // 일반 몬스터보다 1.5배 높은 배율 적용
        health = generateStat(level, 30, 45);  // 체력: 레벨 × 30 ~ 45
        attack = generateStat(level, 7, 15);   // 공격력:레벨 × 7 ~ 15

}


// 캐릭터와의 상호작용 함수: 보스 몬스터가 등장했을 때 콘솔에 상태를 출력
void BossMonster::interactWithCharacter(Character& character) {
	std::cout << "경고! 보스몬스터 "; // 보스 몬스터 전용 등장 메시지
    printIntro(); // Monster 클래스의 공통 출력 함수 호출
}
