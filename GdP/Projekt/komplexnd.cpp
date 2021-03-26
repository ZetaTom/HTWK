#include "komplexnd.hpp"

KomplexND::KomplexND(const size_t& n) {
	currentSize = n;							// set current accessible size
	currentCapacity = currentSize + 10;			// reserve extra capacity to
	array = new KomplexeZahl[currentCapacity];	// avoid copying vectors
}


KomplexND::~KomplexND() {
	delete[] array;
}


size_t KomplexND::size() const {
	return currentSize;
}


size_t KomplexND::capacity() const {
	return currentCapacity;
}


// NOT PART OF SPECIFICATION
void KomplexND::push(const KomplexeZahl& element) {
	if (currentSize == currentCapacity) {						// if maximum capacity is reached
		currentCapacity += 10;									// increase capacity; add some headroom
		KomplexeZahl* tmp = new KomplexeZahl[currentCapacity];
		for(size_t index = 0; index < currentSize; ++index) {	// copy old array
			tmp[index] = array[index];
		}
		delete[] array;
		array = tmp;											// replace and free old array
	}
	array[currentSize] = element;		// add element at last accessible index
	currentSize++;
}


// NOT PART OF SPECIFICATION
void KomplexND::pop() {
	if (currentSize != 0)	// avoid negative sizes (although that might be fun)
		currentSize--;
}


KomplexeZahl& KomplexND::at(const size_t& index) const {
	if (index >= currentSize)
		throw std::out_of_range("Index out of range in KomplexND!");
	return array[index];
}


KomplexeZahl& KomplexND::operator[](const size_t& index) const {
	return this->at(index);
	// this refers to lhs as in lhs[index]; reuse at() method
}


// NOT PART OF SPECIFICATION
void KomplexND::fill(const KomplexeZahl& element) {
	for(size_t index = 0; index < currentSize; ++index) {
		array[index] = element;
	}
}


KomplexND& KomplexND::operator=(const KomplexND& rhs) {
	if (this->size() != rhs.size())
		throw std::invalid_argument("Vectors must be of same size!");
	for(size_t index = 0; index < this->size(); ++index) {
		this->at(index) = rhs.at(index);
	}
	return *this;
}


KomplexND KomplexND::operator+(const KomplexND& rhs) {
	if (this->size() != rhs.size())
		throw std::invalid_argument("Vectors must be of same size!");
	KomplexND result(this->size());										// create new result vector of same size
	for(size_t index = 0; index < result.size(); ++index) {				// iterate over every element
		result.array[index] = this->array[index] + rhs.array[index];	// add them togeher
	}
	return result;
}

