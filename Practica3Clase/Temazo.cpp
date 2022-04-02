//
// Created by soria on 26/02/2022.
//

#include "Temazo.h"

/**
 * @brief Constructor parametrizado
 * @param _titulo
 * @param _interprete
 * @param _duracion
 */

Temazo::Temazo(std::string _titulo, std::string _interprete, int _duracion, std::string _nombreUltimoGarito,Fecha _fechaUltimoUso,std::string _genero)
:titulo(_titulo),interprete(_interprete), duracion(_duracion),nombreUltimoGarito(_nombreUltimoGarito),fechaUltimoUso(_fechaUltimoUso){

    if(_genero.length()<= 2){
        throw std::string("ERROR: No existe el genero!");
    }else{
        genero = _genero;
    }

}
/**
 * @brief Constructor de copia
 * @param orig
 */
Temazo::Temazo(const Temazo &orig):
    interprete (orig.interprete),duracion(orig.duracion),puntuacion(orig.puntuacion),genero(orig.genero),
    nombreUltimoGarito(orig.nombreUltimoGarito),fechaUltimoUso(orig.fechaUltimoUso){
    /**
     * Esto no se hace así , hay que inicializarlo en la secuencia de inicialización
     *
     * titulo = orig.titulo;
    interprete = orig.interprete;
    duracion = orig.duracion;
    puntuacion = orig.puntuacion;
    genero = orig.genero;
    nombreUltimoGarito= orig.nombreUltimoGarito;
    fechaUltimoUso= orig.fechaUltimoUso;
    **/

}
/**
 * @brief Destructor de copia
 */
Temazo::~Temazo() {

}
/**
 * @brief Obtenemos el titulo de una cancion
 * @return titulo
 */
std::string Temazo::getTitulo() const {
    return titulo;
}
/**
 * @brief asignamos el titulo a un temazo
 * @param titulo
 */

/**Utilizamos setters con referencia a un objeto para permitir una asignación encadenada*/

Temazo &Temazo::setTitulo(const std::string &titulo) {

    this->titulo = titulo;

    return *this;
}
/**
 * @brief obtenemos el interprete de una cancion
 * @return interprete
 */
std::string Temazo::getInterprete() const {
    return interprete;
}
/**
 * @brief Asigna un interprete a una canción
 * @param interprete
 */
Temazo &Temazo::setInterprete(const std::string &interprete) {

    this->interprete= interprete;

    return *this;
}
/**
 * @brief obtenemos la duración de una canción
 * @return duracion
 */
int Temazo::getDuracion() const {
    return duracion;
}
/**
 * @brief Asignamos una duración a una canción
 * @param duracion
 */
Temazo &Temazo::setDuracion(const int &duracion) {
    this->duracion = duracion;
    return *this;
}
/**
 * @brief Obtenemos la puntuacion de una canción
 * @return puntutacion
 */
int Temazo::getPuntuacion() const {
    return puntuacion;
}



std::string Temazo::getGenero() const {
    return genero;
}

Temazo& Temazo::setNombreUltimoGarito(std::string nombre) {
    this->nombreUltimoGarito= nombre;
    //Devuelvo una referencia al objeto para que pueda encadenar más setters
    return *this;

}

std::string Temazo::getNombreUltimoGarito() const {
    return this->nombreUltimoGarito;

}

Temazo& Temazo::setFechaUltimoUso(const Fecha &f) {
    this->fechaUltimoUso= f; //Usando constructor de copia
    return *this;
}
Fecha Temazo::getFechaUltimoUso() const {
    return this->fechaUltimoUso;
}
/**
 * @brief sobrecarga de operadores
 * @param orig
 * @return Referencia al objeto
 */
Temazo& Temazo::operator=(const Temazo &orig) {
    //Comprobamos que no estamos asignando el mismo objeto
    if(this != &orig){
        titulo = orig.titulo;
        interprete = orig.interprete;
        duracion = orig.duracion;
        puntuacion = orig.puntuacion;
        genero = orig.genero;
        nombreUltimoGarito= orig.nombreUltimoGarito;
        fechaUltimoUso= orig.fechaUltimoUso;

    }
    //Devolver una referencia permite encadenar este operador
    return *this;
}
/**
 * @brief sobrecarga del mayor
 * @param t2
 * @return si un temazo es mayor que otro según su duración
 */
bool Temazo::operator>(const Temazo &t2) {

    return this->duracion > t2.duracion;
}
/**
 * @brief Sobrecarga del operador de comparación
 * @param t2
 * @return si un temazo es igual a otro según su duración
 */
bool Temazo::operator==(const Temazo &t2) {
    return this->duracion == t2.duracion;
}
