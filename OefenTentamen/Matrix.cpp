#include "Matrix.h"
#include <string>
#include <fstream>

Matrix::Matrix(std::string filename)
{
	fillMatrix(filename);
}

Matrix::~Matrix()
{
}

void Matrix::fillMatrix(std::string filename)
{
	std::string line;
	std::ifstream myfile(filename);
	if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			std::vector<char> lineVector;
			for (int i = 0; i < line.length(); i++)
				lineVector.push_back(line[i]);
			_matrix.push_back(lineVector);
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
}

void Matrix::writePalindromes(std::vector<Palindrome> palindromes)
{
	std::ofstream myfile("gevonden.txt");
	if (myfile.is_open())
	{
		for each(Palindrome p in palindromes)
		myfile << p << std::endl;
		myfile.close();
	}
	else std::cout << "Unable to open file";
}

bool Matrix::isPalindrome(std::string woord)
{
	std::string palindroom = woord;
	std::reverse(palindroom.begin(), palindroom.end());
	if (woord == palindroom)
		return true;
	return false;
}

void Matrix::findPalindromesInMatrix()
{
	std::vector<Palindrome> palindromes;
	std::string palindrome;
	int colcount = 0;
	int rowcount = 0;
	for (size_t row = 0; row < _matrix.size() - 1; row++)
	{
		for (size_t col = 0; col < _matrix[0].size() - 1; col++)
		{
			if (_matrix[row][col] != '.') colcount++;
			else colcount = 0;
			if (colcount >= 4 && (_matrix[row][col + 1] == '.' || col == _matrix[0].size() - 1))
			{
				for (int i = col - colcount + 1; i <= col; i++) palindrome.push_back(_matrix[row][i]);
				if(isPalindrome(palindrome))
					palindromes.push_back(Palindrome(palindrome, col - colcount + 1, row, "Horizontaal"));
				palindrome.clear();
			}
		}
	}

	for (size_t col = 0; col < _matrix[0].size() - 1; col++)
	{
		for (size_t row = 0; row < _matrix.size() - 1; row++)
		{
			if (_matrix[row][col] != '.') rowcount++;
			else rowcount = 0;
			if (rowcount >= 4 && (_matrix[row + 1][col] == '.' || col == _matrix.size() - 1))
			{
				for (int i = row - rowcount + 1; i <= row; i++) palindrome.push_back(_matrix[i][col]);
				if(isPalindrome(palindrome))
					palindromes.push_back(Palindrome(palindrome, col, row - rowcount + 1, "Verticaal"));
				palindrome.clear();
			}
		}
	}

	_palindromes = palindromes;
}

std::vector<Palindrome> Matrix::getPalindromes()
{
	return _palindromes;
}
