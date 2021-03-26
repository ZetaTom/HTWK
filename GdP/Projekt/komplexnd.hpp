#pragma once
#include "komplex.hpp"

/**
 * Implementation of a complex number (Komplexe Zahl) vector.
 *
 * This is a simple (yet horribly written) class to store and manipulate
 * a vector of complex numbers (KomplexeZahl). Vectors are always
 * allocated with a headroom of 10 items.
 */
class KomplexND {
	KomplexeZahl* array;
	size_t currentCapacity;
	size_t currentSize;

public:
	/**
	 * Construct vector of KomplexeZahl with headroom of 10 items.
	 * @param n size of vector to be initialised
	 */
	KomplexND(const size_t& n = 0);

	/**
	 * Destruct vector: free allocated memory
	 */
	~KomplexND();


	// Setters, getters and miscellaneous functions
	/**
	 * Return current accessible size of vector.
	 * @return current accessible size
	 */
	size_t size() const;

	/**
	 * Return current maximum capacity of vector.
	 * @return current maximum capacity
	 */
	size_t capacity() const;

	/**
	 * @brief Push item on end of vector.
	 *
	 * Push item on the end of given vector.
	 * If the size would exceed the current available capacity
	 * the vector will be copied.
	 *
	 * @note This may take some considerable time and memory!
	 * @param element item to be pushed
	 */
	void push(const KomplexeZahl& element = KomplexeZahl());

	/**
	 * @brief Pop last item of vector.
	 *
	 * The item is made inaccessible by reducing the current
	 * accessible size but not the available capacity.
	 */
	void pop();

	/**
	 * Return complex number at given position.
	 * @pre index must be within accessible range of vector
	 * @throws std::out_of_range thrown if given index is out of range
	 * @param index index of item to be returned
	 * @return item at position
	 */
	KomplexeZahl& at(const size_t& index) const;

	/**
	 * Return complex number at given position.
	 * @see KomplexND::at()
	 * @pre index must be within accessible range of vector
	 * @throws std::out_of_range thrown if given index is out of range
	 * @param index index of item to be returned
	 * @return item at position
	 */
	KomplexeZahl& operator[](const size_t& index) const;


	// Functions to manipulate a whole vector
	/**
	 * @brief Fill KomplexND vector with single element.
	 *
	 * Destructively overwrites every entry in vector
	 * with the given complex number.
	 *
	 * @param element complex number to flood vector with
	 */
	void fill(const KomplexeZahl& element);

	/**
	 * @brief Copy one vector to equal another.
	 *
	 * Destructively copy every entry in vector rhs
	 * to another vector, thus overwriting every element
	 * in the given vector.
	 * 
	 * @pre vectors must be of the same size
	 * @throws std::invalid_argument thrown if given vectors are not equally sized
	 * @param rhs vector to be copied
	 * @return copied vector
	 */
	KomplexND& operator=(const KomplexND& rhs);

	/**
	 * Element wise addition of two complex vectors.
	 * @pre vectors must be of the same size
	 * @throws std::invalid_argument thrown if given vectors are not equally sized
	 * @param rhs complex vector
	 * @return vector containing summed elements
	 */
	KomplexND operator+(const KomplexND& rhs);
};

