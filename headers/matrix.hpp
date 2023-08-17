#pragma once 


#ifndef _MATRIX_
#define _MATRIX_


#include <iostream>
#include <initializer_list>


struct Fields {
    static const int REAL_NUMBER = 0x1;
    static const int COMPLEX_NUMBER = 0x2; 
};


/*
    Field is not a needed parameter
    By default it is a real_number
*/

template <std::size_t _Dim_1, std::size_t _Dim_2, typename T> 
class Matrix 
{
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;

    T matrix[_Dim_1][_Dim_2];   /* Private field -> raw matrix */

public:
    /* Creates a default matrix (E) */
    Matrix() {
        for (std::size_t i = 0; i < _Dim_1; i++) {

            for (std::size_t j = 0; j < _Dim_2; j++) 
            {
                if (i == j) matrix[i][j] = 1;
                else matrix[i][j] = 0;
            }
        }
    }
};


#endif  // _MATRIX_