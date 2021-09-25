#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <cstdio>

#include "inputbuf.h"

auto InputBuffer::end_of_input() -> bool {
    if (!input_buffer.empty())
        return false;
    else
        return std::cin.eof();
}

auto InputBuffer::unget_char(char c) -> char {
    if (c != EOF)
        input_buffer.push_back(c);;
    return c;
}

void InputBuffer::get_char(char& c) {
    if (!input_buffer.empty()) {
        c = input_buffer.back();
        input_buffer.pop_back();
    } else {
        std::cin.get(c);
    }
}

auto InputBuffer::unget_string(std::string s) -> std::string {
    for (size_t i = 0; i < s.size(); i++)
        input_buffer.push_back(s[s.size()-i-1]);
    return s;
}
