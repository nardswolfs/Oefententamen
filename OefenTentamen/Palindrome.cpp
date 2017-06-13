#include "Palindrome.h"
#include <string>
#include <fstream>

Palindrome::Palindrome(std::string woord, int posX, int posY, std::string richting)
{
	_posX = posX;
	_posY = posY;
	_woord = woord;
	_richting = richting;
}

Palindrome::~Palindrome()
{
}
