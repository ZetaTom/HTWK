#include <iostream>
#include "Fahrrad.hpp"

int main() {
	Fahrrad fahrrad(50, 7, 1.2);	// ein sehr SEHR merkwürdiges Fahrrad
	std::cout << fahrrad.bestimmeRadumfang() << ", " << fahrrad.bestimmeEntfaltung() << ", " << fahrrad.bestimmeGeschwindigkeit(50) << std::endl;
}
