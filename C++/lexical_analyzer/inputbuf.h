#pragma once
#include <string>
#include <vector>

struct InputBuffer {
    void get_char(char&);
    auto unget_char(char) -> char;
    auto unget_string(std::string) -> std::string;
    auto end_of_input() -> bool;

private:
    std::vector<char> input_buffer;
};
