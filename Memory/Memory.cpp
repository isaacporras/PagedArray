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

    //Le asigna un numero de pagina que despues va a servir para saber si no se ha insertado la pagina


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

void Memory::insertarPagina(Pagina *paginainsertar) {                                                                   //Este metodo asigna la pagina que se quiere cargar a las que se tienen

    if(pagina1.numerodepagina == -1){
        std::cout<<"SE INSERTO EN LA PAGINA 1"<<std::endl;
        pagina1 = (*paginainsertar);
        return;
    }
    if(pagina2.numerodepagina == -1){
        std::cout<<"SE INSERTO EN LA PAGINA 2"<<std::endl;
        pagina2 = (*paginainsertar);
        return;
    }
    if(pagina2.numerodepagina == -1) {
        std::cout<<"SE INSERTO EN LA PAGINA 3"<<std::endl;
        pagina2 = (*paginainsertar);
        return;
    }
    if(pagina3.numerodepagina == -1){
        std::cout<<"SE INSERTO EN LA PAGINA 4"<<std::endl;
        pagina3 = (*paginainsertar);
        return;
    }
    else{
        // aca tiene que buscar cuales de las paginas anteriores va a ser la que va a remplazar

    }
}

void Memory::cargarpagina(int posicion_numero) {
    //Yo defini las paginas de 100 ints = 400bytes
    std::cout<<"AYUDAAAAAAA: "<<pagina1.numerodepagina <<std::endl;
    string status = "no cargado";                                                                                       //Este status permite saber si la pagina esta cargada o no
    int bytepos = posicion_numero * sizeof(int);                                                                        //Calcula la posicion en bytes de el numero
    int numero_de_pagina = (bytepos / (sizeof(int)*100)) ;                                                              //Calcula la pagina en la que se encuentra el numero
    std::cout<<"pagina1: "<<pagina1.numerodepagina <<std::endl;
    std::cout<<numero_de_pagina<<std::endl;
    std::cout<<"MI NUMERO ESTA POSICIONADO EN LA POSICION: "<< bytepos <<std::endl;

    if(numero_de_pagina == pagina1.numerodepagina||numero_de_pagina == pagina2.numerodepagina                                //Verifica que la pagina no este cargada
       || numero_de_pagina == pagina3.numerodepagina|| numero_de_pagina == pagina4.numerodepagina){
        std::cout<<"YA ESTA CARGADA"<<std::endl;
        status = "cargado";                                                                                             //cambia el status si la pagina esta cargada
        return;
    }

    std::cout<<"AYUDAAAAAAA: "<<pagina1.numerodepagina <<std::endl;

    if(status == "no cargado"){                                                                                         //Si la pagina no esta normal
        std::cout<<"MI DATO NO ESTA CARGADO" <<std::endl;

        FILE *file;
        file = fopen("archivo.bin","rb");                                                                               //Abre el archivo.bin

        if(file == NULL){                                                                                               //Verifica si se abrio
            std::cout<<"no se abrio"<< std::endl;
        }
        if(numero_de_pagina == 1){                                                                                      //Si el elemento se encuentra en la pagina 1 entonces  no lo multiplica por la cantidad de bytes que tiene cada pagina
            fseek(file, 0, SEEK_SET);
        }
        if(numero_de_pagina!= 1){                                                                                       //Si el elemento no es la primera multiplica la pagina por la cantidad de bytes que tiene cada pagina
            //...y de esta manera posiciona el lector del archivo donde va a empezar leer la pagina
            fseek(file, numero_de_pagina * 400, SEEK_SET);
        }

        int posicion = 0;

        Pagina pagina1;                                                                                                 //Crea la pagina

        pagina1.numerodepagina = numero_de_pagina;                                                                      // Le asigna el numero de la pagina

        pagina1.posInicio = numero_de_pagina * 400;                                                                     //Le asigna la posicion inicial de la pagina

        pagina1.posFinal = numero_de_pagina * 400 + 400;


        //Le asigna la posicion final de la pagina

        int number;
        std::cout<<"ESTOS SON LOS ELEMENTOS DE MI PAGINA: "<<numero_de_pagina<<std::endl;
        std::cout<<"-----------------------------------------------------------------"<<std::endl;
        int contador = 0;

        while(fread(&number, sizeof(int),1,file) && contador != 101 ){                                                  //Aca lee el archivo y le mete los numeros al array que tiene la pagina

            pagina1.elementos[posicion] = number;                                                                       //Aca mete los numeros al array
            posicion = posicion + 1;                                                                                    //Aumenta la posicion
            std::cout<<number<<" , "<<contador<<", "<<pagina1.numerodepagina<<std::endl;
            contador = contador +1;
        }
        std::cout<<"aca se cae el programa " <<std::endl;
        std::cout<<"AYUDAAAAAAA: "<<pagina1.numerodepagina <<std::endl;
        std::cout<<"HAY "<<contador << " elementos en esta pagina" <<std::endl;
        std::cout<<"-----------------------------------------------------------------"<<std::endl;
        std::cout<<"AYUDAAAAAAA: "<<pagina1.numerodepagina <<std::endl;
        insertarPagina(&pagina1);                                                                                       //Inserta la pagina creada en los memoria

    }

}