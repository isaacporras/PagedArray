//
// Created by Isaac  Porras  on 12/3/18.
//

#ifndef TAREACORTA1_MEMORY_H
#define TAREACORTA1_MEMORY_H
/**
  *@file Memory.h
  * @version 1.0
  * @date 15/3/18
  * @author Oscar Isaac Porras Perez
  * @title Memory
  * @brief Este archivo maneja todo lo que tiene que ver con la paginacion
  */
struct Pagina;

/**
 * @brief Memory class es la clase que controla todo lo referente a el manejo de la paginacion
 */
class Memory {

    int filesize;
    int *todas_las_paginas;
    struct Pagina *pag1;
    struct Pagina *pag2;
    struct Pagina *pag3;
    struct Pagina *pag4;
public:

    Memory();


    /**
     * @brief este metodo busca la posicion del numero que se busca y retorna la pagina completa en la que se encuentra
     * @param posicion_numero la posicion del numero que se busca
     */
    void cargarpagina(int posicion_numero);
    /**
     * @brief este metodo retorna el tamano del archivo que se esta leyendo, en este caso es archivo.bin
     * @return tamano en bytes del archivo
     */
    int getSize();
    /**
     * @brief este metodo inserta la pagina entera(que se busca en el metodo cargarpagina) en los arrays de la memoria.
     * @param paginainsertar
     */
    void insertarPagina(Pagina *paginainsertar);

};


#endif //TAREACORTA1_MEMORY_H
