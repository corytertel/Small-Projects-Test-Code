#pragma once
#include <string>

enum class GoalType {
    NORMAL,
    HIGH_PRIORITY,
    LOW_PRIORITY
};

struct Goal {
    //Constructor
    Goal(GoalType type, std::string msg);
    
    //Essentials: Destructor, Copy and Move Constructors, and Copy and Move Assignment Operators
    ~Goal();
    Goal(const Goal& other);
    Goal(Goal&& other) noexcept;
    Goal& operator=(const Goal& other);
    Goal& operator=(Goal&& other) noexcept;
    
private:
    GoalType type;
    std::string msg;
};