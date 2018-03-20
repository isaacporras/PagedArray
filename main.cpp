#include <iostream>

#include "PagedArray/Reader.h"
#include "Memory/Memory.h"
#include "PagedArray/PagedArray.h"

int main() {
/*    Reader reader;
    reader.writeFile();
    Memory memoria;
    memoria.cargarpagina(1);
    memoria.cargarpagina(101);
    memoria.cargarpagina(201);
    memoria.cargarpagina(301);
    //memoria.cargarpagina(401);
    for(int x = 0; x < 4; x++) {
        Pagina page = memoria.todaslaspaginas[x];
        for (int i = 0; i < 100; i++) {
            std::cout << "Pagina: "<< *page.numerodepagina << " Posicion: " << i << " valor: " << page.elementos[i] << std::endl;
        }
    }*/
    PagedArray array;
    std::cout << "Espero: 2 Prueba regresa: " << array[1] << std::endl;//2
    std::cout << "Espero: 1 Prueba regresa: " << array[101] << std::endl;//1
    std::cout << "Espero: 3 Prueba regresa: " << array[201] << std::endl;//3
    std::cout << "Espero: 8 Prueba regresa: " << array[301] << std::endl;//8
    //array.printTodasLasPaginas();

    return 0;
}
