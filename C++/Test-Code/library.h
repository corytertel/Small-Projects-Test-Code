#pragma once
#include <string>
#include <vector>

template<typename T>
concept App = requires(T a) {
    {a.name} -> std::convertible_to<std::string>;
    {a.launch()} -> std::convertible_to<bool>;
}

template<App T>
struct Library {
    std::vector<App> apps;
}
