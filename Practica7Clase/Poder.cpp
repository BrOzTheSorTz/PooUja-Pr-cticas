//
// Created by soria on 10/04/2022.
//

#include "Poder.h"
#include <sstream>
#include <iostream>

/**
 * @brief Constructor parametrizado
 * @param _nombre
 * @param _descripcion
 * @param _afectaA
 * @param _capacidadDestructiva
 */
Poder::Poder(std::string _nombre, std::string _descripcion, std::string _afectaA, float _capacidadDestructiva)
:nombre(_nombre),descripcion(_descripcion),afectaA(_afectaA),capacidadDestructiva(_capacidadDestructiva){


}

/**
 * @brief Constructor por defecto
 * @post Empleamos el constructor parametrizado
 */
Poder::Poder(): Poder("-","-","-",0)
{
}

/**
 * @brief Constructor de copia
 * @param orig Poder que queremos copiar al nuevo objeto
 */
Poder::Poder(const Poder &orig)
:nombre(orig.nombre),descripcion(orig.descripcion),afectaA(orig.afectaA),capacidadDestructiva(orig.capacidadDestructiva),inhibido(orig.inhibido)
{
}

/**
 * @brief Obtenemos el nombre del poder
 * @return El nombre del poder
 */
const std::string &Poder::getNombre() const {
    return nombre;
}

/**
 * @brief Asignamos un nombre al poder
 * @param nombre Nombre del poder
 */
void Poder::setNombre(const std::string &nombre) {
    Poder::nombre = nombre;
}

/**
 * @brief Obtenemos la descripción del poder
 * @return Descripción del poder
 */
const std::string &Poder::getDescripcion() const {
    return descripcion;
}

/**
 * @brief Asignamos una descripción al poder
 * @param descripcion Descripción del poder
 */
void Poder::setDescripcion(const std::string &descripcion) {
    Poder::descripcion = descripcion;
}

/**
 * @brief Obtenemos a quien afecta el poder
 * @return A quien afecta
 */
const std::string &Poder::getAfectaA() const {
    return afectaA;
}

/**
 * @brief Introducimos en cadena de texto a quienes afectan el poder
 * @param afectaA
 */
void Poder::setAfectaA(const std::string &afectaA) {
    Poder::afectaA = afectaA;
}

/**
 * @brief Obtenemos la capacidad de destrucción del poder
 * @return CapacidadDestructiva
 */
float Poder::getCapacidadDestructiva() const {

    //operador ternario

    return inhibido? 0 :capacidadDestructiva;
}

/**
 * @brief Asignamos una capacidad Destructiva
 * @param capacidadDestructiva
 */
void Poder::setCapacidadDestructiva(float capacidadDestructiva) {
    Poder::capacidadDestructiva = capacidadDestructiva;
}

/**
 * @brief Destructor del poder
 */
Poder::~Poder() {

}

/**
 * @brief Asignamos el valor de un poder a otro
 * @param otro El poder del cual queremos asignar a otro poder
 * @return Referencia al objeto para poder encadenar el método
 */
Poder &Poder::operator=(const Poder &otro) {

    //Primero comprobamos que no estamos haciendo a=a
    if(this != &otro){

        nombre=otro.nombre;
        descripcion=otro.descripcion;
        afectaA=otro.afectaA;
        capacidadDestructiva=otro.capacidadDestructiva;
        inhibido=otro.inhibido;



    }



    return *this;
}

/**
 * @brief Obtenemos un objeto en formato CSV
 * @return Objeto en formato CSV
 */
std::string Poder::toCSV() {

    std::stringstream aux;
    aux<<nombre<<";"<<descripcion<<";"<<afectaA<<";"<<capacidadDestructiva;

    return aux.str();

}

/**
 * @brief Constructor parametrizado
 * @param nombre Nombre del poder
 * @param descripcion Nombre de la descripción del poder
 */
Poder::Poder(const std::string &nombre, const std::string &descripcion) : nombre(nombre), descripcion(descripcion) {


}

/**
 * @brief Constructor parametrizado con otros parametros
 * @param nombre
 * @param descripcion
 * @param capacidadDestructiva
 */
Poder::Poder(const std::string &nombre, const std::string &descripcion, float capacidadDestructiva) : nombre(nombre),
                                                                                                      descripcion(
                                                                                                              descripcion),
                                                                                                      capacidadDestructiva(

                                                                                                              capacidadDestructiva) {}
/**
 * @brief Nos indica si un poder está inhibido
 * @return Estado del atributo inhibido
 */
bool Poder::isInhibido() const {
    return inhibido;
}

/**
 * @brief Cambiamos si el poder de un mutante puede usarse o no
 */
void Poder::cambiarInhibido() {
    inhibido = !inhibido;

}


