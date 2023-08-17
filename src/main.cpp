#include </home/greed/Desktop/Matrix library/headers/array.hpp>
#include <iostream>
#include </home/greed/Desktop/Matrix library/headers/matrix.hpp>
#include "test.cpp"


#include <vector>


int main() {
    Matrix<4, 4, int> matrix;
    std::cout << matrix << std::endl;

    Matrix<5, 5, int> matrix_1 = {{1, 2, 3, 4, 5},
                                  {1, 2, 3, 4, 5},
                                  {1, 2, 3, 4, 5},
                                  {1, 2, 3, 4, 5},
                                  {1, 2, 3, 4, 5}};


    std::vector<std::vector<int>> a = {{1, 2, 3}, {1, 2, 3}};
    std::vector<std::vector<int>>::iterator it = a.begin();
    std::cout << it[0][0] << std::endl;


    std::initializer_list<std::initializer_list<int>> i = {{1, 2, 3}, {1, 2 ,3}};

    std::size_t d_row = i.size();
    std::size_t d_col = (*(i.begin())).size();
    
    
    for (std::size_t i = 0; i < d_row; i++) 
        for (std::size_t j = 0; j < d_col; j++)
        {
            // It isn't working
            // std::cout << *(*(i.begin() + i) + j) << std::endl;
        }

    return 0;
}