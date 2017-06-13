#include "Persoon.h"

Persoon::Persoon(std::string naam, int geboorteJaar)
{
	_geboorteJaar = geboorteJaar;
	_naam = naam;
	_partner = new std::string[1];
	_aantalKinderen = 0;
	_maxAantalKinderen = 2;
	_kinderen = new std::string[_maxAantalKinderen];
}

Persoon::Persoon(const Persoon & persoon)
{
	_geboorteJaar = persoon._geboorteJaar;
	_naam = persoon._naam;
	_partner = new std::string[1];
	_aantalKinderen = 0;
	_maxAantalKinderen = 2;
	_kinderen = new std::string[_maxAantalKinderen];
}

Persoon::~Persoon()
{
	delete[] _kinderen;
	delete[] _partner;
}

void Persoon::wijzigPartner(std::string naam) const
{
	*_partner = naam;
}

void Persoon::voegKindToe(std::string naam)
{
	if (_aantalKinderen >= _maxAantalKinderen) {
		_maxAantalKinderen = _maxAantalKinderen * 2;
		std::string *temp = new std::string[_maxAantalKinderen];
		for (int i = 0; i < _aantalKinderen; i++) {
			temp[i] = _kinderen[i];
		}
		delete[] _kinderen;
		_kinderen = temp;
	}
	_kinderen[_aantalKinderen] = naam;
	_aantalKinderen++;
}

std::string* Persoon::geefKinderen() const
{
	return _kinderen;
}

int Persoon::geefAantalKinderen() const
{
	return _aantalKinderen;
}


