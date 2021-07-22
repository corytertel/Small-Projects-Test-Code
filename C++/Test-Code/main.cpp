#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <iostream>

template<typename T>
concept Integer = std::is_integral<T>::value;

struct App {
    App() = default;
    virtual ~App();

    virtual bool launch() const;
};

struct SteamApp : App {
    SteamApp() = default;
    ~SteamApp();

    bool launch() const override {
        return true;
    }
};


int main(int argc, char** argv) {
    try {
        SteamApp steam_app{};
        App* app{ &steam_app };
        int int_app{};
        App* app2{ &int_app };
    }
    catch (const std::exception e) {
        std::cout << e << std::endl;
    }
    return 0;
}
