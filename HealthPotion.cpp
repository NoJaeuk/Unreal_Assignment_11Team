#include "HealthPotion.h"
#include <iostream>
using namespace std;

HealthPotion::HealthPotion(int heal) : healAmount(heal) {} // ȸ���� �ʱ�ȭ

std::string HealthPotion::GetName() const 
{
    return "Health Potion"; // ������ �̸� ��ȯ
}

void HealthPotion::Use(Character& character) 
{
    character.Heal(healAmount); // ĳ���� ü�� ȸ��

    cout << "ü�� ���� ���! HP�� " << healAmount << " ȸ���Ǿ����ϴ�." << endl;
}
