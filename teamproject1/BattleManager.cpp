#include "BattleManager.h"
#include "BossMonster.h"
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>      // rand() 함수 사용을 위한 표준 라이브러리

// 전투 시작 함수: 캐릭터와 몬스터 간의 전투를 진행하고 결과를 처리함
void BattleManager::startBattle(Character& character, Monster& monster) {
    // 몬스터 등장 메시지 출력
    std::cout << "몬스터 " << monster.getName() << " 등장! 체력: "
        << monster.getHealth() << ", 공격력: " << monster.getAttack() << "\n";

    // 전투 루프: 둘 중 하나가 죽을 때까지 반복
    while (!monster.isDead() && !character.isDead()) {
        // 캐릭터 공격
        std::cout << character.getName() << "가 " << monster.getName() << "을 공격합니다!\n";
        monster.takeDamage(character.getAttack());// 몬스터 체력 감소
        std::cout << monster.getName() << " 체력: " << monster.getHealth() << "\n";

        // 몬스터가 죽었으면 루프 종료
        if (monster.isDead()) break;

        // 몬스터 공격
        std::cout << monster.getName() << "이 " << character.getName() << "을 공격합니다!\n";
        character.takeDamage(monster.getAttack());
        std::cout << character.getName() << " 체력: " << character.getHealth() << "\n";

        // 아이템 랜덤 사용
        if (character.shouldUseItem()) {
            std::cout << "이럴 때 아이템!\n";
            character.useRandomItem(); // 아이템 사용 (아이템 담당자 구현 필요)
        }

    }

    // 몬스터 처치 시 보상 처리
    if (monster.isDead()) {
        int exp = monster.getExpReward();     // 몬스터가 주는 경험치
        int gold = monster.getGoldReward();   // 몬스터가 주는 골드

        character.addExp(exp);                // 캐릭터가 경험치 획득
        character.addGold(gold);              // 캐릭터가 골드 획득

        std::cout << character.getName() << "가 "
            << exp << " EXP와 "
            << gold << " 골드를 획득했습니다.\n";

        // 아이템 드랍 처리
        Item* item = monster.dropItem();
        if (item != nullptr) {
            character.obtainItem(item);
        }

        // 레벨업 체크
		if (character.canLevelUp()) { //캐릭터 레벨업 가능 구현 필요
            character.levelUp();
        }

        // 보스 몬스터 처치 시 게임 클리어 메시지 출력
        //monster가 BossMonster타입이 아닐 경우 nullptr 반환
		//monster가 BossMonster타입일 경우 BossMonster* 타입 반환
		if (character.getLevel() >= 10 && dynamic_cast<BossMonster*>(&monster) != nullptr) { 
            std::cout << "축하합니다! 보스"<<monster.getName()<<"를 처치하고 게임을 클리어했습니다!\n";
        }
    }

    // 캐릭터가 죽었을 경우 게임 오버 처리
    else {
        std::cout << character.getName() << "가 사망했습니다. 게임 오버!\n";
    }
}
