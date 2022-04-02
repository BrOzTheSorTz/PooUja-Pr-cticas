/** 
 * @file Droide.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <sstream>

#include "Droide.h"
#include <string>

using std::string;

int Droide::_numDroides = 0;

Droide::Droide ( ): Droide ( "", "" )
{ }

Droide::Droide ( string marca, string modelo ): _marca (marca), _modelo (modelo)
{
   _numDroides++;
   _idD = _numDroides;
}

Droide::Droide ( const Droide& orig ): _marca(orig._marca), _modelo(orig._modelo),averiado(orig.averiado)
{
   _numDroides++;
   _idD = _numDroides;
}

Droide::~Droide ( )
{ }

int Droide::getIdD ( ) const
{
   return _idD;
}

Droide& Droide::setModelo ( string modelo )
{
   this->_modelo = modelo;
   return (*this);
}

string Droide::getModelo ( ) const
{
   return _modelo;
}

Droide& Droide::setMarca ( string marca )
{
   this->_marca = marca;
   return (*this);
}

string Droide::getMarca ( ) const
{
   return _marca;
}

string Droide::toCSV () const
{
   std::stringstream aux;
   std::string averiadoString="";
   aux << _marca << " ; "
       << _modelo;
   if(averiado ==true){
       averiadoString="VERDADERO";
   }else{
       averiadoString="FALSO";
   }

   return ( aux.str () +";"+averiadoString);
}

Droide& Droide::operator = ( const Droide& otro )
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
      averiado = otro.averiado;
   }
   
   return ( *this );
}

/**
 * @brief Añadimos un valor a los atributos del objeto mediante el formatoCSV
 * @param formatoCSV Los atributos del objeto en formato CSV
 */
void Droide::fromCSV(string formatoCSV) {

    ///Para pasar de formato CSV , a poner cada opción de este en los atributos del objeto
    ///En el DROIDE es de la forma
    /// marca;modelo
    std::stringstream ss;
    string marca, modelo;
    bool _averiado ;
    std::string averiadoString; ///<En el formato CSV hemos puesto VERDADERO/FALSO


    ss.str(formatoCSV);

    std::getline(ss,marca,';');
    getline(ss,modelo,';');
    ss>>averiadoString;

    if(averiadoString=="VERDADERO"){
        _averiado=true;
    }else{
        _averiado=false; ///<En cualquier otro caso la nave no esta averiada solo tenemos en cuenta el caso en el que lo está
    }

    this->setMarca(marca).setModelo(modelo).setAveriado(_averiado);


}
/**
 * @brief Obtenemos si un droide está averiado
 * @return valor booleano
 */
bool Droide::getAveriado() const {
    return averiado;
}

/**
 * @brief Asignamos al droide un valor booleano que indica si está averiado
 * @param averiado valor booleano
 * @return Referencia al objeto para poder encadenar los métodos setters
 */
Droide& Droide::setAveriado(bool averiado) {
    Droide::averiado = averiado;
    return *this;
}
