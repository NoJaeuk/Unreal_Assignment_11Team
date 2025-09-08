#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Items.h"

Shop::Shop()
{
    // 그냥 초기화만
}

void Shop::addItem(std::shared_ptr<Item> item, int count) //게임메니저에서 샵으로 가판대 아이템 리스트 보냄
{
    ShopItem shopItem; // 스트럭트 타입의 인스턴스
    shopItem.item_ = item; // 받은 아이템 타입을 스트럭트에 넣음
    shopItem.count_ = count; // 같은 종류의 아이템 갯수 세기

    availableItems_.push_back(shopItem); // push_back으로 벡터에 아이템 묶음 추가
}

void Shop::displayItems() //가판대 보여주기
{
    std::cout << "판매중인 아이템 리스트" << std::endl;
    
    for (const auto& i : availableItems_)
    {
        std::cout << i.item_->getName() 
            << " : " << i.item_->getPrice() << "Gold" 
            << i.count_ <<"개 가지고 있음."
            << std::endl; //이름과 가격 들고옴
      
    }
}


void Shop::sellItem(const std::string& name, Character& character) // 유저가 상점에게 아이템 구매
{
    Item* item = vector<Item> item_;

}


void Shop::buyItem(const std::string& name, Character& character) //유저가 상점에게 아이템 판매
{
    Item* item = character.findItem(name);
    if (item == nullptr)
    {
        std::cout << "해당 아이템이 없습니다." << std::endl;
        return;
    }

    std::cout << "판매 감사합니다." << std::endl;

    int price = item->getPrice(); // 캐릭터에게 아이템 값 불러옴
    int change = static_cast<int>(price * 0.6); //거스름돈
    character.setGold(character.getGold() + change); //아이템 값 60%반환
    character.removeItem(item); //인벤토리에 아이템 삭제 요청

    std::cout << change << "Gold를 드립니다." << std::endl;
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