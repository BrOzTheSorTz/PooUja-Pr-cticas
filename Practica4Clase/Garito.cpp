//
// Created by soria on 26/02/2022.
//

#include "Garito.h"

//Necesitamos incluir este fichero para poder usar la excepción
//Como podemos ver, estamos estableciendo una relación de dependencia

#include "ParametroNoValido.h"

/**
 * @brief Constructor parametrizado
 * @param _nombre
 * @param _direccion
 */
Garito::Garito(std::string _nombre, std::string _direccion)
    :nombre(_nombre),direccion(_direccion){

    if (nombre == "" || nombre.length()<2) {
        throw ParametroNoValido("Garito.cpp"," Garito()"," Nombre demasiado corto");
    }
}
/**
 * @brief Constructor de copia
 * @param orig
 */
Garito::Garito(const Garito &orig)
:nombre(orig.nombre),direccion ( orig.direccion){

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
        throw ParametroNoValido("Garito.cpp"," setNombre()"," Nombre demasiado corto");
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

        throw ParametroNoValido("Garito.cpp", " setDireccion()"," Dirección demasiado corta");


    }else{
        this->direccion = direccion;
    }
}
/**
 * @brief Muestra del contenido de garito
 * @return Cadena de caracteres formada por el valor de sus atributos
 */
std::string Garito::toCSV() const {
    return (this->nombre + ";" + this->direccion);
}
