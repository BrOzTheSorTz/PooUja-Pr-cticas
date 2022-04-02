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

Droide::Droide ( const Droide& orig ): _marca(orig._marca), _modelo(orig._modelo)
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

   aux << _marca << " ; "
       << _modelo;

   return ( aux.str () );
}

Droide& Droide::operator = ( const Droide& otro )
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
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

    ss.str(formatoCSV);

    std::getline(ss,marca,';');
    getline(ss,modelo,';');

    this->setMarca(marca).setModelo(modelo);


}
