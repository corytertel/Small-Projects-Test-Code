#include <iostream>
#include <iterator>
#include <string>

auto string_length(const std::string& str) -> size_t;

auto main() -> int {
    
    std::string str1{ "Hello world!" };
    std::string str2{ "Goodbye cruel world!" };

    std::cout << "Expected: 12, Got: " << string_length(str1) << "\n";
    std::cout << "Expected: 20, Got: " << string_length(str2) << std::endl;

    return 0;
}

auto string_length(const std::string& str) -> size_t {
    //One way of calculating length wihtout using pointer arithmetic
    //Pointer arithmetic is memory unsafe and could lead to security
    //vulnerabilities, segmentation faults, and undefined behavior
    /*size_t length{};
    for (const auto& c : str) {
        length++;
    }
    return length;*/
    //Another way of calculating length is std::distance which calculates
    //the distance between the first and last iterator
    //std::distance is also more verbose about what you're doing
    return std::distance(str.begin(), str.end());
}