#include "Inventory.h"
#include "Character.h" // Character Ŭ���� ���� �ʿ�

using namespace std;

void Inventory::AddItem(shared_ptr<Item> item, int count)
{
    // �̹� ���� �̸��� �������� �ִ��� Ȯ��
    for (auto& inv : items) 
    {
        if (inv.item->GetName() == item->GetName()) 
        {
            inv.count += count; // ������ ����
            cout << item->GetName() << " " << count << "�� �߰��� (�� " << inv.count << "��)" << endl;
            return;
        }
    }
    // ������ ���� �߰�
    items.push_back({ item, count });
    cout << item->GetName() << " " << count << "�� �κ��丮�� �߰���!" << endl;
}

void Inventory::ShowItems() 
{
    cout << "===== �κ��丮 =====" << endl;
    if (items.empty()) 
    {
        cout << "��� �ֽ��ϴ�." << endl;
        return;
    }
    for (size_t i = 0; i < items.size(); i++) 
    {
        cout << i + 1 << ". " << items[i].item->GetName()
            << " (x" << items[i].count << ")" << endl;
    }
}

void Inventory::UseItem(int index, Character& character) 
{
    if (index < 0 || index >= (int)items.size()) 
    {
        cout << "�߸��� �����Դϴ�!" << endl;
        return;
    }
    // ���õ� ������ ȿ�� ����
    items[index].item->Use(character);
    // ���� ����
    items[index].count--;
    // ������ 0�� �Ǹ� �κ��丮���� ����
    if (items[index].count <= 0) 
    {
        items.erase(items.begin() + index);
    }
}
