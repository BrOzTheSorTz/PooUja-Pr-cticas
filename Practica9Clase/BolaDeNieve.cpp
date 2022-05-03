//
// Created by admin on 03/05/2022.
//

#include "BolaDeNieve.h"
#include "ItemAgotado.h"
#include <sstream>
std::string BolaDeNieve::getDescripcion() {
    return descripcion;
}

BolaDeNieve::~BolaDeNieve() {

}



std::string BolaDeNieve::lanzar() {
    //Decrementamos el número de unidades
    if(this->getNumElementos()==0){
        throw ItemAgotado("[ItemApilableArrojable::lanzar()], Te quedaste sin unidades del objeto :(") ;
    }
    this->decrementaNumElementos(1);

    //Convertimos un float en string
    std::stringstream aux;
    aux<<this->getDamage();
    return "El damage producido fue de: "+ aux.str();
}