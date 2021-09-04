#include "goal.hpp"

//Constructor
Goal::Goal(GoalType type, std::string msg)
: type{ type }, msg{ msg } {}

//Destructor
Goal::~Goal() = default;

//Copy Constructor
Goal::Goal(const Goal& other) = default;

//Move Constructor
Goal::Goal(Goal&& other) noexcept = default;

//Copy Assignment Operator
Goal& Goal::operator=(const Goal& other) = default;

//Move Assignment Operator
Goal& Goal::operator=(Goal&& other) noexcept = default;

