#pragma once
#include "Item.h"
// ���ݷ� ���� ������ Ŭ����

class AttackPotion : public Item 
{
private:
    int boostAmount; // ������ ���ݷ� ��ġ

public:
    AttackPotion(int boost);// ������ (������ ����)
    std::string GetName() const override; // �̸� ��ȯ
    void Use(Character& character) override; // ĳ���Ϳ��� ȿ�� ����
};
