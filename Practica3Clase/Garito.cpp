//
// Created by soria on 26/02/2022.
//

#include "Garito.h"

/**
 * @brief Constructor parametrizado
 * @param _nombre
 * @param _direccion
 */
Garito::Garito(std::string _nombre, std::string _direccion)
    :nombre(_nombre),direccion(_direccion){

}
/**
 * @brief Constructor de copia
 * @param orig
 */
Garito::Garito(const Garito &orig) {
    nombre = orig.nombre;
    direccion = orig.direccion;

}
/**
 * @brief Destructor
 */
Garito::~Garito() {

}
/**
 * @brief Obtenemos el nombre del garito
 * @return nombre
 */
std::string Garito::getNombre() const {
    return nombre;
}
/**
 * @brief asignamos un nombre al garito
 * @param nombre
 */
void Garito::setNombre(const std::string &nombre) {
    if (nombre == "" || nombre.length()<2) {
        throw std::string("ERROR-Garito.cpp: Cadena vacia o demasiado pequenia");
    } else {
        this->nombre = nombre;
    }
}
/**
 * @brief Obtenemos la dirección del garito
 * @return direccion
 */
std::string Garito::getDireccion() const {
    return direccion;
}
/**
 * @brief Asignamos una dirrecion al garito
 * @param direccion
 */
void Garito::setDireccion(const std::string &direccion){
    if (direccion == ""|| direccion.length()<5){

        throw std::string ("ERROR-Garito.cpp: Cadena vacia o direccion demasiado pequenia");

    }else{
        this->direccion = direccion;
    }
}
