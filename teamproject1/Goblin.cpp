#include "Goblin.h"
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "ItemFactory.h"


// Goblin 생성자: 캐릭터의 레벨을 기반으로 Goblin의 체력과 공격력을 랜덤하게 설정
Goblin::Goblin(int level)
    : Monster("Goblin", 0, 0) {
    health = generateStat(level, 20, 30);  // 체력: 레벨 × 20 ~ 30
    attack = generateStat(level, 5, 10);   // 공격력: 레벨 × 5 ~ 10
}


// 캐릭터와의 상호작용 함수: Goblin이 등장했을 때 콘솔에 상태를 출력
void Goblin::interactWithCharacter(Character& character) {
    printIntro();
}

Item* Goblin::dropItem() const {
    if (rand() % 100 < 30) {
        return ItemFactory::createPotion(); // 드랍 성공 시 포션 생성
    }
    return nullptr; // 드랍 실패
}

int Goblin::getExpReward() const {
    return 50; 
}
