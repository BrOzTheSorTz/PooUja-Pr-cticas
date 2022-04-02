//
// Created by soria on 26/02/2022.
//

#include "Fecha.h"
#include <ctime>
/**
 * @brief Constructor parametrizado
 * @param _dia
 * @param _mes
 * @param _anio
 */
Fecha::Fecha(int _dia, int _mes, int _anio)
    :dia(_dia),mes(_mes),anio(_anio){

}
/**
 * @brief Constructor de copia
 * @param orig
 */
Fecha::Fecha(const Fecha &orig) {
    dia =orig.dia;
    mes=orig.mes;
    anio=orig.anio;

}
/**
 * @brief Obtenemos el dia
 * @return dia
 */
int Fecha::getDia() const {
    return dia;
}
/**
 * @brief Asignamos un dia
 * @param dia
 */
void Fecha::setDia(int dia) {
    this->dia = dia;
}
/**
 * @brief Obtenemos el mes
 * @return mes
 */
int Fecha::getMes() const {
    return mes;
}
/**
 * @brief Asignamos un mes
 * @param mes
 */
void Fecha::setMes(int mes) {
    this->mes = mes;
}
/**
 * @brief Obtenemos el anio
 * @return anio
 */
int Fecha::getAnio() const {
    return anio;
}
/**
 * @brief Asignamos un anio
 * @param anio
 */
void Fecha::setAnio(int anio) {
    this->anio = anio;
}

