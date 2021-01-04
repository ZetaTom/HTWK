// Header-Datei

class Fahrrad {
	//Methoden
	public:						// "Öffentlich" → Zugriff von außerhalb möglich
		Fahrrad(int kettenblatt, int rizel, double raddurchmesser);
		Fahrrad();
		double bestimmeRadumfang();
		double bestimmeEntfaltung();
		double bestimmeGeschwindigkeit(const int& TiM);

	//Attribute
	private:					// Zugriff nur innerhalb der Klasse möglich
		int kettenblatt;		//< Anzahl der Zähne des Zahnkranzes (vorne)
		int rizel;				//< Anzahl der Zähne des Ritzels (hinten)
		double raddurchmesser;	//< Raddurchmesser in Metern [m]
};
