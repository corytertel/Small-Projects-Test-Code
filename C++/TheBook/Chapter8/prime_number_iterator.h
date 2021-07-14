#pragma once

struct PrimeNumberIterator {
    //Constructor
    PrimeNumberIterator();

    //Essentials: Destructor, Copy and Move Constructors, and Copy and Move Assignment Operators
    ~PrimeNumberIterator();
    PrimeNumberIterator(const PrimeNumberIterator& other);
    PrimeNumberIterator(PrimeNumberIterator&& other) noexcept;
    PrimeNumberIterator& operator=(const PrimeNumberIterator& other);
    PrimeNumberIterator& operator=(PrimeNumberIterator&& other) noexcept;

    //Iterator Operators
    bool operator!=(unsigned int x) const;
    PrimeNumberIterator& operator++();
    unsigned int operator*() const;

private:
    constexpr unsigned int next_prime();

    unsigned int current;
};
