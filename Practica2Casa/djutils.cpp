//
// Created by soria on 26/02/2022.
//
#include <iostream>
#include "djutils.h"

/**
 * @brief Mostramos los datos de una canción
 * @param c  -> canción
 */
void mostrarTemazo (const Temazo &c){
    std::cout<<"Mostramos los datos de la cancion : "<<std::endl;
    std::cout<< c.getTitulo()<<" - "<<
                c.getInterprete()<<" - "<<
                c.getDuracion()<<" - "<<
                c.getPuntuacion()<<std::endl;

}

/**
 * @brief Mostramos los datos de un garito
 * @param g  -> garito
 */
void mostrarGarito (const Garito &g){
    std::cout<<"Mostramos los datos del garito : "<<std::endl;
    std::cout<< g.getNombre()<<" - "<<
             g.getDireccion()<<" - "<<std::endl;

}
/**
 * @brief Modificamos los datos de un garito
 * @param g  -> garito
 */
void modificarGarito(Garito &g){
    //Aquí hemos utilizado excepciones por si el usuario no escribe nada por lo que hay que tratarlas
    std::string nombre ="";
    std::string direccion = "";
    try{
        std::cout<<"Introduzca un nombre: ";
        std::cin>>nombre;
        g.setNombre(nombre);
        nombre = "";
        direccion = "";
        //Lo concateno para que si pongo mal el nombre no siga pidiendo la direccion
        try{
            std::cout<<"Introduzca una direccion: ";
            std::cin>>direccion;
            g.setDireccion(direccion);

        }catch (std::string &e){
            std::cerr <<"ERROR-djutils.cpp : Cadena vacia"<<std::endl;
        }

    }catch (std::string &e){
        std::cerr <<"ERROR-djutils.cpp : Cadena vacia"<<std::endl;
    }


}
/**
* @brief Mostramos los datos de una fecha
* @param f  -> fecha
*/
void mostrarFecha (const Fecha &f){
    std::cout<<"Mostramos la fecha : "<<std::endl;
    std::cout<< f.getDia()<<"/"<<
             f.getMes()<<"/"<<
             f.getAnio()<<std::endl;


}

