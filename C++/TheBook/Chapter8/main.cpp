#include <cstdio>
#include "fibonacci_range.h"
#include "prime_number_range.h"

int main(int argc, char** argv) {
    printf("Fibonacci Numbers till 5000\n");
    for (const auto num : FibonacciRange{ 5000 }) {
        printf("%d\n", num);
    } 

    printf("Prime Numbers till 5000\n");
    for (const auto num : PrimeNumberRange{ 5000 }) {
        printf("%d\n", num);
    }

    return 0;
}
