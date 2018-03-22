//
// Created by Roger Valderrama on 3/20/18.
//

#ifndef TAREACORTA1_SORTING_HPP
#define TAREACORTA1_SORTING_HPP


#include "../PagedArray/PagedArray.h"

class Sorting {
public:


    static void quickSort(PagedArray *arr, int left, int right);

    static void insertionSort(PagedArray *arr, int length);
};


#endif //TAREACORTA1_SORTING_HPP
