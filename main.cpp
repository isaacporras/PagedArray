#include <iostream>

#include "PagedArray/Reader.h"
#include "Memory/Memory.h"
#include "PagedArray/PagedArray.h"

int main() {
    PagedArray array;
    /*std::cout << "----Prueba 1 regresa: " << array[0] << std::endl;//2
    std::cout << "----Prueba 2 regresa: " << array[1] << std::endl;//8
    std::cout << "----Prueba 3 regresa: " << array[100] << std::endl;//1
    std::cout << "----Prueba 4 regresa: " << array[199] << std::endl;//1
    std::cout << "----Prueba 5 regresa: " << array[200] << std::endl;//3*/
    int *num = array[1];
    std::cout << "array[]: " << *num << std::endl;
    array.printTodasLasPaginas();

    *num = 18;
    std::cout << "array[]: " << *num << std::endl;
    array.printTodasLasPaginas();

    return 0;
}
