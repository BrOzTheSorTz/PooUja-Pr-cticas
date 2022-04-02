//
// Created by soria on 13/03/2022.
//

#include "ParametroNoValido.h"
#include <iostream>
#include "Fecha.h"
#include <sstream> ///<Convertir un int en string

/**
 * @brief Constructor parametrizado
 * @param _fichero fichero donde está el error
 * @param _funcion  función donde está el error
 * @param _descripcion por qué ha ocurrido esto
 */
ParametroNoValido::ParametroNoValido(std::string _fichero, std::string _funcion, std::string _descripcion,Fecha _fecha)
:fichero(_fichero),funcion(_funcion),descripcion(_descripcion), fecha(_fecha){


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
    std::stringstream  ss;
    std::string valor="";
    ss<< valorNoValido;

    valor = ss.str();

    return ("ERROR: "+this->getFichero()+";"+this->getFuncion()+";"+ this->getDescripcion() + ";" + this->getFecha() + "; "+ valor);

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

/**
 * @brief Devolvemos la fecha en la que ocurre el error
 * @return La fecha en cadena de caracteres
 */
const std::string ParametroNoValido::getFecha() const {

    return fecha.toString();
}
/**
 * @brief Constructor parametrizado
 * @param _fichero
 * @param _funcion
 * @param _descripcion
 * @param _valor
 * @param _fecha
 * @post Hemos añadido el parámetro de valor, para que me devuelva el valor por el cual se ha producido el error
 *
 */
ParametroNoValido::ParametroNoValido(std::string _fichero, std::string _funcion, std::string _descripcion, int _valor,
                                     Fecha _fecha):
                                     fichero(_fichero),funcion(_funcion),descripcion(_descripcion),valorNoValido(_valor),fecha(_fecha){

}

