#include <cstdio>
#include <cstdlib>
#include <stdexcept>

struct UnsignedBigInteger {
    //Constructors
    UnsignedBigInteger()
        : small_half{},
        large_half{} {}

    template<typename T>
        requires std::is_integral<T>::value
    UnsignedBigInteger(T data) {
        small_half = static_cast<unsigned long long>(data);
        large_half = 0;
    }

    template<typename T>
        requires std::is_integral<T>::value
    UnsignedBigInteger(T large_half, T small_half) {
        small_half = static_cast<unsigned long long>(small_half);
        large_half = static_cast<unsigned long long>(large_half);
    }
    /*UnsignedBigInteger()
        : data{} {}

    template<size_t Length>
    UnsignedBigInteger(const uint8_t* data) {
        static_assert(Length <= 16, "Data is too large");
        for (size_t i = 0; i < Length; i++) {
            this->data[i] = data[i];
        }
    }

    template<typename T>
        requires std::is_integral<T>::value
    UnsignedBigInteger(T data) {
        static_assert(data > 0, "Data is less than zero");
        size_t data_size = sizeof(data);
        this->data{};
        for (size_t i = 0; i < 16; i++) {
            this->data[i] = data >> 15 * 8
        }
    }*/
    
    //Destructor
    ~UnsignedBigInteger() = default;

    //Copy Constructor
    UnsignedBigInteger(const UnsignedBigInteger& other) = default;

    //Move Constructor
    UnsignedBigInteger(UnsignedBigInteger&& other) noexcept = default;

    //Copy Assignment Operator
    UnsignedBigInteger& operator=(const UnsignedBigInteger& other) = default;

    //Move Assignment Operator
    UnsignedBigInteger& operator=(UnsignedBigInteger&& other) noexcept = default;

    //Methods
    void max() {
        small_half = -1;
        large_half = -1;
    }
    
    void min() {
        small_half = 0;
        large_half = 0;
    }

    void print() const noexcept {
        printf("%llu%llu\n", large_half, small_half);
    }

    //Getter for small_half
    unsigned long long get_small_half() const {
        return this->small_half;
    }

    //Getter for large_half
    unsigned long long get_large_half() const {
        return this->large_half;
    }

    //Setter for small_half
    void set_small_half(unsigned long long new_var) {
        this->small_half = new_var;
    }

    //Setter for large_half
    void set_large_half(unsigned long long new_var) {
        this->large_half = new_var;
    }

    //Operator Overloads
    UnsignedBigInteger operator+(UnsignedBigInteger other) const {
        UnsignedBigInteger result{};
        
        result.set_large_half(this->get_large_half() + other.get_large_half());
        result.set_small_half(this->get_small_half() + other.get_small_half());

        if (result.get_small_half() < this->get_small_half()) {
            //overflow occured
            result.set_large_half(result.get_large_half() + 1);
        }

        if (result.get_large_half() < this->get_large_half()) {
            //overflow occured
            throw std::runtime_error{ "Overflow occured" };
        }

        return result;
    }
    


private:
    //uint8_t data[16];
    unsigned long long small_half;
    unsigned long long large_half;
};


int main(int argc, char** argv) {
    UnsignedBigInteger num1{ 20203040 };
    UnsignedBigInteger num2{ 6084039, 28310830 };
    UnsignedBigInteger num3{ num1 + num2 };
    num3.print();
    UnsignedBigInteger num4{};
    num4.max();
    num4.print();
    return 0;
}
