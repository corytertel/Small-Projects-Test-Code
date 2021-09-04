#include <cstdio>
#include <cstdlib>
#include <stdexcept>

int number_5() { return 5; }

int main(int argc, char** argv) {
    int anumber = 5;
    int bnumber = 6;
    anumber += bnumber;

    int hello = 0;

    hello = number_5();

    return 0;
}


