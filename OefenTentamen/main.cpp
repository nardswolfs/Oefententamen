#include "Persoon.h"
#include <iostream>
#include "Matrix.h"

std::vector<int> verzameling;
std::vector<int> indicatie;
void vulVerzamelingen(int n)
{
	for (int i = 0; i < n; i++) {
		verzameling.push_back(i + 1);
		indicatie.push_back(0);
	}
}

void printDeelverzameling(std::vector<int> ind) {
	bool isnull = true;
	std::cout << "{";
	for (size_t i = 0; i < verzameling.size(); i++) {
		if (ind.at(i) == 1) {
			std::cout << verzameling.at(i);
			isnull = false;
		}
	}
	if (!isnull) std::cout << "} ";
	else if (isnull) std::cout << "} ";
}

void verzamel(std::vector<int> ind, int x) {
	if (x == ind.size() - 1) {
		ind.at(x) = 0;
		printDeelverzameling(ind);
		ind.at(x) = 1;
		printDeelverzameling(ind);
		return;
	}
	ind.at(x) = 0;
	verzamel(ind, x + 1);
	ind.at(x) = 1;
	verzamel(ind, x + 1);
}

int main()
{
	Persoon p = Persoon("Hans", 1996);
	p.wijzigPartner("Barbara");
	p.voegKindToe("Olaf");
	p.voegKindToe("Amy");
	p.voegKindToe("Henk");
	std::cout << p << std::endl;

	Persoon p2 = Persoon("Ans", 1998);
	p2.wijzigPartner("Sjak");
	p2.voegKindToe("Jan");
	p2.voegKindToe("Ilse");
	p2.voegKindToe("Loes");
	std::cout << p2 << std::endl;

	Persoon p3 = Persoon("Walter", 1990);
	std::cout << p3 << std::endl;

	bool comp = p < p2;
	if(comp == false) 
		std::cout << "De naam van deze persoon komt later in het alfabet dan die van de vergeleken persoon" << std::endl << std::endl;
	else std::cout << "De naam van deze persoon komt eerder in het alfabet dan die van de vergeleken persoon" << std::endl;
	p3 = p;
	std::cout << p3 << std::endl;

	Matrix matrix = Matrix("woordenmatrix.txt");
	std::cout << matrix;
	matrix.findPalindromesInMatrix();
	matrix.writePalindromes(matrix.getPalindromes());
	std::cout << std::endl << "Palindromes written away: " << std::endl;
	for each(Palindrome p in matrix.getPalindromes())
		std::cout << p << std::endl;
	std::cout << std::endl;

	vulVerzamelingen(4);
	verzamel(indicatie, 0);

	for (;;);
}
