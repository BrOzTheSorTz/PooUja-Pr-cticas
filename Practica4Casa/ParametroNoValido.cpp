//
// Created by soria on 13/03/2022.
//

#include "ParametroNoValido.h"
#include <iostream>

/**
 * @brief Constructor parametrizado
 * @param _fichero fichero donde está el error
 * @param _funcion  función donde está el error
 * @param _descripcion por qué ha ocurrido esto
 */
ParametroNoValido::ParametroNoValido(std::string _fichero, std::string _funcion, std::string _descripcion)
:fichero(_fichero),funcion(_funcion),descripcion(_descripcion){


}

/**
 * @brief Constructor por copia
 * @param orig Objeto del cual queremos copiar su contenido
 */
ParametroNoValido::ParametroNoValido(const ParametroNoValido &orig)
:fichero(orig.fichero),funcion(orig.funcion),descripcion(orig.descripcion){

}
/**
 * @brief Destructor
 * @brief Libera el contenido del objeto
 */
ParametroNoValido::~ParametroNoValido() {

}
/**
 * @brief Explica el error
 * @return Información sobre qué , dónde, etc. ha ocurrido el error
 */
std::string ParametroNoValido::queOcurre() const{
    return ("ERROR: "+this->getFichero()+";"+this->getFuncion()+";"+ this->getDescripcion());

}
/**
 * @brief obtenemos el valor del fichero
 * @return fichero donde ocurre el error
 */
const std::string &ParametroNoValido::getFichero() const {
    return fichero;
}

/**
 * @brief obtenemos el valor de la función
 * @return función donde se lanza la excepción
 */
const std::string &ParametroNoValido::getFuncion() const {
    return funcion;
}


/**
 *
 * @return Descripción del error
 */
const std::string &ParametroNoValido::getDescripcion() const {
    return descripcion;
}
