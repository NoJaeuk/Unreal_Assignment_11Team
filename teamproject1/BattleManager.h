#pragma once
#include "Character.h"
#include "Monster.h"

// BattleManager 클래스: 캐릭터와 몬스터 간의 전투를 관리하는 클래스
// 전투의 흐름을 제어하고, 피해 계산, 승패 판정 등을 담당함
class BattleManager {
public:
    // 전투 시작 함수 (정적 메서드)
    // character: 플레이어 캐릭터 객체
    // monster: 전투 대상 몬스터 객체
    // 이 함수는 전투를 진행하고 결과를 출력하거나 게임 상태를 갱신함
    static void startBattle(Character& character, Monster& monster);
};
