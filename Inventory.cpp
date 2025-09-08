#include "Inventory.h"
#include "Character.h" // Character 클래스 정의 필요

using namespace std;

void Inventory::AddItem(shared_ptr<Item> item, int count)
{
    // 이미 같은 이름의 아이템이 있는지 확인
    for (auto& inv : items) 
    {
        if (inv.item->GetName() == item->GetName()) 
        {
            inv.count += count; // 개수만 증가
            cout << item->GetName() << " " << count << "개 추가됨 (총 " << inv.count << "개)" << endl;
            return;
        }
    }
    // 없으면 새로 추가
    items.push_back({ item, count });
    cout << item->GetName() << " " << count << "개 인벤토리에 추가됨!" << endl;
}

void Inventory::ShowItems() 
{
    cout << "===== 인벤토리 =====" << endl;
    if (items.empty()) 
    {
        cout << "비어 있습니다." << endl;
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
        cout << "잘못된 선택입니다!" << endl;
        return;
    }
    // 선택된 아이템 효과 적용
    items[index].item->Use(character);
    // 개수 차감
    items[index].count--;
    // 개수가 0이 되면 인벤토리에서 삭제
    if (items[index].count <= 0) 
    {
        items.erase(items.begin() + index);
    }
}
