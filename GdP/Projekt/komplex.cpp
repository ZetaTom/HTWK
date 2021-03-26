#include "komplex.hpp"
#include <cmath>

KomplexeZahl::KomplexeZahl(const double& realVal, const double& imagVal) {
	this->real = realVal;
	this->imag = imagVal;
}


double KomplexeZahl::getReal() const {
	return real;
}


double KomplexeZahl::getImag() const {
	return imag;
}


double KomplexeZahl::getMag() const {
	return std::sqrt(real * real + imag * imag);
	// return magnitude: z = sqrt(real^2 + imag^2)
}


double KomplexeZahl::getPhi() const {
	return std::atan2(imag, real);
	// return angle: phi = arctan(imag / real)
	// atan2 to catch division by 0
}


std::pair<double, double> KomplexeZahl::toPolar() const{
	return {getMag(), getPhi()};
	// return generalised initialiser list (c++11) to build pair
}


void KomplexeZahl::setReal(const double& val) {
	real = val;
}


void KomplexeZahl::setImag(const double& val) {
	imag = val;
}


void KomplexeZahl::setVal(const double& realVal, const double& imagVal) {
	real = realVal;
	imag = imagVal;
}


KomplexeZahl KomplexeZahl::operator+(const KomplexeZahl& rhs) {
	return KomplexeZahl(this->real + rhs.real, this->imag + rhs.imag);
	// *this refers to lhs (lhs + rhs)
	// add real parts, add imaginary parts and return new instance
}


// NOT PART OF SPECIFICATION
KomplexeZahl KomplexeZahl::operator-(const KomplexeZahl& rhs) {
	return KomplexeZahl(this->real - rhs.real, this->imag - rhs.imag);
}


KomplexeZahl KomplexeZahl::operator*(const KomplexeZahl& rhs) {
	KomplexeZahl result;
	result.setReal(this->real * rhs.real - this->imag * rhs.imag);
	result.setImag(this->real * rhs.imag + rhs.real * this->imag);
	return result;
	// *this refers to lhs (lhs + rhs)
	// multiply according to multiplication scheme and
	// return as new instance
}


KomplexeZahl KomplexeZahl::operator*(const double& rhs) {
	return KomplexeZahl(this->real * rhs, this->imag * rhs);
}


KomplexeZahl operator*(const double& lhs, KomplexeZahl& rhs) {
	return rhs * lhs;
	// reverse order (commutative)
}


std::ostream& operator<<(std::ostream& out_stream, const KomplexeZahl& c) {
	out_stream << "( " << c.real << ' ' << c.imag << " )";
	return out_stream;
}


std::istream& operator>>(std::istream& in_stream, KomplexeZahl& c) {
	char parenth[2];												// allocate array for parenthesis
	double realVal, imagVal;
	in_stream >> parenth[0] >> realVal >> imagVal >> parenth[1];	// read complex number from stream
	if (parenth[0] != '(' || parenth[1] != ')')						// if input does not match correct syntax
		throw std::invalid_argument("Expected: KomplexeZahl << ( double double )!");
	c.setVal(realVal, imagVal);										// if it does set number to corresponding value
	return in_stream;
}


bool KomplexeZahl::isEqual(const double& lhs, const double rhs, const double& epsilon) {
	return std::abs(lhs - rhs) < epsilon;
}


// NOT PART OF SPECIFICATION but useful for testing
bool operator==(const KomplexeZahl& lhs, const KomplexeZahl& rhs) {
	return (KomplexeZahl::isEqual(lhs.getReal(), rhs.getReal()) && KomplexeZahl::isEqual(lhs.getImag(), rhs.getImag()));
	// test if corresponding real and corresponding imaginary parts are equal
}


// NOT PART OF SPECIFICATION
bool operator!=(const KomplexeZahl& lhs, const KomplexeZahl& rhs) {
	return !(lhs == rhs);
}

