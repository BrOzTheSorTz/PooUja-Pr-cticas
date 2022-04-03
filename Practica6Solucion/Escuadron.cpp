//
// Created by soria on 02/04/2022.
//

#include "Escuadron.h"

Escuadron::Escuadron(const std::string &nombre, int numPilotos, const std::string &base) : nombre(nombre),
                                                                                           numPilotos(numPilotos),
                                                                                           base(base) {
}

const std::string &Escuadron::getNombre() const {
    return nombre;
}

void Escuadron::setNombre(const std::string &nombre) {
    Escuadron::nombre = nombre;
}

int Escuadron::getNumPilotos() const {
    return numPilotos;
}

void Escuadron::setNumPilotos(int numPilotos) {
    Escuadron::numPilotos = numPilotos;
}

const std::string &Escuadron::getBase() const {
    return base;
}

void Escuadron::setBase(const std::string &base) {
    Escuadron::base = base;
}

Escuadron::~Escuadron() {

}

Escuadron::Escuadron() {
    for(int i=0;i<MAX;++i){
        integrantes[i]= nullptr;
    }

}

Escuadron &Escuadron::addPiloto( Piloto &p) {
    integrantes[numPilotos]=&p;
    ++numPilotos;

    return *this;
}

Piloto &Escuadron::obtenerPiloto(int cual) {

    return *integrantes[cual-1];
}

Escuadron &Escuadron::quitarPiloto(int cual) {

    integrantes[cual-1]= nullptr;

    /*Hay dos formas de restaurar el vector:
     * 1ºForma:
     * ========
     * Asignamos en la posicion que hemos quitado el piloto el último piloto
     *
     * 2º Forma:
     * =========
     * Puede ser que queramos mantener el orden en el vector por lo que tengamos
     * que desplazarlo todo.
     *
     * for(int i=cual-1 ;i<numPilotos-1;++i){
     *      integrantes[i]=integrantes[i+1];
     * }
     * */



    for(int i=cual-1;i<numPilotos-1;++i){
        integrantes[i]=integrantes[i+1];
    }
    integrantes[numPilotos-1]=nullptr;

    return *this;
}

float Escuadron::promedioMisones() {
    float promedio =0;

    for(int i=0;i<numPilotos;++i){
        promedio = promedio + integrantes[i]->getNumMisiones();
    }

    return (promedio/numPilotos);
}

Escuadron Escuadron::operator+(const Escuadron &e) {

    Escuadron suma;

    suma.setNombre(this->getNombre() + e.getNombre());

    for(int i=0;i<this->getNumPilotos();++i){
        suma.addPiloto(*this->integrantes[i]);
    }
    for(int i=0;i<e.getNumPilotos();++i){
        suma.addPiloto(*e.integrantes[i]);
    }


    return suma;
}
