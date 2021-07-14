#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <vector>

template <typename T>
concept Integer = std::is_integral<T>::value;

template <Integer T>
T mode(const T* values, size_t length) {
    struct UniqueValue {
        UniqueValue(T value) 
            : value{ value },
            frequency{ 1 } {}
        T value;
        size_t frequency;
    };

    std::vector<UniqueValue> unique_values{};
    unique_values.reserve(length);

    //Search through all given values
    for (size_t i = 0; i < length; i++) {
        auto current_value = values[i];
        bool value_exists = false;
        //Find all unique values and increment frequency
        for (size_t j = 0; j < unique_values.size(); j++) {
            if (unique_values[j].value == current_value) {
                value_exists = true;
                unique_values[j].frequency++;
                break;
            }
        }
        if (!value_exists) {
            unique_values.push_back(UniqueValue(current_value));
        }
    }

    size_t highest_frequency_index = 0;
    bool invalid_mode = true;

    //Find the highest frequency value
    for (size_t i = 1; i < unique_values.size(); i++) {
        if (unique_values[i].frequency > 
                unique_values[highest_frequency_index].frequency) {
            highest_frequency_index = i;
            invalid_mode = false;
        }
        else if (unique_values[i].frequency == 
                unique_values[highest_frequency_index].frequency) {
            invalid_mode = true;
        }
    }

    if (invalid_mode) return 0;
    else return unique_values[highest_frequency_index].value;
}

template <size_t Index, typename T, size_t Length>
T& get(T (&arr)[Length]) {
    static_assert(Index < Length, "Out-of-bounds access");
    return arr[Index];
}

template<Integer T, size_t Length>
T mean(T (&arr)[Length]) {
    T sum{};
    for (auto val : arr) {
        sum += val;
    }
    return sum / Length;
}

int main(int argc, char** argv) {
    int test_vals1[]{ 1, 3, 4, 44, 2, 3, 1, 3 };
    char test_vals2[100]{};
    short test_vals3[6]{ 5, 5, 5 };

    printf("Mode of test_vals1. Expected: %d Got: %d\n", 3, mode(test_vals1, 8));
    printf("Mode of test_vals2. Expected: %d Got: %d\n", 0, mode(test_vals2, 100));
    printf("Mode of test_vals3. Expected: %d Got: %d\n", 0, mode(test_vals3, 6));

    printf("Mean of test_vals1: %d", mean(test_vals1));
    return 0;
}











