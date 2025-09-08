#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Items.h"

Shop::Shop()
{
    // �׳� �ʱ�ȭ��
}

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


void Shop::sellItem(const std::string& name, Character& character) // ������ �������� ������ ����
{
    Item* item = vector<Item> item_;

}


void Shop::buyItem(const std::string& name, Character& character) //������ �������� ������ �Ǹ�
{
    Item* item = character.findItem(name);
    if (item == nullptr)
    {
        std::cout << "�ش� �������� �����ϴ�." << std::endl;
        return;
    }

    std::cout << "�Ǹ� �����մϴ�." << std::endl;

    int price = item->getPrice(); // ĳ���Ϳ��� ������ �� �ҷ���
    int change = static_cast<int>(price * 0.6); //�Ž�����
    character.setGold(character.getGold() + change); //������ �� 60%��ȯ
    character.removeItem(item); //�κ��丮�� ������ ���� ��û

    std::cout << change << "Gold�� �帳�ϴ�." << std::endl;
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