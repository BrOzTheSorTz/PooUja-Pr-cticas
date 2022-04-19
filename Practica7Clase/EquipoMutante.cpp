/**
 * @file EquipoMutante.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "EquipoMutante.h"

EquipoMutante::EquipoMutante(): EquipoMutante("---","---")
{
}

EquipoMutante::EquipoMutante(string nombre, string base)
    : _nombre(nombre),
    _base(base),
    _numMiembros(0) {

    for (int i = 0; i < _MAX_MIEMBROS_; i++) {
        _miembros[i] = nullptr;
    }
}

EquipoMutante::EquipoMutante(const EquipoMutante& orig)
    : _nombre(orig._nombre),
    _base(orig._base),
    _numMiembros(orig._numMiembros) {
    
    for (int i = 0; i < _MAX_MIEMBROS_; i++) {
        _miembros[i] = orig._miembros[i];
    }
}

EquipoMutante::~EquipoMutante() {
    if (_numMiembros > 0) {
        for (int i = 0; i < _numMiembros; i++) {
            _miembros[i] = nullptr;
        }
    }
}

void EquipoMutante::setNombre(string nombre) {
    this->_nombre = nombre;
}

string EquipoMutante::getNombre() const {
    return _nombre;
}

int EquipoMutante::getNumMiembros() const {
    return _numMiembros;
}

void EquipoMutante::setBase(string base) {
    this->_base = base;
}

string EquipoMutante::getBase() const {
    return _base;
}

EquipoMutante& EquipoMutante::addMutante(Mutante *m) {
    if (_numMiembros == _MAX_MIEMBROS_) {
        throw std::length_error("EquipoMutante::addMutante: el equipo está lleno");
    }

    _miembros[_numMiembros] = m;
    _numMiembros++;
}

Mutante* EquipoMutante::getMutante(int cual) {
    if ((cual < 1) || (cual > _numMiembros)) {
        throw std::invalid_argument("EquipoMutante::getMutante: valor de miembro"
                " incorrecto");
    }

    return _miembros[cual-1];
}

Mutante* EquipoMutante::sacaMutante(int cual) {
    Mutante *aux;

    if ((cual < 1) || (cual > _numMiembros)) {
        throw std::invalid_argument("EquipoMutante::sacaMutante: valor de miembro"
                " incorrecto");
    }

    aux = _miembros[cual-1];
    _miembros[cual-1] = nullptr;

    if (_numMiembros > 1) {
        _miembros[cual-1] = _miembros[_numMiembros - 1];
        _miembros[_numMiembros - 1] = 0;
    }

    _numMiembros--;

    return  aux;
}

string EquipoMutante::toCSV() {
    std::stringstream aux;
    std::string miembrosString="";




    for (int i = 0; i < _numMiembros; i++) {
       miembrosString += _miembros[i]->toCSV();
    }

    aux << _nombre << ";"
        << _base<<";"<<"MIEMBROS: "<<miembrosString;

    return  aux.str();
}

EquipoMutante& EquipoMutante::operator=(const EquipoMutante& orig) {
    if (this != &orig) {
        _nombre = orig._nombre;
        _base = orig._base;
        _numMiembros = orig._numMiembros;

        for (int i = 0; i < _MAX_MIEMBROS_; i++) {
            _miembros[i] = orig._miembros[i];
        }
    }

    return  *this;
}