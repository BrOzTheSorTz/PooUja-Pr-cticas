//
// Created by soria on 26/02/2022.
//

#include "Fecha.h"
#include <iostream>
#include <ctime>
#include <sstream> ///< Para transformar los datos números en cadena de caracteres para el formato CSV

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
/**
 * @brief Constructor por defecto que asigna la fecha actual
 */
Fecha::Fecha() {

    std::time_t t= std::time(0); // obtiene el tiempo ahora
    std::tm* now = std::localtime(&t);//Esto lo que hace es extrapolarlo a la hora de nuestra ciudad

    dia =now->tm_mday;
    mes = (now->tm_mon+1);//Le sumamos un 1 ya que los valores van entre 0 y 11
    anio = (now->tm_mday+2009);

}

bool Fecha::operator<(const Fecha &f2) {
    bool menor = false;
    if(this->anio < f2.anio){
        menor =true;

    }else if ( this->anio >f2.anio){
        //No pasa nada porque sería falso y se quedaría conforme esta
    }else{
        if(this->mes< f2.mes){
            menor = true;
        }else if ( this->mes > f2.mes){

        }else{
            if(this->dia < f2.dia){
                menor = true;
            }
        }
    }

    return menor;
}

bool Fecha::operator==(const Fecha &f2){
    return (this->dia == f2.dia && this->mes==f2.mes && this->anio == f2.anio);
}

bool Fecha::operator<=(const Fecha &f2) {
    return (this->operator<(f2) || this->operator==(f2));
}

bool Fecha::operator>=(const Fecha &f2) {
    //Si no es menor es porque es mayor o igual
    return !(this->operator<(f2));
}

bool Fecha::operator>(const Fecha &f2) {
    return !(this->operator<(f2) || this->operator==(f2));
}

bool Fecha::operator!=(const Fecha &f2) {
    return !(this->operator==(f2));
}

/**
 * @brief Muestra la fecha en formato CSV
 * @return fecha encadenada
 */
std::string Fecha::toCSV() const {


    std::stringstream ss;///< Varible del tipo stringstream
    ss<< this->getAnio() << ";" << this->getMes() << ";" << this->getDia();///< guardamos los valores que queremos mostrar independientemente de si son cadenas de caracteres o no



    return ss.str();///<Con el método .str() convertimos los caracteres a string
}
