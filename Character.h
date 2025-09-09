#pragma once
#include <string>
#include <vector>
#include <memory>
#include "healthPotion.h" // 임시 헤더 파일

using namespace std;

class Character {
private:
	string name;
	int level;
	int maxHealth;
	int health;
	int attack;
	int exp; // exp
	int gold;
	struct itemCount {
		shared_ptr<Item> item; // 임시 Item 클래스명 변경시 수정 필요
		int count; // 아이템 개수
		itemCount(shared_ptr<Item> inputItem, int inputCount = 1); // 구조체 itemCount 생성자
	}; // 아이템 객체와 개수를 관리하는 sturct 멤버 변수
	vector<itemCount> inventory; // itemCount 적재용 인벤토리
	Character(const string& inputName); // 생성자
	~Character(); // 소멸자
	// 복사 방지
	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;
	Character(Character&&) = delete;
	Character& operator = (Character&&) = delete;
public:
	static Character& getInstance(string inputName = ""); // name 변수명 중복으로 생길 휴먼에러 방지차 inputName 으로 바꿈
	void displayStatus(); // 캐릭터 상태창 확인 함수
	void levelUp(); // 캐릭터 레벨업 구현 함수
	void addItem(shared_ptr<Item> inputItem, int inputCount); // 아이템 추가 함수, 인자로 카운트 추가
	void removeItem(shared_ptr<Item> inputItem); // 아이템 제거 함수
	//bool isDead() const; // 캐릭터 생사여부 판단 함수
	shared_ptr<Item> findItem(const string& inputName) const; // 아이템 객체 검색후 반환하는 함수 없으면 nullptr
	void showInventory(); // void 인벤토리 아이템 다 출력
	void addExp(int inputExp); // sexExperience -> addExp로 변경 경험치값이 100을 초과하면 levelUp() 호출
	// getter
	const string& getName() const; // 효율성을 위해 상수와 참조값을 반환하게 변경
	int getMaxHealth() const; 
	int getLevel() const; // 안정성을 위해 읽기 전용으로 변경
	int getHealth() const;
	int getAttack() const;
	int getExperience() const;
	int getGold() const;
	// setter
	//void setName(string val); // 필요시 추가
	//void setMaxHealth(int val); // 필요시 추가
	//void setLevel(int val); // 필요시 추가
	void setHealth(int inputHealth);
	void setAttack(int inputAttack);
	//void setExperience(int inputExperience); // addExp
	void setGold(int inputGold);
};
