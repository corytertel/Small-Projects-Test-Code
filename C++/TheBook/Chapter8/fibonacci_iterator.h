#pragma once
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

struct FibonacciIterator {
    //Constructor
    FibonacciIterator();

    //Essentials: Destructor, Copy and Move Constructors, and Copy and Move Assignment Operators
    ~FibonacciIterator();
    FibonacciIterator(const FibonacciIterator& other);
    FibonacciIterator(FibonacciIterator&& other) noexcept;
    FibonacciIterator& operator=(const FibonacciIterator& other);
    FibonacciIterator& operator=(FibonacciIterator&& other) noexcept;

    //Iterator Operators
    bool operator!=(int x) const;
    FibonacciIterator& operator++();
    int operator*() const;

private:
    int current;
    int last;
};
