#include <iostream>

#include "PagedArray/Reader.h"
#include "Memory/Memory.h"
#include "PagedArray/PagedArray.h"
#include "Sorting/Sorting.hpp"

using namespace std;

int main() {
    PagedArray array;
    /*std::cout << "----Prueba 1 regresa: " << array[0] << std::endl;//2
    std::cout << "----Prueba 2 regresa: " << array[1] << std::endl;//8
    std::cout << "----Prueba 3 regresa: " << array[100] << std::endl;//1
    std::cout << "----Prueba 4 regresa: " << array[199] << std::endl;//1
    std::cout << "----Prueba 5 regresa: " << array[200] << std::endl;//3*/
    //int num = array[1];
    //std::cout << "array[]: " << num << std::endl;
    //array.printTodasLasPaginas();
//    num = 18;
//    std::cout << "array[]: " << num << std::endl;
//    array.printTodasLasPaginas();

    //std::cout<< "EL TAMANO DE MI ARCHIVO ES :" << *memoria.getSize() << " bytes" <<std::endl;


    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "-----------------------------WELCOME---------------------------------" << endl;
    cout << "----------------PLEASE CHOOSE ANY SORTING ALGORITHM------------------" << endl;
    cout << "-------------------------Type QS for QuickSort-----------------------" << endl;
    cout << "----------------------Type SS for SelectionSort----------------------" << endl;
    cout << "----------------------Type IS for InsertionSort----------------------" << endl;


    int *length = array.getSize();
//    cout << "LENGTH: " << *length << endl;
    int fl = *length / 4;

    string input;
    cin >> input;
    if (input == "QS") {
        Sorting::quickSort(&array, 0, fl - 1);
        array.printTodasLasPaginas();
    } else if (input == "IS") {
        Sorting::insertionSort(&array, fl);
        array.printTodasLasPaginas();
    } else if (input == "SS") {
        Sorting::selectionSort(&array, fl);
        array.printTodasLasPaginas();
    } else {
        cout << "input not valid, type QS, IS, SS" << endl;
    }


    return 0;
}
