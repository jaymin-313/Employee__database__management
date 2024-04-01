#ifndef attribute_flag
#define attribute_flag
#include <string>
#include "validate.h"
#include <functional>
#include <type_traits>

template<typename T, typename Validator>
bool setAttribute(const std::string& attributeName, T& attribute, Validator validator) {
    int attempts = 0;
    while (attempts < 3) {
        std::cout << attributeName << ": ";
        std::string input;
        std::cin >> input;
        if (validator(input)) {
            if constexpr (std::is_same_v<T, int>) {
                attribute = std::stoi(input);
            }
            else if constexpr (std::is_same_v<T, float>) {
                attribute = std::stof(input);
            }
            else {
                attribute = input;
            }
            break;
        }
        else {
            std::cout << "\033[31mInvalid input! Please try again.\033[0m\n";
            attempts++;
        }
    }
    if (attempts == 3) {
        std::cout << "\033[31mExceeded maximum attempts. Exiting...\033[0m\n";
        return false;
    }
    return true;
}


#endif