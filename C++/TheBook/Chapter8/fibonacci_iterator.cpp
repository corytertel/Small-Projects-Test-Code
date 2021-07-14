#include "fibonacci_iterator.h"

//Constructor
FibonacciIterator::FibonacciIterator()
: current{ 1 }, last{ 1 } {}

//Destructor
FibonacciIterator::~FibonacciIterator() = default;

//Copy Constructor
FibonacciIterator::FibonacciIterator(const FibonacciIterator& other) = default;

//Move Constructor
FibonacciIterator::FibonacciIterator(FibonacciIterator&& other) noexcept = default;

//Copy Assignment Operator
FibonacciIterator& FibonacciIterator::operator=(const FibonacciIterator& other) = default;

//Move Assignment Operator
FibonacciIterator& FibonacciIterator::operator=(FibonacciIterator&& other) noexcept = default;

//Iterator Operators
bool FibonacciIterator::operator!=(int x) const {
    return x >= current;
}

FibonacciIterator& FibonacciIterator::operator++() {
    const auto tmp = current;
    current += last;
    last = tmp;
    return *this;
}

int FibonacciIterator::operator*() const {
    return current;
}
