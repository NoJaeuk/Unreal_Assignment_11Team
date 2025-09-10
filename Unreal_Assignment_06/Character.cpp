#include "Character.h"
#include "Item.h"
#include <iostream>

//ĳ���� ������
Character::Character(std::string name)
{
    this->name = name;
    this->level = 1;
    this->health = 200;
    this->maxHealth = 200;
    this->attack = 30;
    this->exp = 0;
    this->gold = 200;
    this->inventory = {};
}

//ĳ���� �ν��Ͻ� ����
Character& Character::getInstance(const std::string& name)
{
    static Character instance(name);
    return instance;
}

//ĳ���� �Ҹ���
Character::~Character() 
{
    inventory.clear();
}

//���Լ�
std::string Character::getName() { return this->name; }
int Character::getLevel() { return this->level; }
int Character::getHealth() { return this->health; }
int Character::getMaxHealth() { return this->maxHealth; }
int Character::getAttack() { return this->attack; }
int Character::getExp() { return this->exp; }
int Character::getGold() { return this->gold; }


void Character::setHealth(int health) 
{ 
    if (health >= maxHealth) { this->health = maxHealth; }
    else if (health <= 0) { this->health = 0; }
    else { this->health = health; }
}

void Character::setGold(int gold) { this->gold = gold; }
void Character::setAttack(int attack)
{
    this->attack = attack;
}

void Character::addExp(int exp) {
    this->exp += exp;
    if (this->exp >= 100) {
        this->levelUp();
    }
}

void Character::displayStatus() {
    cout << "\n=====Status=====" << "\n";
    cout << "�̸�: " << this->name << "\n";
    cout << "����: " << this->level << "\n";
    cout << "���� ü��: " << this->health << "/" << this->maxHealth << "\n";
    cout << "���ݷ�: " << this->attack << "\n";
    cout << "����ġ: " << this->exp << "/100" << "\n";
    cout << "������: " << this->gold << "\n";
} // ����â ����

void Character::levelUp() {
    this->exp -= 100;
    if (this->level >= 10) {
        this->level = 10;
        return;
    } // ���� ó��
    this->level++;
    this->maxHealth = (this->maxHealth + (this->level * 20));
    this->attack += this->level * 5;
    this->health = this->maxHealth;
    std::cout << "\n********************************\n";
    std::cout << "���� ��!!\n";
    std::cout << "********************************\n";
} // ������ �Լ�

void Character::removeItem(const std::string& itemName) {
    for (auto it = inventory.begin(); it != inventory.end(); it++) {
        if (it->item->getName() == itemName) {
            it->count--;
            if (it->count <= 0) {
                inventory.erase(it);
            }
            break;
        }
    }
}

std::shared_ptr<Item> Character::findItem(const std::string& itemName) {
    for (auto& invItem : inventory) {
        if (invItem.item->getName() == itemName) {
            return invItem.item; 
        }
    }
    return nullptr;
}

void Character::showInventory() {
    std::cout << "\n========================================================\n";
    std::cout << "�κ��丮 ���" << std::endl;
    for (auto& invItem : inventory) {
        cout << "[" << invItem.item->getName() << "] �ǸŰ� : " << invItem.item->getPrice() * 0.6 << " G " << " �������� : " << invItem.count << "\n";
    }
    std::cout << "========================================================\n";
}

void Character::addInventory(shared_ptr<Item> item, int count) {    //Ȯ�强�� ���ؼ� count �߰��߽��ϴ�.
    for (auto& invItem : inventory) {
        if (invItem.item->getName() == item->getName()) {
            invItem.count += count; // �̹� ������ ������ ����
            return; // ������
        }
    }
    // ������ ���� �߰�
    InventoryItem newitem;
    newitem.item = item;
    newitem.count = count;
    inventory.push_back(newitem);
}



