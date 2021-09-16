#include <cstddef>
#include <iostream>
#include <string>
#include <functional>

auto add(int x, int y) -> int {
    return x + y;
}

auto subtract(int x, int y) -> int {
    return x - y;
}

struct Printer {
    Printer(std::string name) : name{ name } {}

    void operator()(std::string text_to_print) {
        std::cout << name << " : " << text_to_print << std::endl;
    }

private:
    std::string name;
};

template <typename Fn>
void transform(Fn fn, const int* in, int* out, size_t length) {
    for (size_t i = 0; i < length; i++) {
        out[i] = fn(in[i]);    
    }
}

template <typename Fn, typename T>
void transform2(Fn fn, const T* in, T* out, size_t length) {
    for (size_t i = 0; i < length; i++) {
        out[i] = fn(in[i]);    
    }
}

void static_func() {
    printf("A static function.\n");
}

auto main(int argc, char** argv) -> int {
    
    //Basic Function Pointers
    const int first{ 100 };
    const int second{ 20 };

    auto (*operation)(int, int) -> int {};
    //printf("operation initialized to 0x%p\n", operation);

    operation = &add;
    //printf("&add = 0x%p\n", operation);
    printf("%d + %d = %d\n", first, second, operation(first, second));
    
    operation = &subtract;
    //printf("&add = 0x%p\n", operation);
    printf("%d - %d = %d\n", first, second, operation(first, second));

    //useful if using many function pointers of the same type
    //declares the "type" of function pointer. usage stays the same
    using operation_func = int(*)(int, int);

    operation_func operation2{};
    operation = &add;
    operation = &subtract;


    //The Function Call Operator
    //used to make user-defined types invocable like a function
    //called a function type. objects are called function-objects
    Printer printer{ "The Printer" };
    printer("Hello world!");
    printer("Goodbye cruel world!");

    
    //Lambda Expressions
    //[captures] (parameters) modifiers -> return-type { body }
    //[](int x) { return x * x; }
    {
        const size_t len{ 3 };
        int base[]{ 1, 2, 3 }, a[len], b[len], c[len];
        transform([](int x) { return 1; }, base, a, len);
        transform([](int x) { return x; }, base, b, len);
        transform([](int x) { return 10 * x + 5; }, base, c, len);
        for (size_t i = 0; i < len; i++) {
            printf("Element %zu: %d %d %d\n", i, a[i], b[i], c[i]);
        }
    }

    //default arguments
    auto increment = [](auto x, int y = 1) { return x + y; };
    printf("increment(10)    = %d\n", increment(10));
    printf("increment(10, 5) = %d\n", increment(10, 5));

    //generic lambdas
    {
        constexpr size_t len{ 3 };
        int base_int[]{ 1, 2, 3 }, a[len];
        float base_float[]{ 10.f, 20.f, 30.f }, b[len];
        auto translate = [](auto x) { return 10 * x + 5; };
        transform2(translate, base_int, a, len);
        transform2(translate, base_float, b, len);

        for (size_t i = 0; i < len; i++) {
            printf("Element %zu: %d %f\n", i, a[i], b[i]);    
        }
    }

    //explicitly defined return types are useful for when a specific
    //return type is known and wanted
    // [](auto x, double y) -> decltype(x+y) { return x + y; }
    // rarely will return types need to be explicitly declared
    // but useful for verbosity

    //Lambda captures
    //captures can capture by reference or value, by default it's capture by value
    //similar to a function type's constructor
    //kind of like a argument that is pre-defined so it doesn't need to be defined later
    {
        char to_count{ 's' };
        auto s_counter = [to_count](const char* str) {
            size_t index{}, result{};
            while (str[index]) {
                if (str[index] == to_count) result++;
                index++;
            }
            return result;
        };
        auto sally = s_counter("Sally sells seashells by the seashore.");
        printf("Sally: %zu\n", sally);
        auto sailor = s_counter("Sailor went to the sea to see what he could see.");
        printf("Sailor: %zu\n", sailor);
    }

    //capture by reference to keep a running tally across lambda invocations
    {
        char to_count{ 's' };
        size_t tally{};
        auto s_counter = [to_count, &tally](const char* str) {
            size_t index{}, result{};
            while (str[index]) {
                if (str[index] == to_count) result++;
                index++;
            }
            tally += result;
            return result;
        };
        printf("Tally: %zu\n", tally);
        auto sally = s_counter("Sally sells seashells by the seashore.");
        printf("Sally: %zu\n", sally);
        printf("Tally: %zu\n", tally);
        auto sailor = s_counter("Sailor went to the sea to see what he could see.");
        printf("Sailor: %zu\n", sailor);
        printf("Tally: %zu\n", tally);
    }

    //default capture
    //you can capture all automatic variables used in lambda with default capture
    //to specify a default capture by value within a capture list use a '='
    //to specify default capture by reference use '&'
    //you're not allowed to modify variables captured by value uless you add the
    //'mutable' keyword as a suffix. it allows you to modify value-captured variables,
    //including calling non-const methods on the object
    //but the version in the lambda is a shadow that happens to have the same name
    //it won't affect the original value
    
    //you can nix a default capture with a named capture
    //[&, to_count] default by ref but variable to_count by value

    //refrain from using default captures. better to use explicit captures

    //initialize capture
    //you can declare a new variable in a capture list
    //[&tally, my_char=to_count]

    //capturing 'this'
    //you can capture the object that the lambda is in by either [*this]
    //for by value or by [this] for by reference

    //constexpr lambdas
    //all lamdas are constexpr as long as the lambda can be invoked at compile time
    //you should use the constexpr suffix if you want to make sure it is constexpr
    //constexpr means no dynamic memory allocations and no non-constexpr functions


    //std::function is a wrapper class for a callable object
    //could be thought of as a "generic function pointer"
    //you can store a static function, a function object, or a lambda into std::function
    // std::function<return-type(arg-type-1, arg-type-2, ...)>
    //if you invoke a std::function with no callable object, a std::bad_function_call
    //error will be thrown
    std::function<void()> func{ [] { printf("A lambda.\n"); } };
    func();
    func = static_func;
    func();

    //std::function arrays are useful for storing many different types
    //of callable objects that are called the same way
    //using std::function *may* include runtime overhead because it
    //may need to make a dynamic allocation to store the object


    //cmd-line arguments
    printf("Arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%d: %s\n", i, argv[i]);    
    }


    
    return 0;
}
