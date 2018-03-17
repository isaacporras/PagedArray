#include <iostream>

#include "PagedArray/Reader.h"
#include "Memory/Memory.h"

int main() {
    Reader reader;
    reader.writeFile();
//    reader.getSize();
//    reader.readFile();
    Memory memoria;
    memoria.cargarpagina(100);
    memoria.cargarpagina(300);

    return 0;
}
