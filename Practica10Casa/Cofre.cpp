/** 
 * @file    Cofre.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Cofre.h"
#include "EmptyContainer.h"
#include <stdexcept>


std::string Cofre::getDescripcion() {
    //Los cofres no son apilables
    /*Redefinir el método getDescripcion() de Cofre para
    que además muestre el número de elementos que contiene. */
    std::stringstream aux;
    aux<<this->cuantosHay();

    return "Cofre ("+aux.str()+")";
}

/**
 * @pre No se puede meter un cofre dentro de otro
 * @param item
 */
void Cofre::mete(Item *item) {

    Cofre *c= dynamic_cast<Cofre*>(item);

    if(c != nullptr){
        throw std::invalid_argument("[Cofre::mete()]No se puede meter un cofre dentro de otro");

    }
    //ToDo No se si esta bien esto a continuación
    this->Contenedor<Item>::mete(item);


}

Cofre::Cofre(int cuantosCaben) : Contenedor<Item>(cuantosCaben) {

}

Cofre::~Cofre() {

}
