//
// Created by soria on 25/03/2022.
//

#include "Escuadron.h"
#include <stdexcept>

/**
 * @brief Constructor por defecto
 * @post Iniciaremos cada componente del vector
 *       a nullptr
 */
Escuadron::Escuadron() {
    //integrantes[0]=new Piloto;
    for(int i=0;i<TAM_MAX;++i){
        integrantes[i]= nullptr;
    }

}
/**
 * @brief COnstructor parametrizado
 * @param nombre nombre del escuadrón
 * @param base  nombre de la base
 */

Escuadron::Escuadron(const std::string &nombre, const std::string &base,Piloto *p) : nombre(nombre), base(base){
    integrantes[0]=p;
    ++numPilotos;
}

/**
 * @brief Añado un piloto al escuadron
 * @param p Piloto
 * @return Referencia al objeto para poder encadenar métodos
 */
Escuadron& Escuadron::addPiloto(Piloto &p) {
    if(numPilotos ==TAM_MAX){
        throw std::length_error("El escuadron esta lleno");
    }
    integrantes[numPilotos]=&p;
    ++numPilotos;

    return *this;
}

/**
 * @brief Destructor
 * @post Liberamos la relación pero no destruimos
 *       el objeto agregado
 */
Escuadron::~Escuadron() {
    for(int i=0;i<TAM_MAX;++i){
        if(integrantes[i]!= nullptr){
            integrantes[i]= nullptr;
        }
    }


}

/**
 * @brief Obtenemos un piloto
 * @param cual posición del piloto que queremos obtener
 * @return el piloto
 */
Piloto &Escuadron::obtenerPiloto(int cual) {
    if(cual<1 || cual >50){
        throw std::out_of_range("El valor de la posición no es correcto");
    }

    return (*integrantes[cual-1]);
}

void Escuadron::quitarPiloto(int cual) {
    if(cual<1 || cual >TAM_MAX){
        throw std::out_of_range("No se puede acceder a ningun piloto del escuadron con dicho indice");

    }
    //En este caso al ser una agregación
    //no eliminamos al piloto si no que simplemente
    //lo echamos del escuadron
    integrantes[cual-1]= nullptr;
    for(int i=cual-1;i<numPilotos-1;++i){
        integrantes[i]=integrantes[i+1];
    }
    integrantes[numPilotos-1]= nullptr;
    numPilotos--;


}
/**
 * @brief Calculamos el número medio de misiones
 *        de los pilotos integrados en el escuadrón
 * @return el número medio de misiones
 * @post Devuelve un int ya que el número de misiones
 *       no tiene sentido que sea de 3.6
 */
int Escuadron::promedioMisones() {
    int numMisiones=0;
    int media =0;


    for(int i=0;i<numPilotos;++i){
        numMisiones=numMisiones + integrantes[i]->getNumMisiones();


    }
    media = numMisiones/numPilotos;

    return media;
}

/**
 * @brief Obtenemos el nombre del escuadrón
 * @return nombre del escuadrón
 */
const std::string &Escuadron::getNombre() const {
    return nombre;
}
/**
 * @brief Obtenemos el nombre de la base del escuadrón
 * @return base del escuadrón
 */
const std::string &Escuadron::getBase() const {
    return base;
}

/**
 * @brief Cambiamos de base al escuadrón
 * @param base Nombre de la base
 */
void Escuadron::setBase(const std::string &base) {
    Escuadron::base = base;
}

/**
 * @brief Cambiamos el nombre del escuadrón
 * @param nombre Nuevo nombre del escuadrón
 */
void Escuadron::setNombre(const std::string &nombre) {
    Escuadron::nombre = nombre;
}

/**
 * @brief Constructor parametrizado
 * @param nombre nombre del escuadrón
 * @param base  nombre de la base del escuadrón
 */
Escuadron::Escuadron(const std::string &nombre,const std::string &base) : nombre(nombre),base(base) {}

/**
 * @brief Obtenemos el numero de pilotos del escuadron
 * @return número de pilotos
 */
int Escuadron::getNumPilotos() const {
    return numPilotos;
}
