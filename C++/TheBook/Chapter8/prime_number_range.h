#pragma once
#include "prime_number_iterator.h"

struct PrimeNumberRange {
    //Constructor
    PrimeNumberRange(unsigned int max);

    //Essentials: Destructor, Copy and Move Constructors, and Copy and Move Assignment Operators
    ~PrimeNumberRange();
    PrimeNumberRange(const PrimeNumberRange& other);
    PrimeNumberRange(PrimeNumberRange&& other) noexcept;
    PrimeNumberRange& operator=(const PrimeNumberRange& other);
    PrimeNumberRange& operator=(PrimeNumberRange&& other) noexcept;

    //Iterator Methods
    PrimeNumberIterator begin() const;
    unsigned int end() const;

private:
    unsigned int max;
};
