#pragma once


#ifndef __ARRAY
#define __ARRAY


typedef unsigned int uint32_t;

template <class T, uint32_t N> class Array {
private:
    using value_type = T;
    using size_type = uint32_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;

    T __array[N];

public:
    /* Iterators */

    /* Default constructor */
    Array() {
        for (uint32_t i = 0; i < N; i++) {
            __array[i] = 0;
        }
    }

    Array(pointer _arr) {
        
    }
};

#endif // __ARRAY