#pragma once
#include <iostream>

class Persoon {

public:
	Persoon(std::string naam, int geboorteJaar);
	Persoon(const Persoon &persoon);
	~Persoon();

	void wijzigPartner(std::string partner) const;
	void voegKindToe(std::string naam);

	std::string * geefKinderen() const;
	int geefAantalKinderen() const;

	void operator=(const Persoon& persoon) {
		_naam = persoon._naam;
		_geboorteJaar = persoon._geboorteJaar;
		_partner = persoon._partner;
		_kinderen = persoon._kinderen;
		_aantalKinderen = persoon._aantalKinderen;
		_maxAantalKinderen = persoon._maxAantalKinderen;
	}

	bool operator<(const Persoon& persoon) {
		size_t length = persoon._naam.length() - _naam.length();
		if (length < 0) length *= -1;
		for (int i = 0; i < length; i++)
		{
			if (_naam[i] < persoon._naam[i])
				return true;
		}
		return false;
	}

	friend std::ostream& operator<<(std::ostream& os, const Persoon &p) {
		os << "Naam: " << p._naam.c_str() << std::endl;
		os << "Geboortejaar: " << p._geboorteJaar << std::endl;
		if(p._partner[0] != "") os << "Partner: " << p._partner[0].c_str() << std::endl;
		else os << "Partner: Geen partner" << std::endl;
		if (p._aantalKinderen > 0)
		{
			std::cout << "Kinderen: "; 
			for (int i = 0; i < p._aantalKinderen; i++) 
				std::cout << p._kinderen[i].c_str() << " "; 
			os << std::endl;
		}
		else os << "Kinderen: Geen kinderen" << std::endl;
		return os;
	}

private:
	std::string _naam;
	int _geboorteJaar;
	std::string *_partner;  		// een persoon heeft 0 of 1 partner (naam)
	std::string *_kinderen; 		// een persoon heeft 0 of meer kinderen (namen)
							// De namen van deze kinderen worden in een 
							// dynamische array opgeslagen.
	int _aantalKinderen;		// het aantal kinderen van deze persoon
	int _maxAantalKinderen;	// de huidige grootte van de 
							// dynamisch array van de namen van kinderen
};


