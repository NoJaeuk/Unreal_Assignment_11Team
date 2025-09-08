#pragma once
#include <string>
#include <vector>
#include <memory>
#include "healthPotion.h" // 임시 헤더 파일
#include "shop.h" // 임시 헤더 파일

using namespace std;

//class Item; // 임시 Item 클래스 전방 선언(변경시 수정 필요)

class Character {
private:
	static Character* instance; // 싱글톤 생성
	string name;
	int level;
	int maxHealth;
	int health;
	int attack;
	int experience;
	int gold;
	struct itemCount {
		shared_ptr<Item> item; // 임시 Item 클래스명 변경시 수정 필요
		int count; // 아이템 개수
		itemCount(shared_ptr<Item> inputItem, int inputCount = 1); // 생성자
	}; // 아이템 객체와 개수를 관리하는 sturct 멤버 변수
	vector<itemCount> inventory; // itemCount 적재용 인벤토리
	Character(const string& inputName); // 생성자
	// 복사 방지
	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;
	Character(Character&&) = delete;
	Character& operator = (Character&&) = delete;
public:
	static Character* getInstance(string inputName = ""); // name 변수명 중복으로 생길 휴먼에러 방지차 inputName 으로 바꿈
	void displayStatus(); // 캐릭터 상태창 확인 함수
	void levelUp(); // 캐릭터 레벨업 구현 함수
	//void useItem(int index); // 확장성을 위해 아이템 제거 함수로 대체
	void visitShop(); // 상점 방문 함수 미구현(조율 필요)
	void addItem(shared_ptr<Item> inputItem); // 아이템 추가 함수
	void removeItem(shared_ptr<Item> inputItem); // 아이템 제거 함수
	bool isDead() const; // 캐릭터 생사여부 판단 함수
	// getter
	const string& getName() const; // 효율성을 위해 상수와 참조값을 반환하게 변경
	//int getMaxHealth(); // 필요시 추가
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
	void setExperience(int inputExperience);
	void setGold(int inputGold);
};
