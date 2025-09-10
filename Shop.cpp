#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>
#include <random>


void Shop::displayItems() {
    std::cout << "========================================================\n";
    std::cout << "판매중인 아이템 리스트" << "\n";
    for (auto& invItem : availableItems_) {
        std::cout << invItem.item->getName() << " : " << invItem.item->getPrice() << " G " << " 남은갯수 : " << invItem.count << "\n";

    }
    std::cout << "Random : 5 G\n";
    std::cout << "========================================================\n";
}


void Shop::buyItem(const std::string& name, Character* character) 
{
    //이름으로 찾기
    shared_ptr<Item> sitem;
    for (auto& invItem : availableItems_) {
        if (invItem.item->getName() == name) {
            if (invItem.count != 0 && character->getGold()>=invItem.item->getPrice()) {
                sitem = invItem.item;
                character->setGold(character->getGold() - sitem->getPrice());
                character->addInventory(sitem, 1);
                invItem.count--;
                std::cout << "\n구입 완료!\n";
            }
            else {
                std::cout << "\n아이템을 구입할수 없습니다!\n";
            }
            return;
        }
    }
    std::cout << "\n해당 아이템이 없습니다!\n";
}

void Shop::sellItem(const std::string& name, Character* character) {
    for (auto& invItem : character->inventory) {
        if (invItem.item->getName() == name) {
            character->setGold(character->getGold() + character->findItem(name)->getPrice() * 0.6);
            character->removeItem(name);
            std::cout << "\n판매 완료!\n";
            return;
        }
    }
    std::cout << "\n해당 아이템이 없습니다!\n";
}

void Shop::addItem(std::shared_ptr<Item> item, int count) {
    ShopItem newitem;
    newitem.item = item;
    newitem.count = count;
    availableItems_.push_back(newitem);
}

int TriggerEventWithProbability(float Probability_1, float Probability_2, float Probability_3 )
{
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> dist(1, 100); 

    int randomNumber = dist(gen);

    if (randomNumber > 0 && randomNumber < Probability_1) { return 1; }
    if (randomNumber >= Probability_1 && randomNumber < Probability_2) { return 2; }
    if (randomNumber >= Probability_2 && randomNumber < Probability_3) { return 3; }
    if (randomNumber >= Probability_3 && randomNumber <= 100) { return 4; }
}


void Shop::randomPick(Character* character) {
    if (character->getGold() >= 5) {
        character->setGold(character->getGold() - 5);
        int random = TriggerEventWithProbability(35, 60, 85);
        std::cout << "\nRandom 아이템을 구매합니다!\n";
        std::cout << "ㄷㄱㄷㄱㄷㄱㄷㄱㄷㄱㄷㄱㄷㄱㄷㄱㄷㄱㄷ\n";

        switch (random)
        {
        case 1:
            std::cout << "\n [꽝! 다음기회에~] \n";
            break;

        case 2:
            std::cout << "\n [3원 당첨! 축하드립니다!] \n";
            character->setGold(character->getGold() + 3);
            break;

        case 3: {
            std::cout << "\n [HealthPotion 당첨! 축하드립니다!] \n";
            auto it = std::find_if(availableItems_.begin(), availableItems_.end(),
                [](const ShopItem& inv) { return inv.item->getName() == "HealthPotion"; });
            if (it != availableItems_.end()) { character->addInventory(it->item, 1); }
            break;
        }

        case 4: {
            std::cout << "\n [AttackBoost 당첨! 축하드립니다!] \n";
            auto it_ = std::find_if(availableItems_.begin(), availableItems_.end(),
                [](const ShopItem& inv) { return inv.item->getName() == "AttackBoost"; });
            if (it_ != availableItems_.end()) { character->addInventory(it_->item, 1); }
            break;
        }

        }

    }
    else {
        std::cout << "\n아이템을 구입할수 없습니다!\n";
    }
}