#pragma once

struct Node {
    //Constructor
    Node();
    
    //Essentials: Destructor, Copy and Move Constructors, and Copy and Move Assignment Operators
    ~Node();
    Node(const Node& other);
    Node(Node&& other) noexcept;
    Node& operator=(const Node& other);
    Node& operator=(Node&& other) noexcept;

private:
    
};