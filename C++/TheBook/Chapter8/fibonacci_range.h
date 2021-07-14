#pragma once
#include <cstdio>
#include "fibonacci_iterator.h"

struct FibonacciRange {
    //Constructor
    FibonacciRange(int max);

    //Essentials: Destructor, Copy and Move Constructors, and Copy and Move Assignment Operators
    ~FibonacciRange();
    FibonacciRange(const FibonacciRange& other);
    FibonacciRange(FibonacciRange&& other) noexcept;

    //Iterator Methods
    FibonacciIterator begin() const;
    int end() const;

private:
    const int max;
};

