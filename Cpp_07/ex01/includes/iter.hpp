
#pragma once

#include <iostream>

template <typename T> void iter(T *ptr, size_t len, void (*func)(T &)) {
    for (size_t i = 0; i < len; i++)
        func(ptr[i]);
}

template <typename T> void print_elem(T &value) {
    std::cout << value << std::endl; }
