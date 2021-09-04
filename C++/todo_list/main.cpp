#include <iostream>
#include <string_view>
#include <vector>
#include <span>
#include "cmdarg.hpp"

auto main(int argc, char** argv) -> int {
    //If no arguments
    if (argc == 1) {
        std::cout << "Usage: todolist [OPTIONS] TYPE GOAL..." << std::endl;
        std::cout << "todolist: error: You must provide at least one goal." << std::endl;
        std::cout << "Type todolist --help to see a list of all options." << std::endl;
        return 1;
    }

    //Helper for safer c-array access
    std::span<char*> args{ argv, size_t(argc) };
    //Container for all flags and their arguments
    std::vector<CmdArg> flags{};
    
    //Check to see if the first flag is valid
    if (args[1][0] != '-') {
        std::cout << "Invalid flag." << std::endl;
        return 1;
    }

    //Add all flags and their arguments to the flags vector
    for (size_t i = 1; i < args.size(); i++) {
        if (args[i][0] == '-') {
            flags.push_back(CmdArg{ std::string_view{ args[i] } });
        }
        else {
            flags.back().add_arg(std::string_view{ args[i] });
        }
    }

    // DEBUG: print out flags and their arguments
    for (const auto& flag : flags) {
        std::cout << flag.get_flag() << "\n";
        for (auto arg : flag.get_args()) {
            std::cout << arg << "\n";
        }
    }

    //Reorder flags in terms of priority


    //Evaluate flags

    return 0;
}
