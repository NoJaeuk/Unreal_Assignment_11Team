#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Items.h"
#include "Inventory.h"

Shop::Shop()
{
    // availableItems에 판매용 아이템 추가
}

void Shop::shopOpen()
{
    std::cout << "어서 오세요. 상점에 오신 것을 환영합니다." << std::endl;

    while (true)
    {
        int select = 0;
        std::cout << "선택지를 골라 주세요." << std::endl;
        std::cout << "1. 아이템 구매." << std::endl;
        std::cout << "2. 아이템 판매." << std::endl;
        std::cout << "3. 랜덤 뽑기." << std::endl;
        std::cout << "0. 상점 나가기." << std::endl;
        std::cin >> select;

        switch (select)
        {
        case 1:
            std::cout << "아이템 구매를 선택했습니다." << std::endl;
            buyItem();
            break;

        case 2:
            std::cout << "아이템 판매를 선택했습니다." << std::endl;
            sellItem();
            break;

        case 3:
            std::cout << "아이템 랜덤뽑기를 선택했습니다." << std::endl;
            randomPick();
            break;

        case 0:
            std::cout << "상점에서 나갑니다." << std::endl;
            return;
        }
    }

}

void addItem(std::string name, int price)
{
    ShopItem shopItem;
    shopItem.item = std::make_shared<Item>(name, price);
    shopItem.count = 1;

    availableItems.push_back(shopItem);
}

void Shop::displayItems()
{
    std::cout << "판매중인 아이템 리스트" << std::endl;
    
    for (auto* item : availableItems)
    {
      
    }
}


void Shop::sellItem()
{
    displayItems();

}


void Shop::buyItem(const std::string& name, Character* character)
{
    Items* item = character->findItem(name);
    if (item == nullptr)
    {
        cout << "해당 아이템이 없습니다." << endl;
        return;
    }

    int price = item->getprice();
    character->setGold(character->getGold() + price);
    character->removeItem(name);
}



void Shop::randomPick()
{
    std::cout << "랜덤 뽑기 시작." << std::endl;
}




/*


    - 상점에서는 골드로 아이템을 구매/판매 가능(아이템 목록은 자유롭게!)
        - 아이템 구매
            - 플레이어는 골드를 사용해서 아이템을 구매
            - 구매 아이템은 인벤토리에 즉시 추가
        - 아이템 판매
            - 플레이어는 보유한 아이템을 골드로 판매 **(판매 가격은 구입 원가의 60%!)**
            - 판매된 아이템은 인벤토리에서 즉시 제거
    - “체력 물약 10 Gold”, “공격력 강화 15 Gold”처럼 가격을 정해놓기!
    - 구매 즉시 인벤토리에 들어오며, 판매 시 아이템이 소멸되고 골드 획득!
    - 즉, 상점 시스템을 추가한다는 것은 곧 인벤토리도 있어야겠네요?
        - 캐릭터 클래스의 멤버 변수를 참고해보세요!

*/