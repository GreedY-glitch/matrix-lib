#include </home/greed/Desktop/Matrix library/headers/array.hpp>
#include <iostream>
#include "test.cpp"


int main() {
    Array<int, 8> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << arr << std::endl;

    std::cout << arr.at(3) << " " << arr.size() << std::endl;

    int* ptr = nullptr;
    if constexpr (is_pointer<decltype(ptr)>::value) { std ::cout << "It works!\n"; }

    return 0;
}