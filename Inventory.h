#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Item.h"

using namespace std;

// 인벤토리 안에 들어가는 실제 아이템 정보
struct InventoryItem 
{
    shared_ptr<Item> item; // 아이템 객체 (공유 포인터)
    int count;                  // 개수
};

// 인벤토리 구조체
struct Inventory 
{
    vector<InventoryItem> items; // 아이템 리스트

    void AddItem(std::shared_ptr<Item> item, int count = 1);// 아이템 추가
    void ShowItems();// 아이템 목록 출력
    void UseItem(int index, Character& character);// 아이템 사용
};
