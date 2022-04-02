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
                c.getPuntuacion()<<" - "<<
                c.getGenero()<<" - "<<
                c.getNombreUltimoGarito()<<" - "<<std::endl;
                mostrarFecha(c.getFechaUltimoUso());
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
            std::cout <<"ERROR-djutils.cpp : Cadena vacia"<<std::endl;
        }

    }catch (std::string &e){
        std::cout <<"ERROR-djutils.cpp : Cadena vacia"<<std::endl;
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


/**
 *
* @brief Visualizar los temazos del vector cuya fecha de último uso sea anterior a la fecha indicada como tercer parámetro
 * @param v
 * @param tama
 * @param f
 *
*/
void mostrarTemazosAnteriores(const Temazo v[],const int &tama,const Fecha &f){

    for(int i=0;i<tama;++i){
        // lo hemos hecho con sobrecarga aunque también lo podemos hacer como (v[i].getFecha()).operatos<(f)
        if(v[i].getFechaUltimoUso() < f){

            mostrarTemazo(v[i]);
        }
    }
}
/**
 * @brief Visualizar todos los temazos con una duración superior o igual a la del indicado
 * @param v
 * @param tama
 * @param t
 */
void verTemazosMasLargosQue(const Temazo v[],const int &tama, const Temazo &t){

    for(int i=0;i<tama;++i){
        //Si la duración es superior o igual que el indicado lo visualizamos
        if(v[i].getDuracion() >= t.getDuracion()){
            mostrarTemazo(v[i]);
        }
    }

}
/*
 * ToDo
//Aumentar tamanio de un puntero
int aumentarTamaEn1(Temazo* vP,int tamaInicial){
    int nuevoTama = tamaInicial+1;
    Temazo* aux = new Temazo[nuevoTama];

    for(int i=0;i<nuevoTama;++i){

    }

    return nuevoTama;
}*/


/**
 * @brief Devuelve una lista de los temazos cuya duracion en conjunto es menor a la dad
 * @param v
 * @param tamv
 * @param lista Cuyo tamanio debe ser igual que el introducido como máximo
 * @param tamLista
 * @param duracionTotal
 * @return
 */
int listaRelleno( Temazo v[], int tamv, Temazo* lista[], int tamLista, int duracionTotal) {
    int nuevoTama=0;
    int suma=0;

    for(int i=0;i<tamv;++i){
        suma= suma+ v[i].getDuracion();
        if(suma<duracionTotal){
            lista[nuevoTama]=&v[i];
            ++nuevoTama;

        }
    }

    return nuevoTama;
}
/*
 * ToDo
void temazosConDuracionInferior(int duracionTotal, Temazo *pv, int &tamaPv, const Temazo *v, int tamanio) {

}
*/