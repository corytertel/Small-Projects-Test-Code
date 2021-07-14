#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct SimpleString {
    //Constructor
    SimpleString(const char* str)
        : length{ strlen(str) },
        capacity{ strlen(str) } {
        string = new char[capacity];
        std::strncpy(string, str, length);
    }

    //Destructor
    ~SimpleString() {
        delete[] string;        
    }

    //Copy Construction
    SimpleString(const SimpleString& other) 
        : length{ other.length },
        capacity{ other.capacity } {
        string = new char[capacity];    
        std::strncpy(string, other.string, length);
    }

    //Move Construction
    SimpleString(SimpleString&& other) noexcept
        : string{ other.string },
        length{ other.length },
        capacity{ other.capacity } {
        other.string = nullptr;
        other.length = 0;
        other.capacity = 0;
    }

    //Copy Assignment Operator
    SimpleString& operator=(const SimpleString& other) {
        length = other.length;
        capacity = other.capacity;
        delete[] string;
        string = new char[capacity];
        strncpy(string, other.string, other.length);
        return *this;
    }

    //Move Assignment Operator
    SimpleString& operator=(SimpleString&& other) noexcept {
        length = other.length;
        capacity = other.capacity;
        delete[] string;
        string = other.string;
        other.length = 0;
        other.capacity = 0;
        other.string = nullptr;
        return *this;
    }

    void debug() noexcept {
        printf("String: %s\nLength: %zu\nCapacity: %zu", string, length, capacity);
    }

private:
    char* string;
    size_t length;
    size_t capacity;
};

int main(int argc, char** argv) {
    SimpleString string1{ "Hello world!" };
    string1.debug();
    return 0;
}


