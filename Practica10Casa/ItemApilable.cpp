//
// Created by soria on 30/04/2022.
//

#include <stdexcept>
#include "ItemApilable.h"

/**
 *Constructor parametrizado
 * @param _numElementos Numero de elementos que apilamos
 * @throw std::out_of_range Si se supera la cantidad máxima
 */
ItemApilable::ItemApilable(int _numElementos):numElementos(_numElementos){
    if(_numElementos>64 || _numElementos<1){
        throw std::out_of_range("ItemApilable::itemApilable(numElementos).No es correcto el numero de elementos que quieres añadir");

    }


}
/**
 * @brief Aumentamos el número de objetos de un cofre
 * @param cantidad Número extra de objetos que queremos añadir
 * @throw std::out_of_range Si se supera la cantidad máxima
 */

void ItemApilable::incrementaNumElementos(int cantidad)
{
    if(numElementos+cantidad >64){
        throw std::out_of_range("ItemApilable::incrementaNumElementos.No es correcto el numero de elementos que quieres incrementar");
    }
    numElementos +=cantidad;

}

/**
 * @brief Eliminamos la cantidad de objetos de una determinada cantidad
 * @param cantidad
 * @throw std::out_of_range Si se eliminan más objetos de los que realmente ahí
 */
void ItemApilable::decrementaNumElementos(int cantidad) {
    if(numElementos-cantidad <0){
        throw std::out_of_range("ItemApilable::decrementaNumElementos.No es correcto la cantidad introducida");

    }

}

/**
 * @brief Obtenemos el número de elementos apilados
 * @return Número de elementos apilados
 */
int ItemApilable::getNumElementos() const {
    return numElementos;
}
