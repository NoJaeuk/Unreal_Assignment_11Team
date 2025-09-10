#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>
#include <random>


void Shop::displayItems() {
    std::cout << "========================================================\n";
    std::cout << "�Ǹ����� ������ ����Ʈ" << "\n";
    for (auto& invItem : availableItems_) {
        std::cout << invItem.item->getName() << " : " << invItem.item->getPrice() << " G " << " �������� : " << invItem.count << "\n";

    }
    std::cout << "Random : 5 G\n";
    std::cout << "========================================================\n";
}


void Shop::buyItem(const std::string& name, Character* character) 
{
    //�̸����� ã��
    shared_ptr<Item> sitem;
    for (auto& invItem : availableItems_) {
        if (invItem.item->getName() == name) {
            if (invItem.count != 0 && character->getGold()>=invItem.item->getPrice()) {
                sitem = invItem.item;
                character->setGold(character->getGold() - sitem->getPrice());
                character->addInventory(sitem, 1);
                invItem.count--;
                std::cout << "\n���� �Ϸ�!\n";
            }
            else {
                std::cout << "\n�������� �����Ҽ� �����ϴ�!\n";
            }
            return;
        }
    }
    std::cout << "\n�ش� �������� �����ϴ�!\n";
}

void Shop::sellItem(const std::string& name, Character* character) {
    for (auto& invItem : character->inventory) {
        if (invItem.item->getName() == name) {
            character->setGold(character->getGold() + character->findItem(name)->getPrice() * 0.6);
            character->removeItem(name);
            std::cout << "\n�Ǹ� �Ϸ�!\n";
            return;
        }
    }
    std::cout << "\n�ش� �������� �����ϴ�!\n";
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
        std::cout << "\nRandom �������� �����մϴ�!\n";
        std::cout << "��������������������������������������\n";

        switch (random)
        {
        case 1:
            std::cout << "\n [��! ������ȸ��~] \n";
            break;

        case 2:
            std::cout << "\n [3�� ��÷! ���ϵ帳�ϴ�!] \n";
            character->setGold(character->getGold() + 3);
            break;

        case 3: {
            std::cout << "\n [HealthPotion ��÷! ���ϵ帳�ϴ�!] \n";
            auto it = std::find_if(availableItems_.begin(), availableItems_.end(),
                [](const ShopItem& inv) { return inv.item->getName() == "HealthPotion"; });
            if (it != availableItems_.end()) { character->addInventory(it->item, 1); }
            break;
        }

        case 4: {
            std::cout << "\n [AttackBoost ��÷! ���ϵ帳�ϴ�!] \n";
            auto it_ = std::find_if(availableItems_.begin(), availableItems_.end(),
                [](const ShopItem& inv) { return inv.item->getName() == "AttackBoost"; });
            if (it_ != availableItems_.end()) { character->addInventory(it_->item, 1); }
            break;
        }

        }

    }
    else {
        std::cout << "\n�������� �����Ҽ� �����ϴ�!\n";
    }
}