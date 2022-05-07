//
// Created by soria on 30/04/2022.
//

#include "Filete.h"

std::string Filete::getDescripcion() {

    return "Un Filete";
}

Filete::Filete(std::string descripcion):descripcion(descripcion) {

}

Filete::~Filete() {

}

Filete::Filete(const Filete &orig) :descripcion(orig.descripcion){

}
