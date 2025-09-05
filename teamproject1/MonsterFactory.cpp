#include "MonsterFactory.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Slime.h"
#include "BossMonster.h"
#include <cstdlib>   // rand() 함수 사용을 위한 표준 라이브러리

// 몬스터 생성 함수: 캐릭터의 레벨을 기반으로 적절한 몬스터를 생성하여 반환
std::unique_ptr<Monster> MonsterFactory::createMonster(int level) {
    // 캐릭터가 10레벨 이상이면 보스 몬스터를 생성
    if (level >= 10) {
        return std::make_unique<BossMonster>(level); // 보스 몬스터 생성
    }

    // 일반 몬스터 중 하나를 랜덤하게 선택
    int r = rand() % 4; // 0~3 사이의 랜덤 숫자 생성

    // 랜덤 숫자에 따라 몬스터 종류 결정
    switch (r) {
    case 0: return std::make_unique<Goblin>(level); // 고블린 생성
    case 1: return std::make_unique<Orc>(level);    // 오크 생성
    case 2: return std::make_unique<Troll>(level);  // 트롤 생성
    case 3: return std::make_unique<Slime>(level);  // 슬라임 생성
    }

    // 예외 상황: 랜덤 값이 범위를 벗어날 경우 nullptr 반환 (실제로는 발생하지 않음)
    return nullptr;
}
