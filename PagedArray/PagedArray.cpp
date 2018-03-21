//
// Created by karina on 19/03/18.
//

#include "PagedArray.h"

#include <cmath>
#include <iostream>
#include "PagedArray.h"
#include "Reader.h"

PagedArray::PagedArray() {
    Reader reader;
    reader.writeFile();
    MAX_INDEX = 1000;
}

int PagedArray::operator[](int index) {
    if(index >= MAX_INDEX){
        return 666666;
    }

    int requestedIndex = (index % 100);
    int requestedPageNumber = (int) ceil(index/100) + 1;
    struct Pagina* requestedPage = virtualMemory.cargarpagina(index);
    /*if(requestedIndex == 0){
        requestedPageNumber += 1;

    }*/

    std::cout << "el indice que voy a pedir: " << requestedIndex << " de la pagina: " << requestedPageNumber <<std::endl;


    for(int i = 0; i < 4; ++i){
        if(*virtualMemory.todaslaspaginas[i].numerodepagina == requestedPageNumber){
            requestedPage = &virtualMemory.todaslaspaginas[i];
        }
    }
    int requestedValue = requestedPage -> elementos[requestedIndex];
    return requestedValue;
}

void PagedArray::printTodasLasPaginas(){
    for(int x = 0; x < 4; x++) {
        Pagina page = virtualMemory.todaslaspaginas[x];
        for (int i = 0; i < 100; i++) {
            std::cout << "Pagina: " << *page.numerodepagina << " Posicion: " << i << " valor: " << page.elementos[i]
                      << std::endl;

        }
        std::cout << "-------" << std::endl;
    }
}

