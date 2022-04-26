/**
 * @file PoderPsiquico.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <sstream>

#include "PoderPsiquico.h"

using std::string;

PoderPsiquico::PoderPsiquico ( string nmb, string dsc, string aA, float cD ):
               Poder ( nmb, dsc, aA, cD )
{

}

PoderPsiquico::PoderPsiquico ( const PoderPsiquico& orig ):
               Poder(orig),lucidez(orig.lucidez)
{ }

PoderPsiquico::~PoderPsiquico ( )
{ }

Poder& PoderPsiquico::operator= ( const PoderPsiquico& orig )
{
   if ( this != &orig )
   {
       //TODO Ojo habría primero que copiar los datos de la clase padre y luego ya los métodos específicos del objeto
      this->Poder::operator= ( orig );
      lucidez = orig.lucidez;
   }

   return  *this;
}
/**
 * @brief Obtenemos la lucidez de un poder psiquico
 * @return Valor de la lucidez
 */
float PoderPsiquico::getLucidez() const {
    return lucidez;
}
/**
 * @brief Asignamos un valor a la lucidez
 * @param lucidez
 * @return Referencia a un poder( clase padre) para poder hacer asignaciones
 *         encadenadas
 * @throw std::invalid_argument Al no estar el valor de lucidez entre [0,1]
 */
Poder& PoderPsiquico::setLucidez(float lucidez) {
    if(lucidez <0 || lucidez >1) throw std::invalid_argument("PoderPsiquico::setLucidez.Valor incorrecto de lucidez");

    PoderPsiquico::lucidez = lucidez;
    return *this;
}

/**
 * @brief Obtenemos la capacidad destructiva de Un poder psiquico
 * @return Capacidad destructiva
 */
float PoderPsiquico::getCapacidadDestructiva() const {

    /*OJO, habría que llamar al métedo de la clase padre para obtener la capacidad
    destructiva, por eso hay que llamarlo con el nombre de clase (Poder::getCapacidad())

    -Aplicamos lo que se nos pide
    */
    return Poder::getCapacidadDestructiva()*lucidez;
}
/**
 * @brief Convertimos en formato CSV un poder psiquico
 * @return cadena de texto con la información del poder psiquico
 */
std::string PoderPsiquico::toCSV() const {
    std::stringstream  aux;
    aux<<";"<<lucidez;

    return Poder::toCSV() + aux.str();
}
