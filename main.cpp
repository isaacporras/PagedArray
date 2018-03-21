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
    int num = array[1];
    std::cout << "array[]: " << num << std::endl;
    //array.printTodasLasPaginas();
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
    cout<<"HERE"<<endl;
//    num = 18;
//    std::cout << "array[]: " << num << std::endl;
//    array.printTodasLasPaginas();


    cout<<"----------------------Type QS for QuickSort----------------------"<<endl;
    cout<<"----------------------Type IS for QuickSort----------------------"<<endl;
    cout<<"----------------------Type SS for QuickSort----------------------"<<endl;


    long length = array.getSize()/ sizeof(int);
    cout<<"LENGTH: "<<length<<endl;


    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    cout<<"HERE2"<<endl;
    Sorting::quickSort(&array, 0, (int)(length-1));
    cout<<"HERE3"<<endl;
    cout<<"HERE3"<<endl;
    cout<<"HERE3"<<endl;
    cout<<"HERE3"<<endl;
    cout<<"HERE3"<<endl;
    cout<<"HERE3"<<endl;
    cout<<"HERE3"<<endl;
    cout<<"HERE3"<<endl;
    cout<<"HERE3"<<endl;
    cout<<"HERE3"<<endl;
    array.printTodasLasPaginas();
//    string input {""};
//    cin>>input;
//    if(input == "QS") { Sorting::quickSort(&array, 0,(int)(length - 1));};
//    if(input == "IS") { Sorting::quickSort(&array, (int)length);};
//    if(input == "SS") { Sorting::quickSort(&array, (int)length);};



    return 0;


}
