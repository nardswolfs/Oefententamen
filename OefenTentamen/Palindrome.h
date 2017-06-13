#pragma once
#include <iostream>
#include <vector>

class Palindrome
{
public:
	Palindrome(std::string woord, int _posX, int _posY, std::string richting);
	~Palindrome();

	friend std::ostream& operator<<(std::ostream& os, const Palindrome &p) {
		os << p._woord.c_str() << " (" << p._posX << ", " << p._posY << ") " << p._richting.c_str();
		return os;
	}

private:
	std::string _woord;
	int _posX;
	int _posY;
	std::string _richting;
};
