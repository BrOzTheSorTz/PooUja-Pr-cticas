/** 
 * @file StarFighter.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "StarFighter.h"

using std::string;

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter ( ):StarFighter ( "", "" ) {
    //partes[0] = new Pieza; // Siempre va a ver una
    for(int i=0;i<TAM_MAX;++i){
        partes[i]= nullptr;
    }
}

StarFighter::StarFighter ( string marca, string modelo ):
                           _marca (marca), _modelo(modelo)
{
    //partes[0]=new Pieza;
   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::StarFighter ( const StarFighter& orig ):
    _marca(orig._marca),_modelo(orig._modelo),
    _numPlazas(orig._numPlazas)
{
    //@todo Preguntar al maestro
    for(int i=0;i<orig.numPiezas;++i){
        partes[i]=new Pieza(*orig.partes[i]);
    }
   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::~StarFighter ( )
{
    for(int i=0;i<numPiezas;++i){
        if(partes[i]!= nullptr){
            delete partes[i];
            partes[i]=nullptr;
        }
    }
}

/**
 * @done Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de plazas no puede ser <= 0
 */
StarFighter& StarFighter::setNumPlazas ( int numPlazas )
{
   if ( numPlazas <= 0 )
   {
      throw std::invalid_argument ( "StarFighter::StarFighter: el número de"
                                    " plazas no puede ser negativo" );
   }

    this->_numPlazas = numPlazas;
    return *this;
}

int StarFighter::getNumPlazas ( ) const
{
   return _numPlazas;
}

StarFighter& StarFighter::setModelo ( string modelo )
{
   this->_modelo = modelo;
   return *this;
}

string StarFighter::getModelo ( ) const
{
   return _modelo;
}

StarFighter& StarFighter::setMarca ( string marca )
{
   this->_marca = marca;
   return *this;
}

string StarFighter::getMarca ( ) const
{
   return _marca;
}

int StarFighter::getIdSF ( ) const
{
   return _idSF;
}

string StarFighter::toCSV () const
{
   std::stringstream aux;

   aux << _marca << " ; "
       << _modelo << " ; "
       << _numPlazas;

   return aux.str ();
}

StarFighter& StarFighter::operator = (const StarFighter& otro)
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
      _numPlazas = otro._numPlazas;
   }
   
   return *this;
}

void StarFighter::fromCSV (string& datos)
{
   std::stringstream aux;
   
   aux << datos;
   
   getline ( aux, _marca, ';' );
   getline ( aux, _modelo, ';' );
   aux >> _numPlazas;
}
/**
 * @brief Añadimos una pieza de la nave
 * @param p Pieza que se le añade
 */
void StarFighter::addPieza(Pieza &p) {
    if(numPiezas ==TAM_MAX){
        throw std::length_error("No puede tener mas piezas");

    }
    Pieza *nueva=new Pieza(p);

    partes[numPiezas]=nueva;///<Importante hacer esto al tratarse de una composición
    ++numPiezas;


}
/**
 * @brief Obtenemos una pieza de la nave
 * @param cual Posición de la pieza que queremos
 * @return Pieza
 */
Pieza &StarFighter::obtenerPieza(int cual) {
    if(cual <1 || cual >TAM_MAX){
        throw std::out_of_range("No podemos acceder a la pieza que deseas");

    }
    return (*partes[cual-1]);
}

/**
 * @brief Quitamos la pieza de una nave
 * @param cual indice de la pieza en el vector
 *
 */
void StarFighter::quitarPieza(int cual) {
    // <= Ya que si hay una pieza, esta no se puede quitar
    if(cual <=1 || cual >TAM_MAX){
        throw std::out_of_range("No podemos acceder a la pieza que deseas");///<Out of range para cuando no podemos acceder a un dato ya que el usuario a introducido un número incorrecto

    }

    //Ya no se puede volver a utilizar la pieza
    delete partes[cual-1];
    partes[cual-1] = nullptr;

    for(int i=cual-1;i<numPiezas-1;++i){
        partes[i]=partes[i+1];
    }
    //Ya hemos copiado el ultimo dato en la posicion anterior
    partes[numPiezas-1]= nullptr;
    --numPiezas;

}

/**
 * @brief Calcula el peso total de las piezas
 *        que componen una nave
 * @return Peso de las piezas de la nave en kg
 */
float StarFighter::calculaPeso() {

    float peso =0.0;

    for(int i=0;i<numPiezas;++i){
        peso = peso + partes[i]->getPeso();
    }

    return peso;
}

/**
 * @brief Añadimos piezas a la nave de otra forma
 * @param _nombre Nombre de la pieza
 * @param _peso Peso de la pieza
 * @param _descripcion Descripción de la pieza
 * @return Referencia al propio objeto para poder encadenar métodos
 */
StarFighter& StarFighter::addPieza(std::string _nombre, float _peso, std::string _descripcion) {
    if(numPiezas ==TAM_MAX){
        throw std::length_error("No puede tener mas piezas");

    }
    partes[numPiezas]=new Pieza(_nombre,_peso,_descripcion);

    ++numPiezas;

    return *this ;

}

/**
 * @brief Obtenemos el número de piezas que compone la nave
 * @return número de piezas
 */
int StarFighter::getNumPiezas() const {
    return numPiezas;
}

/**
 * @brief Añadimos una pieza a la nave
 * @param p pieza
 * @return Referencia al objeto
 */
StarFighter &StarFighter::addPieza(Pieza *p) {
    partes[numPiezas]=new Pieza(*p);
    ++numPiezas;

    return *this;
}
