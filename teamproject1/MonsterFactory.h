#pragma once
#include <memory> // std::unique_ptr 사용을 위한 헤더 (동적 객체 관리)
#include <string>
#include "Monster.h"

// MonsterFactory 클래스: 몬스터 객체를 생성하는 팩토리 클래스
// 캐릭터의 레벨을 기반으로 적절한 몬스터를 랜덤하게 생성하여 반환함
class MonsterFactory {
public:
    // 몬스터 생성 함수 (정적 메서드)
	// 스마트 포인터를 사용하여 동적 메모리 관리를 자동화
    // level: 캐릭터의 현재 레벨
    // 반환값: Monster를 상속받은 몬스터 객체를 unique_ptr로 반환
    // 레벨이 10 이상이면 BossMonster를 생성하고, 그렇지 않으면 일반 몬스터 중 하나를 랜덤 생성
    static std::unique_ptr<Monster> createMonster(int level);
};
