#pragma once
#include "Item.h"
// ü�� ȸ�� ������ Ŭ����
class HealthPotion : public Item 
{
private:
    int healAmount; // ȸ����

public:
    HealthPotion(int heal);// ������ (ȸ���� ����)
    std::string GetName() const override; // �̸� ��ȯ
    void Use(Character& character) override; // ĳ���Ϳ��� ȿ�� ����
};
