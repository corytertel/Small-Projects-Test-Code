#include "linked_list.hpp"

//Constructor
LinkedList::LinkedList()
: {
    
}

//Destructor
LinkedList::~LinkedList() = default;

//Copy Constructor
LinkedList::LinkedList(const LinkedList& other) = default;

//Move Constructor
LinkedList::LinkedList(LinkedList&& other) noexcept = default;

//Copy Assignment Operator
LinkedList& LinkedList::operator=(const LinkedList& other) = default;

//Move Assignment Operator
LinkedList& LinkedList::operator=(LinkedList&& other) noexcept = default;