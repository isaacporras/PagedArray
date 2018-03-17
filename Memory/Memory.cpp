//
// Created by Isaac  Porras  on 12/3/18.
//

#include "Memory.h"
#include <iostream>
#include <string>
using std::string;

/**
  *@file Memory.h
  * @version 1.0
  * @date 15/3/18
  * @author Oscar Isaac Porras Perez
  * @title Memory
  * @brief Este archivo maneja todo lo que tiene que ver con la paginacion
  */


Memory::Memory() {

    struct Pagina pagina1;
    pagina1.numerodepagina = -1;
    struct Pagina pagina2;
    pagina2.numerodepagina = -1;
    struct Pagina pagina3;
    pagina3.numerodepagina = -1;
    struct Pagina pagina4;
    pagina4.numerodepagina = -1;

}

int Memory::getSize(){                                                                                                  //Este metodo no se utiliza
    std::cout<<"LOS NUMEROS QUE SE ALMACENAN EN MI ARCHIVO SON: "<<std::endl;
    FILE *file;
    int number;
    file = fopen("archivo.bin","rb");
    int *cantidad = (int *)malloc(sizeof(int));
    *cantidad = 0;
    if(file==NULL){
        std::cout<<"no se abrio"<< std::endl;
    }
    else{
        while(fread(&number, sizeof(int),1,file)){
            cantidad = cantidad +1;
            std::cout<<number<<std::endl;
        }
    }
    return *cantidad *sizeof(int);

}

Pagina Memory::insertarPagina(Pagina *paginainsertar) {                                                                   //Este metodo asigna la pagina que se quiere cargar a las que se tienen

    if(pagina1.numerodepagina == -1){

        std::cout<<"SE INSERTO EN LA PAGINA 1"<<std::endl;

        pagina1 = (*paginainsertar);

        todaslaspaginas[1] = pagina1;

        pagina1.lasttimeused += 1;

        return pagina1;
    }
    if(pagina2.numerodepagina == -1){

        std::cout<<"SE INSERTO EN LA PAGINA 2"<<std::endl;
        pagina2 = (*paginainsertar);
        todaslaspaginas[2] = pagina2;
        pagina2.lasttimeused +=1;
        return pagina2;
    }
    if(pagina3.numerodepagina == -1) {
        std::cout<<"SE INSERTO EN LA PAGINA 3"<<std::endl;
        pagina3 = (*paginainsertar);
        todaslaspaginas[3] = pagina3;
        pagina3.lasttimeused +=1;
        return pagina3;
    }
    if(pagina4.numerodepagina == -1){
        std::cout<<"SE INSERTO EN LA PAGINA 4"<<std::endl;
        pagina4 = (*paginainsertar);
        todaslaspaginas[4] = pagina4;
        pagina4.lasttimeused +=1;
        return pagina4;
    }
        //ACA APLICA EL CRITERIO DE LA MENOS USADA PARA AREMPLAZAR
    else{
        if(pagina1.lasttimeused >= pagina2.lasttimeused && pagina1.lasttimeused>= pagina3.lasttimeused
           && pagina1.lasttimeused>= pagina4.lasttimeused)
        {
            std::cout<<"SE INSERTO EN LA PAGINA 1"<<std::endl;
            pagina1 = (*paginainsertar);
            todaslaspaginas[1] = pagina1;
            return pagina1;
        }
        if(pagina2.lasttimeused>= pagina1.lasttimeused && pagina2.lasttimeused>= pagina3.lasttimeused
           && pagina2.lasttimeused>= pagina4.lasttimeused){
            std::cout<<"SE INSERTO EN LA PAGINA 2"<<std::endl;
            pagina2 = (*paginainsertar);
            todaslaspaginas[2] = pagina2;
            return pagina2;
        }
        if(pagina3.lasttimeused>= pagina1.lasttimeused && pagina3.lasttimeused>= pagina2.lasttimeused
           && pagina3.lasttimeused>= pagina4.lasttimeused){
            std::cout<<"SE INSERTO EN LA PAGINA 3"<<std::endl;
            pagina3 = (*paginainsertar);
            todaslaspaginas[3] = pagina3;
            return pagina3;
        }
        if(pagina3.lasttimeused>= pagina1.lasttimeused && pagina3.lasttimeused>= pagina2.lasttimeused
           && pagina3.lasttimeused>= pagina4.lasttimeused){
            std::cout<<"SE INSERTO EN LA PAGINA 4"<<std::endl;
            pagina4 = (*paginainsertar);
            todaslaspaginas[4] = pagina4;

            return pagina4;
        }

    }
}

Pagina Memory::cargarpagina(int posicion_numero) {                                                                        //Yo defini las paginas de 100 ints = 400bytes

    string status = "no cargado";                                                                                       //Este status permite saber si la pagina esta cargada o no
    int bytepos = posicion_numero * sizeof(int);                                                                        //Calcula la posicion en bytes de el numero
    int numero_de_pagina = (bytepos / (sizeof(int) * 100));                                                              //Calcula la pagina en la que se encuentra el numero

    std::cout << numero_de_pagina << std::endl;
    std::cout << "MI NUMERO ESTA POSICIONADO EN LA POSICION: " << bytepos << std::endl;

    if (numero_de_pagina == pagina1.numerodepagina){

        pagina1.lasttimeused +=1;
        return pagina1;
    }
    if(numero_de_pagina ==pagina2.numerodepagina){
        pagina2.lasttimeused +=1;
        return pagina2;
    }
    if( numero_de_pagina == pagina3.numerodepagina ){
        pagina3.lasttimeused +=1;
        return pagina3;
    }
    if(numero_de_pagina == pagina4.numerodepagina){
        pagina4.lasttimeused +=1;
        return pagina4;
    }


    if (status == "no cargado") {                                                                                         //Si la pagina no esta normal
        std::cout << "MI DATO NO ESTA CARGADO" << std::endl;

        FILE *file;
        file = fopen("archivo.bin", "rb");                                                                               //Abre el archivo.bin

        if (file == NULL) {                                                                                               //Verifica si se abrio
            std::cout << "no se abrio" << std::endl;
        }
        if (numero_de_pagina == 1) {
                                                                                                                        //Si el elemento se encuentra en la pagina 1 entonces  no lo multiplica por la cantidad de bytes que tiene cada pagina
            fseek(file, 0, SEEK_SET);
        }
        if (numero_de_pagina != 1) {                                                                                       //Si el elemento no es la primera multiplica la pagina por la cantidad de bytes que tiene cada pagina
                                                                                                        //...y de esta manera posiciona el lector del archivo donde va a empezar leer la pagina
            fseek(file, numero_de_pagina * 400, SEEK_SET);
        }

        int posicion = 0;

        Pagina pagina1;                                                                                                //Crea la pagina

        pagina1.numerodepagina = numero_de_pagina;
                                                                                                                        // Le asigna el numero de la pagina
        if(numero_de_pagina == 1){
            pagina1.posInicio = 0;
        }
        if(numero_de_pagina != 1){
            pagina1.posInicio = (numero_de_pagina - 1) * 400;
        }
                                                                           //Le asigna la posicion inicial de la pagina

        pagina1.posFinal = numero_de_pagina * 400;


        //Le asigna la posicion final de la pagina

        int number;
        std::cout << "ESTOS SON LOS ELEMENTOS DE MI PAGINA: " << numero_de_pagina << std::endl;
        std::cout << "-----------------------------------------------------------------" << std::endl;
        int contador = 0;

        while (fread(&number, sizeof(int), 1, file) && contador != 101) {                                                  //Aca lee el archivo y le mete los numeros al array que tiene la pagina

            pagina1.elementos[posicion] = number;                                                                       //Aca mete los numeros al array
            posicion = posicion + 1;                                                                                    //Aumenta la posicion
            std::cout << number << " , " << contador << ", " << pagina1.numerodepagina << std::endl;
            contador = contador + 1;
        }

        std::cout << "HAY " << contador << " elementos en esta pagina" << std::endl;
        std::cout << "-----------------------------------------------------------------" << std::endl;

        insertarPagina(&pagina1);                                                                                       //Inserta la pagina creada en los memoria

    }
}
