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
    /* virtualMemory.cargarpagina(1);
     virtualMemory.cargarpagina(101);
    virtualMemory.cargarpagina(201);
    virtualMemory.cargarpagina(301);
      virtualMemory.cargarpagina(401);*/
}

int PagedArray::operator[](int index) {
    std::cout << "Entrando a operador sobreescrito index: " << index << std::endl;
    int requestedIndex = (index % 100);
    std::cout << "requestedIndex: " << requestedIndex <<std::endl;


    struct Pagina* requestedPage = virtualMemory.cargarpagina(index);
    //std::cout << "requestedPage: " << *(requestedPage->numerodepagina) <<std::endl;
    //std::cout << "a punto de regresar elemento " << requestedPage -> elementos[requestedIndex] <<std::endl;
    //int requestedValue = requestedPage -> elementos[requestedIndex];


    int requestedPageNumber = (int) ceil(index/100) + 1;
    std::cout << "------ Página solicitada: " << requestedPageNumber << " -------" << std::endl;

    for(int i = 0; i < 4; i++){
        if(*virtualMemory.todaslaspaginas[i].numerodepagina == requestedPageNumber){
            requestedPage = &virtualMemory.todaslaspaginas[i];
        }
    }
    int requestedValue = requestedPage -> elementos[requestedIndex -1];
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

