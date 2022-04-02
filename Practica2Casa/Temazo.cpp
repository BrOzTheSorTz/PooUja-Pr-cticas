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
Temazo ::Temazo(std::string _titulo, std::string _interprete, int _duracion)
        :titulo(_titulo),interprete(_interprete),duracion(_duracion){

}

/**
 * @brief Constructor de copia
 * @param orig
 */
Temazo::Temazo(const Temazo &orig) {
    titulo = orig.titulo;
    interprete = orig.interprete;
    duracion = orig.duracion;
    puntuacion = orig.puntuacion;
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
void Temazo::setTitulo(const std::string &titulo) {
    this->titulo = titulo;
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
void Temazo::setInterprete(const std::string &interprete) {
    this->interprete = interprete;
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
void Temazo::setDuracion(int duracion) {
    this->duracion = duracion;
}
/**
 * @brief Obtenemos la puntuacion de una canción
 * @return puntutacion
 */
int Temazo::getPuntuacion() const {
    return puntuacion;
}
