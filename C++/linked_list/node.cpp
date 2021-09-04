#include "node.hpp"

//Constructor
Node::Node()
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