#include <iostream>

#include "PagedArray/Reader.h"
#include "Memory/Memory.h"

int main() {
    Reader reader;
    reader.writeFile();
//    reader.getSize();
//    reader.readFile();
    Memory memoria;
    memoria.cargarpagina(1);
    memoria.cargarpagina(2);
    memoria.cargarpagina(3);
    memoria.cargarpagina(105);
    memoria.cargarpagina(205);
    memoria.cargarpagina(305);

    std::cout<< "SE TERMINARON TODAS LAS BUSQUEDAS "<<std::endl;
    for(int x = 0 ; x < 4; x++){
        std::cout <<"********************************SE EMPIEZA UNA PAGINA NUEVA "<< x + 1 <<" *********************************"<<std::endl;
        Pagina page  = memoria.todaslaspaginas[x];
        for(int i = 0; i < 100; i++){
        std::cout<< "PAGINA : "<< *page.numerodepagina << ", Posicion: "<< i <<", VALOR:" << page.elementos[i] <<std::endl;
        }
    }
//    memoria.cargarpagina(401);
//    memoria.cargarpagina(402);
//    memoria.cargarpagina(700);
//    memoria.cargarpagina(2);

    return 0;
}
