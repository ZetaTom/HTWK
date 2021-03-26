#pragma once
#include <ostream>
#include <istream>


/**
 * Implementation of a complex number (Komplexe Zahl) data type.
 *
 * This is a simple (yet horribly written) class to store and manipulate
 * complex numbers. Each number consists of two double precision values:
 * a real and an imaginary part. Numbers are formatted as an ordered
 * pair: ( 3 7 ) which equates to 3 + 7i in Cartesian coordinates.
 */
class KomplexeZahl {
	double real, imag;

public:
	/**
	 * Construct a complex number.
	 *
	 * @param realVal double precision real value
	 * @param imagVal double precision imaginary value
	 */
	KomplexeZahl(const double& realVal = 0, const double& imagVal = 0);


	// Setters and getters
	/**
	 * Return real part of complex number.
	 * @return value of real part
	 */
	double getReal() const;

	/**
	 * Return imaginary part of complex number.
	 * @return value of imaginary part
	 */
	double getImag() const;

	/**
	 * @brief Return magnitude of complex number.
	 *
	 * Calculate and return the magnitude
	 * using std::sqrt.
	 *
	 * @return magnitude of complex number
	 */
	double getMag() const;

	/**
	 * @brief Return argument of complex number.
	 *
	 * Calculate and return the argument/phase
	 * in radians using std::atan2 and M_PI.
	 *
	 * @return argument of complex number in radians
	 */
	double getPhi() const;

	/**
	 * @brief Calculate and return polar coordinates of complex number.
	 *
	 * Calculate and return polar coordinates as a pair using
	 * methods getMag() and getPhi()
	 * 
	 * @returns pair< magnitude, argument >
	 */
	std::pair<double, double> toPolar() const;

	/**
	 * Set real part of complex number.
	 * @param val real part
	 */
	void setReal(const double& val);

	/**
	 * Set imaginary part of complex number.
	 * @param val imaginary part
	 */
	void setImag(const double& val);

	/**
	 * Set real and imaginary part at once.
	 * @param realVal real part
	 * @param imagVal imaginary part
	 */
	void setVal(const double& realVal, const double& imagVal);


	// Overload arithmetic maths operators
	/**
	 * Addition of two complex numbers.
	 * @param rhs complex number
	 * @return sum of complex numbers
	 */
	KomplexeZahl operator+(const KomplexeZahl& rhs);

	/**
	 * Subtraction of two complex numbers.
	 * @param rhs complex number
	 * @return difference between complex numbers
	 */
	KomplexeZahl operator-(const KomplexeZahl& rhs);

	/**
	 * Multiplication of two complex numbers.
	 * @param rhs complex number
	 * @return product of complex numbers
	 */
	KomplexeZahl operator*(const KomplexeZahl& rhs);

	/**
	 * Scalar multiplication of complex number with double.
	 * @param rhs scalar
	 * @return product
	 */
	KomplexeZahl operator*(const double& rhs);


	// Overload input / output operators
	/**
	 * Write complex number into stream.
	 * @pre Format: '( real imag )' where real and imag are doubles
	 * @param out_stream output stream (stream to write to)
	 * @param c complex number to output
	 * @return altered stream
	 */
	friend std::ostream& operator<<(std::ostream& out_stream, const KomplexeZahl& c);

	/**
	 * Read complex number from stream into variable.
	 * @pre Format: '( real imag )' where real and imag are doubles
	 * @throws std::invalid_argument thrown if input does not match syntax
	 * @param in_stream input stream (stream to read from)
	 * @param c value to read complex number into
	 * @return altered stream
	 */
	friend std::istream& operator>>(std::istream& in_stream, KomplexeZahl& c);


	/**
	 * @brief Test if two numbers are equal (within margin of error).
	 *
	 * Test whether two double precision numbers are equal by
	 * comparing the difference between them against an epsilon.
	 * 
	 * @param lhs first number to compare
	 * @param rhs second number to compare
	 * @param epsilon margin of error to consider provided numbers equal
	 * @return true if difference between given numbers is less than epsilon
	 */
	static bool isEqual(const double& lhs, const double rhs = 0, const double& epsilon = 1.0e-50);
};



/**
 * Scalar multiplication of complex number (KomplexeZahl) with double.
 * @see KomplexeZahl KomplexeZahl::operator*(const double&)
 * @param rhs complex Number (KomplexeZahl)
 * @return product
 */
KomplexeZahl operator*(const double& lhs, KomplexeZahl& rhs);


/**
 * @brief Test if two complex numbers are equal.
 *
 * Test if two complex numbers (KomplexeZahl) are equal by comparing
 * their corresponding real and imaginary parts.
 * 
 * @return true if complex numbers are equal
 */
bool operator==(const KomplexeZahl& lhs, const KomplexeZahl& rhs);

/**
 * @brief Test if two complex numbers are not equal.
 *
 * Test if two complex numbers (KomplexeZahl) are not equal by
 * comparing their corresponding real and imaginary parts.
 * 
 * @see operator==(const KomplexeZahl&, const KomplexeZahl&)
 * @return false if complex numbers are equal
 */
bool operator!=(const KomplexeZahl& lhs, const KomplexeZahl& rhs);

