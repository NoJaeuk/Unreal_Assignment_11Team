#include "Inventory.h"
#include "HealthPotion.h"
#include "AttackPotion.h"
#include <memory>

using namespace std;

int main() {
  

    // 인벤토리 생성
    Inventory inventory;

    // 아이템 추가
    inventory.AddItem(make_shared<HealthPotion>(50), 2); // 체력포션 2개
    inventory.AddItem(make_shared<AttackPotion>(5), 1);   // 공격력 증가 아이템 1개

    // 현재 상태 출력
    Character.ShowStatus();
    inventory.ShowItems();

    // 아이템 사용
    inventory.UseItem(0, Character); // 첫 번째 아이템(체력포션) 사용
    Character.ShowStatus();
    inventory.ShowItems();

    inventory.UseItem(0, Character); // 또 사용 (체력포션 남은 1개 사용)
    Character.ShowStatus();
    inventory.ShowItems();

    return 0;
}
