#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "komplex.hpp"
#include "komplexnd.hpp"

/**
 * Simple test programme to test basic functionality of the following classes:
 * KomplexeZahl:	komplex.cpp komplex.hpp			Implementation of complex numbers
 * KomplexND:		Komplexnd.cpp komplexnd.hpp		Vector of complex numbers
 *
 *
 * Tab stop >|<
 * 			 ^
 */



// Define some macros to ease readability
#define LINE std::cout << std::endl << "Current Line: " << __LINE__ << std::endl;
#define PASS std::cout << "TEST PASSED!" << std::endl;
#define FAIL std::cout << std::endl << "\a############################################################" << std::endl << "######################  TEST  FAILED  ######################" << std::endl << "############################################################\a" << std::endl; exit(1);



void sec(std::string name, std::string module = "", std::string function = "");
void msg(std::string msg);
bool ass(double a, double b);
bool ass(bool a, bool b);
bool ass(KomplexeZahl a, KomplexeZahl b);
bool ass(size_t a, size_t b);



void sec(std::string name, std::string module, std::string function) {
	std::cout << std::endl
	<< "============================================================" << std::endl
	<< "Module:   " << module << std::endl
	<< "Function: " << function << std::endl
	<< "Test:     " << name << std::endl
	<< "------------------------------------------------------------" << std::endl;
}


void msg(std::string msg) {
	std::cout << ">>> " << msg << " <<<" << std::endl;
}


bool ass(double a, double b = 0) {
	if (std::abs(a - b) < 1.0e-50)
		return true;
	FAIL
}


bool ass(bool a, bool b = 1) {
	if (a == b)
		return true;
	FAIL
}


bool ass(KomplexeZahl a, KomplexeZahl b) {
	if (a == b)
		return true;
	FAIL
}


bool ass(size_t a, size_t b) {
	if (a == b)
		return true;
	FAIL
}



int main() {
	sec("KomplexeZahl, KomplexND", "Programme to test basic functionality of classes");

	sec("Constructor, setters and getters", "KomplexeZahl", "getReal(), getImag(), set*(), ==, !=");
	{
		KomplexeZahl a;
		KomplexeZahl b;
		double r = 3.628375;
		double i = -45678.8765432;
		KomplexeZahl c(r, i);
		ass(a == a);
		ass(a == b);
		ass(a != c);
		ass(b != c);
		a.setReal(r);
		a.setImag(i);
		b.setVal(r, i);
		ass(a.getReal(), r);
		ass(b.getReal(), r);
		ass(c.getReal(), r);
		ass(a.getImag(), i);
		ass(b.getImag(), i);
		ass(c.getImag(), i);
		ass(a == b);
		ass(b == c);
		ass(a == c);
		PASS
	}

	sec("Scalar Multiplication", "KomplexeZahl", "*");
	{
		for (double r = -300.0000002345; r < 301; r += 0.3456) {
			for (double b = -300.2221234; b < 301; b += 0.6835) {
				double i = r / 42;
				KomplexeZahl a(r, i);
				a = a * b;
				ass(a.getReal(), r * b);
				ass(a.getImag(), i * b);
			}
		}
		PASS
	}

	sec("Calculate Magnitude", "KomplexeZahl", "getMag(), toPolar()");
	{
		for (int r = -300; r < 300; ++r) {
			for (int i = -300; i < 300; ++i) {
				KomplexeZahl a(r, i);
				ass(a.getMag(), std::sqrt(r * r + i * i));
				ass(a.toPolar().first, std::sqrt(r * r + i * i));
			}
		}
		PASS
	}

	sec("Calculate Argument", "KomplexeZahl", "getPhi(), toPolar()");
	{
		for (int r = -300; r < 300; ++r) {
			for (int i = -300; i < 300; ++i) {
				KomplexeZahl a(r, i);
				ass(a.getPhi(), std::atan2(i, r));
				ass(a.toPolar().second, std::atan2(i, r));
			}
		}
		PASS
		msg("Testing edge cases");
		for (double i = 0.01; i < 300; ++i) {
			KomplexeZahl a(i, 0);
			ass(a.getPhi(), 0);
		}
		for (double i = 0.01; i < 300; ++i) {
			KomplexeZahl a(0, i);
			ass(a.getPhi(), M_PI / 2);
		}
		for (double i = 0.01; i < 300; ++i) {
			KomplexeZahl a(0, -i);
			ass(a.getPhi(), M_PI / -2);
		}
		for (double i = 0.01; i < 300; ++i) {
			KomplexeZahl a(-i, 0);
			ass(a.getPhi(), M_PI);
		}
		KomplexeZahl b(0, 0);
		ass(b.getPhi(), 0);
		PASS
	}

	sec("Test construction of small vectors", "KomplexND", "Constructor, .at(), =");
	{
		KomplexND a(5);
		KomplexeZahl c(1,1);
		a.at(0) = c;
		a.at(1) = KomplexeZahl(3, 3);
		a.at(2) = KomplexeZahl(1.14, 3.1415962);
		a[3] = a[2];
		a[4] = a.at(0);
		ass(a[0], c);
		ass(a[1], KomplexeZahl(3, 3));
		ass(a[2], KomplexeZahl(1.14, 3.1415962));
		ass(a[3], KomplexeZahl(1.14, 3.1415962));
		ass(a[4], c);
		PASS
	}

	sec("Test size function vectors", "KomplexND", ".size()");
	{
		for(unsigned int i = 0; i < 2000; ++i) {
			KomplexND a(i);
			ass(a.size(), i);
		}
		PASS
	}

	sec("Test construction of large vectors", "KomplexND", "Constructor, .at(), =");
	{
		msg("THIS MAY REQUIRE SOME AMOUNT OF MEMORY!");
		msg("Construct large vector");
		KomplexND a(99999999);
		msg("Fill vector with complex numbers");
		for(unsigned int i = 0; i < a.size(); ++i) {
			a.at(i) = KomplexeZahl(i, i + 1);
		}
		{
			msg("Do something else for a while");
			for(unsigned int i = 0; i < 1000; ++i) {
				KomplexND b(20000);
				b[i] = KomplexeZahl(i, i * 1.119);
			}
		}
		msg("Test accessibility and value of every element");
		for(unsigned int i = 0; i < a.size(); ++i) {
			ass(a.at(i), KomplexeZahl(i, i + 1));
		}
		PASS
	}

	sec("Test addition of large vectors", "KomplexND, KomplexeZahl", "=, +");
	{
		msg("THIS MAY REQUIRE SOME AMOUNT OF MEMORY!");
		msg("Construct 1. large vector");
		KomplexND a(99999999);
		msg("Fill vector with complex numbers");
		for(unsigned int i = 0; i < a.size(); ++i) {
			a.at(i) = KomplexeZahl(i, i + 1);
		}
		msg("Construct 2. large vector");
		KomplexND b(a.size());
		msg("Fill vector with complex numbers");
		for(unsigned int i = 0; i < b.size(); ++i) {
			b.at(i) = KomplexeZahl(i + 2, i + 3);
		}
		msg("Construct 3. large vector");
		KomplexND c(b.size());
		msg("Add previous vectors and store result");
		c = a + b;
		msg("Check if results are correct");
		for(unsigned int i = 0; i < c.size(); ++i) {
			ass(c.at(i), KomplexeZahl(2 * i + 2, 2 * i + 4));
		}
		PASS
	}

	sec("2. test addition of large vectors", "KomplexND, KomplexeZahl", "=, +");
	{
		msg("THIS MAY REQUIRE SOME AMOUNT OF MEMORY!");
		msg("Construct 1. large vector");
		KomplexND a(99999999);
		msg("Fill vector with complex numbers");
		for(unsigned int i = 0; i < a.size(); ++i) {
			a.at(i) = KomplexeZahl(i, i + 1);
		}
		msg("Construct 2. large vector");
		KomplexND b(a.size());
		msg("Fill vector with complex numbers");
		for(unsigned int i = 0; i < b.size(); ++i) {
			b.at(i) = KomplexeZahl(i + 2, i + 3);
		}
		msg("Construct 3. large vector and store result");
		KomplexND c = a + b;
		msg("Check if results are correct");
		for(unsigned int i = 0; i < c.size(); ++i) {
			ass(c.at(i), KomplexeZahl(2 * i + 2, 2 * i + 4));
		}
		PASS
	}


	sec("Input / Output", "KomplexeZahl", "<<, >>");
	{
		msg("Testing human input");
		KomplexeZahl a;
		try {
			for (int i = 1; i <= 5; ++i) {
				msg("Input a complex number e.g.: ( 3.14159  -7.6666666 )");
				std::cout << i << "/5 > ";
				std::cin >> a;
				std::cout << ">> " << a << std::endl;
			}
		} catch(...) {
			FAIL
		}
		PASS
	}
	msg("All tests passed (hopefully with flying colours)! Exiting.");
	return 0;
}

