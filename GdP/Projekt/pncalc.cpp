#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "komplex.hpp"

/*
 * Simple (forward) polish / prefix notation calculator using class KomplexeZahl
 * to test basic functionality of said class, evaluate simple equations and conversions.
 *
 * Supported operations:	{+, -, *} KomplexeZahl KomplexeZahl
 *							{+, -, *} KomplexeZahl double (will be converted to real part)
 *
 * Supported Conversions:	>polar		Return polar coordinates as complex number
 *										real part		= magnitude
 *										imaginary part	= argument in radians
 *							>mag		Return magnitude as complex number (real part)
 *							>phi		Return argument as complex number (real part)
 *
 * Input format:	complex number:	4.5 - 2.445*i --> ( 4.5 -2.445 )
 *					real number:	42
 * 
 * Tab stop >|<
 * 			 ^
 */



// Print error message and exit; tries to guess unexpected symbol (which is not always correct)
#define UNEXP std::cout << "Unexpected symbol: \"" << peek << "\". Cannot continue." << std::endl; exit(-1);



// Prototypes
KomplexeZahl calc(std::istream &str);
KomplexeZahl conv(std::istream &str);



KomplexeZahl calc(std::istream &str) {
	char peek;
	while((peek = str.peek()) == ' ') {		// get first char of stream
		str.get();							// until it is not a space
	}
	switch(peek) {
		case '+':							// recurse if operator is selected
			str.get();
			return calc(str) + calc(str);
		case '-':
			str.get();
			return calc(str) - calc(str);
		case '*':
			str.get();
			return calc(str) * calc(str);
		case '>':							// conversion operator selected
			str.get();
			return conv(str);
		case '(':
			try {
				KomplexeZahl num;			// try to read complex number in from stream
				str >> num;
				return num;
			} catch (...) {}				// if it fails continue to -1
		case -1:							// if EOF is reached
			UNEXP							// Output error message and exit
		default:
			try {
				double num = 0;				// try to read double in
				str >> num;					// convert double to real part of
				return KomplexeZahl(num);	// complex number to return
			} catch (...) {
				UNEXP						// Output error message and exit
			}
	}
}


// Conversion operators
KomplexeZahl conv(std::istream &str) {
	std::string a;
	str >> a;
	/**
	 * Convert to polar coordinates and return
	 * as KomplexeZahl to match return data type.
	 * Real will equate to the magnitude and imag to
	 * the argument of given complex number.
	 *
	 * Switch-Cases apparently don't like strings...
	 */
	if (a == "polar") {
		std::pair<double, double> polar = calc(str).toPolar();
		return KomplexeZahl(polar.first, polar.second);
	}
	// Return magnitude in real part
	if (a == "mag") {
		return KomplexeZahl(calc(str).getMag());
	}
	// Return argument in real part
	if (a == "phi") {
		return KomplexeZahl(calc(str).getPhi());
	}
	// Test if numbers are equal; return boolean value as real part
	if (a == "=") {
		return KomplexeZahl(calc(str) == calc(str));
	}
	// Negate (test if magnitude is greater than 0); return boolean value as real part
	if (a == "!") {
		return KomplexeZahl(!(calc(str).getMag() > 0));
	}
	return KomplexeZahl();	// Invalid operator; return (0 0)
}


int main() {
	std::string input;
	std::cout << "$> ";
	std::getline(std::cin, input);							// Prompt user for input
	std::stringstream input_stream(input);
	std::cout << ">>> " << calc(input_stream) << std::endl;	// Print result
}

