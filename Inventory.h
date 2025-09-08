#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Item.h"

using namespace std;

// �κ��丮 �ȿ� ���� ���� ������ ����
struct InventoryItem 
{
    shared_ptr<Item> item; // ������ ��ü (���� ������)
    int count;                  // ����
};

// �κ��丮 ����ü
struct Inventory 
{
    vector<InventoryItem> items; // ������ ����Ʈ

    void AddItem(std::shared_ptr<Item> item, int count = 1);// ������ �߰�
    void ShowItems();// ������ ��� ���
    void UseItem(int index, Character& character);// ������ ���
};
