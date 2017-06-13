#pragma once
#include <iostream>
#include <vector>
#include "Palindrome.h"
#define ROWS 1000
#define COLS 1000

class Matrix
{
public:
	Matrix(std::string filename);
	~Matrix();

	void fillMatrix(std::string filename);
	static void writePalindromes(std::vector<Palindrome> palindromes);
	static bool isPalindrome(std::string woord);
	void findPalindromesInMatrix();
	std::vector<Palindrome> getPalindromes();
	
	friend std::ostream& operator<<(std::ostream& os, const Matrix &m) {
		for(size_t row = 0; row < m._matrix.size(); row++)
		{
			for(size_t col = 0; col < m._matrix[0].size(); col++)
			{
				std::cout << m._matrix[row][col];
			}
			std::cout << std::endl;
		}
		return os;
	}

private:
	std::vector<std::vector<char>> _matrix;
	std::vector<Palindrome> _palindromes;
};
