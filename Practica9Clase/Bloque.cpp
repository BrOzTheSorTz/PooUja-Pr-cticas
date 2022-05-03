//
// Created by soria on 30/04/2022.
//

#include "Bloque.h"
#include <sstream>

std::string Bloque::getDescripcion() {

    //Obtenemos el número de bloques que hay
    std::stringstream aux;
    aux<<this->getNumElementos();
    //Y como es un INT, hay que convertirlo en string para poder
    //concatenarlo en la salida

    return descripcion+ " ("+aux.str()+")";
}

Bloque::Bloque(std::string descripcion)
:descripcion(descripcion) {

}
