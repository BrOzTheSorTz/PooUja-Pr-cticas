/** 
 * @file Informe.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Informe.h"

using std::string;

long Informe::_numInformes = 0;

Informe::Informe ( ): Informe ( 0 )
                      
{ }

Informe::Informe ( long fecha ): _fechaEstelar(fecha)
{
   _numInformes++;
   _idI = _numInformes;
}

Informe::Informe ( const Informe& orig ): _idPiloto(orig._idPiloto),
                                          _fechaEstelar(orig._fechaEstelar),
                                          _datosInforme(orig._datosInforme)
{
   _numInformes++;
   _idI = _numInformes;
}

Informe::~Informe ( )
{
}

Informe& Informe::setDatosInforme ( string datosInforme )
{
   this->_datosInforme = datosInforme;
   
   return ( *this );
}

string Informe::getDatosInforme ( ) const
{
   return _datosInforme;
}

/**
 * @throw Comprobar el valor, y si es negativo, lanzar excepción
 */
Informe& Informe::setFechaEstelar ( long fechaEstelar )
{
    if(fechaEstelar<0){
        throw std::invalid_argument("[Informe::setFechaEstelar]:El numero de la fecha no puede ser negativo");
    }
   this->_fechaEstelar = fechaEstelar;

   return ( *this );
}

long Informe::getFechaEstelar ( ) const
{
   return _fechaEstelar;
}

/**
 * @throw Comprobar el valor, y si es negativo, lanzar excepción
 */
Informe& Informe::setIdPiloto ( int idPiloto )
{
    if(idPiloto <0){
        throw std::invalid_argument("[Informe::setIdPiloto]: El id no puede ser negativo");
    }
   this->_idPiloto = idPiloto;
   
   return ( *this );
}

int Informe::getIdPiloto ( ) const
{
   return _idPiloto;
}

int Informe::getIdI ( ) const
{
   return _idI;
}

string Informe::toCSV () const
{
   std::stringstream aux;

   aux << "Fecha estelar: " << _fechaEstelar << " ; "
       << "id de piloto: " << _idPiloto << " ; "
       << _datosInforme;

   return ( aux.str () );
}

Informe& Informe::operator = ( const Informe& otro )
{
   if ( this != &otro )
   {
      _idPiloto = otro._idPiloto;
      _fechaEstelar = otro._fechaEstelar;
      _datosInforme = otro._datosInforme;
   }
   
   return ( *this );
}

/**
 * @brief Asignamos a los atributos del objeto lo indicado en el formato CSV
 * @param formatoCSV
 */

void Informe::fromCSV(std::string formatoCSV) {
    std::stringstream ss;
    ///Necesitamos como varibles tantas como elementos hayan en el formato CSV

    int idPiloto;
    long fechaEstelar;
    std::string datosInforme;

    //FECHA-ID -DATOS -> Este es el orden del formato luego hay que coger los atributos en este orden

    ss.str(formatoCSV);
    //COgemos el primer dato y eliminamos el punto y coma correspondiente
    ss>>idPiloto;
    ss.ignore(1);

    //COgemos el segundo dato y eliminamos el punto y coma correspondiente
    ss>>fechaEstelar;
    ss.ignore(1);

    std::getline(ss,datosInforme);

    this->setIdPiloto(idPiloto).setFechaEstelar(fechaEstelar).setDatosInforme(datosInforme);


}
