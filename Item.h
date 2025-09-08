#pragma once // �ߺ� ���� ����

#include <string>
//class Character;  ���� ����: Character�� ���� ���� �� ������, ������/������ ����� �� �ֵ��� ����

// �������� ���� �������̽� ���� (�߻� Ŭ����)
class Item 
{
public:
    virtual ~Item() {} // ���� �Ҹ��� (��ӹ��� ��ü ���� �� �����ϰ� ����)

    // ������ �̸� �������� (��� ���� Ŭ�������� �����ؾ� ��)
    virtual std::string GetName() const = 0;

    // ������ ��� �� Character ��ü�� ȿ�� ���� (���� ���� �Լ�)
    virtual void Use(Character& character) = 0;
};
