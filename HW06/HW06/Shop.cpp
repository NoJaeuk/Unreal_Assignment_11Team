#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Items.h"
#include "Inventory.h"

Shop::Shop()
{
    // availableItems�� �Ǹſ� ������ �߰�
}

void Shop::shopOpen()
{
    std::cout << "� ������. ������ ���� ���� ȯ���մϴ�." << std::endl;

    while (true)
    {
        int select = 0;
        std::cout << "�������� ��� �ּ���." << std::endl;
        std::cout << "1. ������ ����." << std::endl;
        std::cout << "2. ������ �Ǹ�." << std::endl;
        std::cout << "3. ���� �̱�." << std::endl;
        std::cout << "0. ���� ������." << std::endl;
        std::cin >> select;

        switch (select)
        {
        case 1:
            std::cout << "������ ���Ÿ� �����߽��ϴ�." << std::endl;
            buyItem();
            break;

        case 2:
            std::cout << "������ �ǸŸ� �����߽��ϴ�." << std::endl;
            sellItem();
            break;

        case 3:
            std::cout << "������ �����̱⸦ �����߽��ϴ�." << std::endl;
            randomPick();
            break;

        case 0:
            std::cout << "�������� �����ϴ�." << std::endl;
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
    std::cout << "�Ǹ����� ������ ����Ʈ" << std::endl;
    
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
        cout << "�ش� �������� �����ϴ�." << endl;
        return;
    }

    int price = item->getprice();
    character->setGold(character->getGold() + price);
    character->removeItem(name);
}



void Shop::randomPick()
{
    std::cout << "���� �̱� ����." << std::endl;
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