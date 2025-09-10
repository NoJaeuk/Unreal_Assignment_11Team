#pragma once
#include <string>

class Character;

class Item
{
public:
	virtual std::string getName() = 0;
	virtual int getPrice() = 0;
	virtual void use(Character* character) = 0;

	virtual ~Item() = default;
};

