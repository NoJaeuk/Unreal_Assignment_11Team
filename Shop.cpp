#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"


void Shop::addItem(std::shared_ptr<Item> item, int count) //���Ӹ޴������� ������ ���Ǵ� ������ ����Ʈ ����
{
    ShopItem shopItem; // ��Ʈ��Ʈ Ÿ���� �ν��Ͻ�
    shopItem.item_ = item; // ���� ������ Ÿ���� ��Ʈ��Ʈ�� ����
    shopItem.count_ = count; // ���� ������ ������ ���� ����

    availableItems_.push_back(shopItem); // push_back���� ���Ϳ� ������ ���� �߰�
}

void Shop::displayItems() //���Ǵ� �����ֱ�
{
    std::cout << "�Ǹ����� ������ ����Ʈ" << std::endl;
    
    for (const auto& i : availableItems_)
    {
        std::cout << i.item_->getName() 
            << " : " << i.item_->getPrice() << "Gold" 
            << i.count_ <<"�� ������ ����."
            << std::endl; //�̸��� ���� ����
      
    }
}


void Shop::buyItem(const std::string& name, Character* character) //������ �������� ������ �Ǹ�
{
    ShopItem* find = nullptr; //������ �˻�
    for (auto& it : availableItems_)
    {
        if (it.item_->getName() == name)
        {
            find = &it;
            break;
        }
    }

    if (find == nullptr) //������ ����
    {
        std::cout << "������ �ش� �������� �����ϴ�." << std::endl;
        return;
    }

    if (find->count_ <= 0) //������
    {
        std::cout << "��� �����մϴ�." << std::endl;
        return;
    }

    int price = find->item_->getPrice(); //������
    if (character->getGold() < price)
    {
        std::cout << "��尡 �����մϴ�." << std::endl;
        return;
    }

    character->setGold(character->getGold() - price); //ĳ���͵����

    character->addInventory(find->item_, 1); //�������κ��丮�߰�

    find->count_--; //���� �����

    std::cout << "���� �Ϸ�: " << name << " ( " << price << " Gold )" << std::endl;

    //���� �����ۿ��� �̸����� ã��, �������� ��带 �����ͼ� ĳ���Ϳ��� set��� ĳ������ ��尡 �����ۺ��� ������ ����.
    // addInventory(shared_ptr<Item> name ,int count)�� ������ �߰�
    // ���� ����� -1 
    //��� ���� �� �������� �����Ҽ������ϴ� if(count <=0)

}


void Shop::sellItem(const std::string& name, Character* character) // ������ �������� ������ ����
{
    Item* item = character->findItem(name);
    if (item == nullptr)
    {
        std::cout << "�ش� �������� �����ϴ�." << std::endl;
        return;
    }

    std::cout << "�Ǹ� �����մϴ�." << std::endl;

    int price = item->getPrice(); // ĳ���Ϳ��� ������ �� �ҷ���
    int change = static_cast<int>(price * 0.6); //������ �� ���
    character->setGold(character->getGold() + change); //������ �� 60%��ȯ
    character->removeItem(item); //�κ��丮�� ������ ���� ��û

    std::cout << change << "Gold�� �帳�ϴ�." << std::endl;
}



void Shop::randomPick(Character* character)
{
    std::cout << "���� �̱� ����." << std::endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //�õ��ʱ�ȭ

    int cost = 5; //�̱Ⱑ��

    if (character->getGold() < cost) //������
    {
        std::cout << "��尡 �����մϴ�. (�ʿ�: " << cost << " Gold)" << std::endl;
        return;
    }

    character->setGold(character->getGold() - cost); //�̱����, ĳ���� �����
    std::cout << "���� �̱� ����!" << std::endl;

    int roll = std::rand() % 100 + 1; //�������� 1~100
    std::cout << "����� ���� ���ڴ�?: " << roll << std::endl;



    if (roll <= 35) // ��1
    {
        std::cout << "��! �ƹ� �͵� ���� ���߽��ϴ�." << std::endl;
    }
    else if (roll <= 60) // ��2
    {
        int reward = 3; //��2 ��ǰ
        character->setGold(character->getGold() + reward);
        std::cout << reward << " Gold�� ȹ���߽��ϴ�!" << std::endl;
    }
    else if (roll <= 85)
    {
        if (roll % 2)
        {
            auto potion = std::make_shared<Item>("Health Potion");
            character->addInventory(potion,1);
            std::cout << "ü�� ������ ȹ���߽��ϴ�!" << std::endl;
        }
        else
        {
            auto potion = std::make_shared<Item>("AttackPotion");
            character->addInventory(potion, 1);
            std::cout << "�� ������ ȹ���߽��ϴ�!" << std::endl;
        }
    }

    //gold ���� 5��
    //int random = TriggerEventWithProbability(35, 60, 85); �� / 3�� / ����
}




/*


    - ���������� ���� �������� ����/�Ǹ� ����(������ ����� �����Ӱ�!)
        - ������ ����
            - �÷��̾�� ��带 ����ؼ� �������� ����
            - ���� �������� �κ��丮�� ��� �߰�
        - ������ �Ǹ�
            - �÷��̾�� ������ �������� ���� �Ǹ� **(�Ǹ� ������ ���� ������ 60%!)**
            - �Ǹŵ� �������� �κ��丮���� ��� ����
    - ��ü�� ���� 10 Gold��, �����ݷ� ��ȭ 15 Gold��ó�� ������ ���س���!
    - ���� ��� �κ��丮�� ������, �Ǹ� �� �������� �Ҹ�ǰ� ��� ȹ��!
    - ��, ���� �ý����� �߰��Ѵٴ� ���� �� �κ��丮�� �־�߰ڳ׿�?
        - ĳ���� Ŭ������ ��� ������ �����غ�����!

*/