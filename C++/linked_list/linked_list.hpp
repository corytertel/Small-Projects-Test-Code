#pragma once
#include <cstddef>
#include <array>
#include "node.hpp"

template <typename T>
struct LinkedList {
    //Constructor
    LinkedList();
    LinkedList(std::array existing_list);
    
    //Essentials: Destructor, Copy and Move Constructors, and Copy and Move Assignment Operators
    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept;
    LinkedList& operator=(const LinkedList& other);
    LinkedList& operator=(LinkedList&& other) noexcept;
    #include ".h"
    
    //Constructor
    Node()
    : {
        
    }
    
    //Destructor
    Node::~Node() = default;
    
    //Copy Constructor
    Node::Node(const Node& other) = default;
    
    //Move Constructor
    Node::Node(Node&& other) noexcept = default;
    
    //Copy Assignment Operator
    Node& Node::operator=(const Node& other) = default;
    
    //Move Assignment Operator
    Node& Node::operator=(Node&& other) noexcept = default;

    //Overload Bracket Operator
    Node& operator[](size_t index) const;
    
private:
    
};