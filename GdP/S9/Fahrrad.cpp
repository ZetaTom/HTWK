#include "Fahrrad.hpp"
// Definition von Methoden


// Konstruktor
// i steht für Input
Fahrrad::Fahrrad(int ikettenblatt, int iritzel, double iraddurchmesser) {
	kettenblatt = ikettenblatt;
	ritzel = iritzel;
	raddurchmesser = iraddurchmesser;
};

// Standardkonstruktor, wird bei Aufruf ohne Parameter benutzt
Fahrrad::Fahrrad() {
	kettenblatt = 40;
	ritzel = 13;
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
	double T = TiM * 60;							// Tim → T in 1/min; Umrechnung in s
	double v = T * bestimmeEntfaltung() / 1000;		// v = T * e; Umrechnung in km/h
	return v;
}
