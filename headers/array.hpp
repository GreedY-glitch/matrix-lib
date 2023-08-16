#pragma once


#ifndef __ARRAY
#define __ARRAY


#include <iostream>
#include <initializer_list>



typedef unsigned int uint32_t;

// metafunction for checking overflow (when n < initializer_list.size())

// ----- isn't  work ------
template <typename value_type, uint32_t _Size, 
          typename _rinit_list = std::initializer_list<value_type>>
struct is_overflow : std::conditional<(_Size < _rinit_list::size), 
                     std::true_type, 
                     std::false_type>::type {};





template <class T, uint32_t N> class Array {
private:
    using value_type = T;
    using size_type = uint32_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;

    T __array[N];

    size_type size_ = 0;

public:
    /* Iterators */

    /* Default constructor */
    Array() {
        for (uint32_t i = 0; i < N; i++) {
            __array[i] = 0;
            ++size_;
        }
    }

    Array(pointer _arr) {
        for (int i = 0; i < N; i++) {
            __array[i] = _arr[i];
            ++size_;
        }
    }

    Array(const std::initializer_list<T>& il) {
        typename std::initializer_list<T>::iterator iter = il.begin();

        if (N < il.size()) {
            throw std::overflow_error( "Fatal error!\n Can't make an array with current initializer_list\n");
        } else {
            uint32_t i = 0;
            for (; iter != il.end(); ++iter, i++) {
                __array[i] = *iter;
                ++size_;
            }
        }
    } 

    Array<T, N> operator=(pointer) noexcept;

    constexpr reference operator[](size_type pos) { return __array[pos]; }
    constexpr reference at(size_type pos) { return __array[pos]; }

    constexpr reference front() const noexcept { return __array[0]; }
    constexpr reference back() const noexcept { return __array[N - 1]; }

    friend std::ostream& operator<<(std::ostream& os, Array<T, N>& arr) {
        uint32_t i = 0;
        while (i != N) {  std::cout << arr[i] << " "; i++; }
        return os;
    }


    /* Need an implementation */
    constexpr size_type max_size() const noexcept;

    constexpr size_type size() const noexcept { return size_; }
    constexpr bool empty() const noexcept {
        return (size_ == 0) ? true : false;
    }
};



template <class T, uint32_t N>
inline Array<T, N> Array<T, N>::operator=(pointer _arr) noexcept
{
    for (int i = 0; i < N; i++) __array[i] = _arr[i];
    return this;
}

#endif // __ARRAY
