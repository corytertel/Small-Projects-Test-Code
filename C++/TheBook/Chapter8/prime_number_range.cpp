#include "prime_number_range.h"

//Constructor
PrimeNumberRange::PrimeNumberRange(unsigned int max)
: max{ max } {}

//Destructor
PrimeNumberRange::~PrimeNumberRange() = default;

//Copy Constructor
PrimeNumberRange::PrimeNumberRange(const PrimeNumberRange& other) = default;

//Move Constructor
PrimeNumberRange::PrimeNumberRange(PrimeNumberRange&& other) noexcept = default;

//Copy Assignment Operator
PrimeNumberRange& PrimeNumberRange::operator=(const PrimeNumberRange& other) = default;

//Move Assignment Operator
PrimeNumberRange& PrimeNumberRange::operator=(PrimeNumberRange&& other) noexcept = default;

//Iterator Methods
PrimeNumberIterator PrimeNumberRange::begin() const {
    return PrimeNumberIterator{};
}

unsigned int PrimeNumberRange::end() const {
   return max; 
}
