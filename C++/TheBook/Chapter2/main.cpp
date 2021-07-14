#include <cstdio>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide,
};

struct Calculator {
    Calculator(Operation o) : 
        op{o} {}

    int calculate(int a, int b) {
        switch(op) {
            case Operation::Add: {
                return a + b;
            } break;
            case Operation::Subtract: {
                return a - b;
            } break;
            case Operation::Multiply: {
                return a * b;
            } break;
            case Operation::Divide: {
                return a / b;
            } break;
            default: {
                printf("Unknown Operation");
                return 0;
            }
        }
    }
private:
    Operation op;
};

int main(int argc, char** argv) {
    Calculator adder{ Operation::Add };
    Calculator subber{ Operation::Subtract };
    Calculator multiplier{ Operation::Multiply };
    Calculator divider{ Operation::Divide };

    printf("%d\n", adder.calculate(1, 2));
    printf("%d\n", subber.calculate(1, 2));
    printf("%d\n", multiplier.calculate(3, 4));
    printf("%d\n", divider.calculate(9, 3));

    return 0;
}
