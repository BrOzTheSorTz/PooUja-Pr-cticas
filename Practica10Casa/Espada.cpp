//
// Created by soria on 30/04/2022.
//

#include "Espada.h"

std::string Espada::getDescripcion() {

    return descripcion;
}

Espada::Espada(std::string descripcion):descripcion(descripcion) {

}

Espada::~Espada() {

}

Espada::Espada(const Espada &orig) :descripcion(orig.descripcion){

}
