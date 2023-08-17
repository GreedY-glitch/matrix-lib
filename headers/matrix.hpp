#pragma once 


#ifndef _MATRIX_
#define _MATRIX_


#include <iostream>


struct Fields {
    static const int REAL_NUMBER = 0x1;
    static const int COMPLEX_NUMBER = 0x2; 
};


/*
    Field is not a needed parameter
    By default it is a real_number
*/

template <typename _Dim_1, typename _Dim_2, typename Field> 
class Matrix {};


/* Uses by default */
template <typename _Dim_1, typename _Dim_2, decltype(Fields::REAL_NUMBER)> 
class Matrix {};


/* if you're need a complex number matrix use this */
template <typename _Dim_1, typename _Dim_2, decltype(Fields::COMPLEX_NUMBER)> 
class Matrix {};

#endif  // _MATRIX_