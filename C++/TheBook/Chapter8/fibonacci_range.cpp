#include "fibonacci_range.h"

//Constructor
FibonacciRange::FibonacciRange(int max)
: max{ max } {}

//Destructor
FibonacciRange::~FibonacciRange() = default;

//Copy Constructor
FibonacciRange::FibonacciRange(const FibonacciRange& other) = default;

//Move Constructor
FibonacciRange::FibonacciRange(FibonacciRange&& other) noexcept = default;

//Iterator Methods
FibonacciIterator FibonacciRange::begin() const {
    return FibonacciIterator{};
}

int FibonacciRange::end() const {
    return max;
}


