// Header-Datei

class Fahrrad {
	//Methoden
	public:						// "Öffentlich" → Zugriff von außerhalb möglich
		Fahrrad(int kettenblatt, int ritzel, double raddurchmesser);
		Fahrrad();
		double bestimmeRadumfang();						// U in m
		double bestimmeEntfaltung();					// e in m
		double bestimmeGeschwindigkeit(const int& TiM);	// T in 1/min

	//Attribute
	private:					// Zugriff nur innerhalb der Klasse möglich
		int kettenblatt;		//< Anzahl der Zähne des Zahnkranzes (vorne)
		int ritzel;				//< Anzahl der Zähne des Ritzels (hinten)
		double raddurchmesser;	//< Raddurchmesser in Metern [m]
};
