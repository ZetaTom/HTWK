#include "Fahrrad.hpp"
// Definition von Methoden


// Konstruktor
Fahrrad::Fahrrad(int ikettenblatt, int irizel, double iraddurchmesser) {
	kettenblatt = ikettenblatt;
	rizel = irizel;
	raddurchmesser = iraddurchmesser;
};

// Standardonstruktor, wird bei Aufruf ohne Parameter benutzt
Fahrrad::Fahrrad() {
	kettenblatt = 40;
	rizel = 13;
	raddurchmesser = 0.65;
}

double Fahrrad::bestimmeRadumfang() {
	return 3.14159 * raddurchmesser;	// Umfang U [m] = pi * d
										// raddruchmesser aus Klasse
}

double Fahrrad::bestimmeEntfaltung() {
	double e;
	e = bestimmeRadumfang() * kettenblatt / rizel;	// e = nK / nR * U
	return e;
}

double Fahrrad::bestimmeGeschwindigkeit(const int& TiM) {
	double T = TiM * 60;
	double v = T * bestimmeEntfaltung() / 1000;
	return v;
}
