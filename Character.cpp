#include "Character.h"
#include "Item.h"
#include <iostream>

//캐릭터 생성자
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

//캐릭터 인스턴스 접근
Character& Character::getInstance(const std::string& name)
{
    static Character instance(name);
    return instance;
}

//캐릭터 소멸자
Character::~Character() 
{
    inventory.clear();
}

//겟함수
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
    cout << "이름: " << this->name << "\n";
    cout << "레벨: " << this->level << "\n";
    cout << "현재 체력: " << this->health << "/" << this->maxHealth << "\n";
    cout << "공격력: " << this->attack << "\n";
    cout << "경험치: " << this->exp << "/100" << "\n";
    cout << "소지금: " << this->gold << "\n";
} // 상태창 보기

void Character::levelUp() {
    this->exp -= 100;
    if (this->level >= 10) {
        this->level = 10;
        return;
    } // 예외 처리
    this->level++;
    this->maxHealth = (this->maxHealth + (this->level * 20));
    this->attack += this->level * 5;
    this->health = this->maxHealth;
    std::cout << "\n********************************\n";
    std::cout << "레벨 업!!\n";
    std::cout << "********************************\n";
} // 레벨업 함수

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
    std::cout << "인벤토리 목록" << std::endl;
    for (auto& invItem : inventory) {
        cout << "[" << invItem.item->getName() << "] 판매가 : " << invItem.item->getPrice() * 0.6 << " G " << " 남은갯수 : " << invItem.count << "\n";
    }
    std::cout << "========================================================\n";
}

void Character::addInventory(shared_ptr<Item> item, int count) {    //확장성을 위해서 count 추가했습니다.
    for (auto& invItem : inventory) {
        if (invItem.item->getName() == item->getName()) {
            invItem.count += count; // 이미 있으면 수량만 증가
            return; // 끝내기
        }
    }
    // 없으면 새로 추가
    InventoryItem newitem;
    newitem.item = item;
    newitem.count = count;
    inventory.push_back(newitem);
}



