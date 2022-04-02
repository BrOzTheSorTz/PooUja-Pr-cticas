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
Escuadron::Escuadron():nombre("Desconocido"),base("No asignado") {
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

/**
 * @brief Creamos un escuadrón basado en la suma de 2 escuadrones
 * @param e Escuadron que se le suma al objeto que estamos tratando en el momento
 * @return La suma de los dos escuadrones
 * //@todo No se si hace falta asignar el nombre
 * @post El nombre y la base del nuevo escuadrón sera la suma del nombre y base de los escuadrones
 *      que estamos sumando
 */
Escuadron &Escuadron::operator+( Escuadron &e) {
    Escuadron suma;
    suma.setNombre(this->getNombre()+e.getNombre());
    suma.setBase(this->getBase() + e.getBase());
    int numPilotosSuma=0;

    for(int i=0;i<this->getNumPilotos();++i){
        suma.addPiloto(this->obtenerPiloto(i+1));
        ++numPilotosSuma;


    }

    for(int i=0;i<e.getNumPilotos();++i){
            suma.addPiloto(e.obtenerPiloto(i+1));
            ++numPilotosSuma;

    }

    suma.setNumPilotos(numPilotosSuma);

    e = suma;

    return e;
}

/**
 * @brief Asignamos un valor de pilotos determinados a un escuadrón
 * @param numPilotos Número de pilotos
 */
void Escuadron::setNumPilotos(int numPilotos) {
    Escuadron::numPilotos = numPilotos;
}

/**
 * @brief Sobrecargamos el operador de asignación
 * @param otro Escuadron que queremos asignar
 * @return Referencial al objeto en el que estamos
 */
Escuadron &Escuadron::operator=( Escuadron &otro) {
    if(this != &otro){
        this->nombre=otro.nombre;
        this->base= otro.base;

        for(int i=0;i<otro.getNumPilotos();++i){

            this->addPiloto(otro.obtenerPiloto(i+1));

        }
        this->numPilotos=otro.numPilotos;
    }
    return *this;
}

/**
 * @brief Mostramos si un escuadrón está en misión
 * @return True o False según si está en misión
 */
bool Escuadron::estaEnMision() {
    return this->enMision;
}

/**
 * @brief Cambia el estado de un Escuadrón a activo(TRUE) si sus integrantes están preparados
 *        sii tienen asignados una nave y un auxiliar
 */
void Escuadron::comenzarMision() {

    for(int i=0;i<this->getNumPilotos();++i){
        if(this->obtenerPiloto(i+1).getNave()== nullptr ||this->obtenerPiloto(i+1).getAuxiliar()== nullptr ){
            throw std::logic_error("El escuadrón no esta preparado para empezar la misión. Hay uno o varios pilotos sin asignar su dron o auxiliar");
        }
    }

    this->enMision=true;///<Si no salta la excepción es porque está preparado

}
