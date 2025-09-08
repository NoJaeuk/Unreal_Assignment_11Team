#pragma once // 중복 포함 방지

#include <string>
//class Character;  전방 선언: Character를 아직 정의 안 했지만, 포인터/참조로 사용할 수 있도록 선언

// 아이템의 공통 인터페이스 역할 (추상 클래스)
class Item 
{
public:
    virtual ~Item() {} // 가상 소멸자 (상속받은 객체 삭제 시 안전하게 동작)

    // 아이템 이름 가져오기 (모든 하위 클래스에서 구현해야 함)
    virtual std::string GetName() const = 0;

    // 아이템 사용 → Character 객체에 효과 적용 (순수 가상 함수)
    virtual void Use(Character& character) = 0;
};
