#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct TimerClass {
    //Constructor
    TimerClass(const char* name, unsigned int current_time)
        : timestamp{ current_time }, 
        current_time{ current_time } {
            this->name = new char[strlen(name)];
            std::strncpy(this->name, name, strlen(name));
        }

    //Copy Constructor
    TimerClass(const TimerClass& other)
        : timestamp{ other.timestamp }, 
        current_time{ other.current_time } {
            this->name = new char[strlen(other.name)];
            std::strncpy(this->name, other.name, strlen(other.name));
    }

    //Move Constructor
    TimerClass(TimerClass&& other) noexcept
        : name{ other.name },
        timestamp{ other.timestamp }, 
        current_time{ other.current_time } {
            other.name = nullptr;
            other.timestamp = 0;
            other.current_time = 0;
    }

    //Copy Assignment Operator
    TimerClass operator=(const TimerClass& other) {
        if (this == &other) return *this;
        delete[] this->name;
        this->name = new char[strlen(other.name)];
        std::strncpy(this->name, other.name, strlen(other.name));
        this->timestamp = other.timestamp;
        this->current_time = other.current_time;
        return *this;
    }
    
    //Move Assignment Operator
    TimerClass operator=(TimerClass&& other) noexcept {
        if (this == &other) return *this;
        delete[] this->name;
        this->name = other.name;
        this->timestamp = other.timestamp;
        this->current_time = other.current_time;
        other.name = nullptr;
        other.timestamp = 0;
        other.current_time = 0;
        return *this;
    }

    //Destructor
    ~TimerClass() {
        if(this->name != nullptr) {
            printf("Age of Timer %s: %d\n", name, current_time - timestamp);
            delete[] name;
        }
    }

    void set_current_time(unsigned int current_time) noexcept {
        this->current_time = current_time;
    }

private:
    char* name;
    unsigned int timestamp;
    unsigned int current_time;
};

int main(int argc, char** argv) {
    TimerClass timer1{ "timer1", 0 };
    TimerClass timer2{ "timer2", 0 };

    //Race starts

    //Runner 1 finishes
    timer1.set_current_time(20);

    //Runner 2 finishes
    timer2.set_current_time(30);

    //Timer1 Copy
    TimerClass timer3{ timer1 };

    //Timer2 Copy
    TimerClass timer4{ timer2 };

    //Move Timer1 into Timer5
    TimerClass timer5{ std::move(timer1) };

    //Move Timer2 into Timer6
    TimerClass timer6{ std::move(timer2) };

    timer3.set_current_time(40);
    timer4.set_current_time(50);

}




















