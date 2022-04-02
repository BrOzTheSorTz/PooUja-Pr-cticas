//
// Created by soria on 26/02/2022.
//

#include <sstream>
#include "Temazo.h"
#include "ParametroNoValido.h"
#include "Fecha.h" ///< Para llamar a toCSV() en el atributo fecha de temazo

/**
 * Se inicializan las varibles de clase en el cpp y fuera de cualquier método
 */
int Temazo:: numTemazos = 0;

/**
 * @brief Constructor por defecto
 */
Temazo:: Temazo(){
    numTemazos = numTemazos+1;
    idTemazo = numTemazos;

}
/**
 * @brief Constructor parametrizado
 * @param _titulo
 * @param _interprete
 * @param _duracion
 */

Temazo::Temazo(std::string _titulo, std::string _interprete, int _duracion, std::string _nombreUltimoGarito,Fecha _fechaUltimoUso,std::string _genero)
:titulo(_titulo),interprete(_interprete), duracion(_duracion),nombreUltimoGarito(_nombreUltimoGarito),fechaUltimoUso(_fechaUltimoUso){

    if(_genero.length()<= 2){
        throw ParametroNoValido("Temazo.cpp", " Constructor parametrizado"," No existe el genero");
    }else{
        genero = _genero;
        numTemazos=numTemazos+1;
        idTemazo = numTemazos;
    }

}
/**
 * @brief Constructor de copia
 * @param orig
 */
Temazo::Temazo(const Temazo &orig)
:titulo (orig.titulo),
interprete  (orig.interprete),
duracion  (orig.duracion),
puntuacion  (orig.puntuacion),
genero (orig.genero),
nombreUltimoGarito( orig.nombreUltimoGarito),
fechaUltimoUso(orig.fechaUltimoUso){

    numTemazos = numTemazos +1;
    idTemazo=numTemazos;

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
 * @brief Incrementa la puntuación de un temazo
 * @param incremento número de puntos a sumar
 * @details Lanza una excepción si el número no está entre [-10,10]
 *
 */
void Temazo::incrementarPuntuacion(int incremento) {
    if(incremento <-10 || incremento>10){
        throw ParametroNoValido("Temazo.cpp"," incrementarPuntuacion()"," El incremento no puede ser ni menor de -10 ni mayor de 10");

    }else{
        this->puntuacion=this->puntuacion + incremento;
    }

}
/**
 * Mostramos el id de un temazo
 * @return El id de un temazo
 */
int Temazo:: getId() const{
    return idTemazo;
}

/**
 * @brief Mostramos el contenido de un Temazo
 * @return El valor de los atributos separados por ";"
 */
std::string Temazo::toCSV() const {
    std::stringstream ss;
    ss<<this->idTemazo<<";"<<this->titulo<<";"<<this->interprete<<";"<<this->duracion<<";"<<
        this->puntuacion<<";"<<this->nombreUltimoGarito<<
        ";"<<(this->fechaUltimoUso).toCSV();

    std::string resultado=ss.str();

    return resultado;
}

/**
 * @brief Introducimos una puntuación al temazo
 * @param puntuacion Puntuación de la canción
 * @return El objeto para poder llamar a varios setters a la vez
 */

Temazo& Temazo::setPuntuacion(int puntuacion) {
    if(puntuacion <-10 || puntuacion>10){
        throw ParametroNoValido("Temazo.cpp ","setPuntuacion()","Puntuacion no valida");
    }
    Temazo::puntuacion = puntuacion;
    return *this;///<Para poder luego encadenarlo con otros setters
}
