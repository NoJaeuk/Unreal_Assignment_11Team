#include "AttackPotion.h"

#include <iostream>
using namespace std;

AttackPotion::AttackPotion(int boost) : boostAmount(boost) {} // ������ �ʱ�ȭ

std::string AttackPotion::GetName() const 
{
    return "Attack Boost"; // ������ �̸� ��ȯ
}

void AttackPotion::Use(Character& character) {
    character.IncreaseAttack(boostAmount); // ĳ���� ���ݷ� ����
    cout << "���ݷ� ���� ������ ���! ���ݷ��� " << boostAmount << " �ö����ϴ�." << endl;
}



