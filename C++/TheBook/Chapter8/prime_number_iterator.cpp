#include "prime_number_iterator.h"
#include <cmath>

//Constructor
PrimeNumberIterator::PrimeNumberIterator()
: current{ 2 } {}

//Destructor
PrimeNumberIterator::~PrimeNumberIterator() = default;

//Copy Constructor
PrimeNumberIterator::PrimeNumberIterator(const PrimeNumberIterator& other) = default;

//Move Constructor
PrimeNumberIterator::PrimeNumberIterator(PrimeNumberIterator&& other) noexcept = default;

//Copy Assignment Operator
PrimeNumberIterator& PrimeNumberIterator::operator=(const PrimeNumberIterator& other) = default;

//Move Assignment Operator
PrimeNumberIterator& PrimeNumberIterator::operator=(PrimeNumberIterator&& other) noexcept = default;

//Iterator Operators
bool PrimeNumberIterator::operator!=(unsigned int x) const {
    return x >= current;
}

PrimeNumberIterator& PrimeNumberIterator::operator++() {
    current = next_prime();
    return *this;
}

unsigned int PrimeNumberIterator::operator*() const {
    return current;
}

//Calculates next prime number
constexpr unsigned int PrimeNumberIterator::next_prime() {
    double current = this->current + 1;
    while(true) {
        double current_sqrt = ceil(sqrt(current));
        bool is_prime = true;
        
        for (size_t i = 2; i <= current_sqrt; i++) {
            if (current / i == floor(current / i) && i != current) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) { return static_cast<unsigned int>(current); }
        else { current++; }
    }
}
