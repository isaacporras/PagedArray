//
// Created by karina on 19/03/18.
//

#ifndef TAREACORTA1_PAGEDARRAY_H
#define TAREACORTA1_PAGEDARRAY_H

#include "../Memory/Memory.h"
#include <iostream>
#include <string>
using std::string;

class PagedArray {
public:
    Memory virtualMemory;
    int MAX_INDEX;

    PagedArray();
    int& operator[](int);
    void printTodasLasPaginas();

    int *getSize();
};


#endif //TAREACORTA1_PAGEDARRAY_H
