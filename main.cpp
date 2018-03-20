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
    memoria.cargarpagina(10);
    memoria.cargarpagina(250);
    memoria.cargarpagina(251);
//    memoria.cargarpagina(401);

    return 0;
}
