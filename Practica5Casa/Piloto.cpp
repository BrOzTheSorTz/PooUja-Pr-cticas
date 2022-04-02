/** 
 * @file Piloto.cpp
 * @author Yoyapro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Piloto.h"
#include <sstream>


using std::string;

int Piloto::_numPilotos = 0;

Piloto::Piloto ( ): Piloto ( "" )
{ }

Piloto::Piloto ( string nombre ): _nombre (nombre)
{
   _numPilotos++;
   _idP = _numPilotos;
}

Piloto::Piloto ( const Piloto& orig ): _nombre(orig._nombre),
                                       _nacionalidad(orig._nacionalidad),
                                       _numMisiones(orig._numMisiones),
                                       _fechaUltimaMision(orig._fechaUltimaMision),
                                       _incidenciasUltimaMision(orig._incidenciasUltimaMision),
                                       nave(orig.nave),
                                       droide(orig.droide)
{
   _numPilotos++;
   _idP = _numPilotos;
}

Piloto::~Piloto ( )
{
    nave = nullptr; ///<Una vez que destruyo el objeto , libero su relación
    droide=nullptr;
}

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de misiones no puede ser <= 0
 */
Piloto& Piloto::setNumMisiones ( int numMisiones )
{
    //Para realizar estas excepciones hay que incluir la bibliote de c++ de excepciones
    // que es : stdexcept
    if(numMisiones<0){
        throw std::invalid_argument("[Piloto::setNumMisiones]: El numero de misiones no pueden ser negativas");
    }
   this->_numMisiones = numMisiones;
   return *this;
}

int Piloto::getNumMisiones ( ) const
{
   return _numMisiones;
}

Piloto& Piloto::setNacionalidad ( string nacionalidad )
{
   this->_nacionalidad = nacionalidad;
   return *this;
}

string Piloto::getNacionalidad ( ) const
{
   return _nacionalidad;
}

Piloto& Piloto::setNombre ( string nombre )
{

    this->_nombre = nombre;
    return *this;
}

string Piloto::getNombre ( ) const
{
   return _nombre;
}

int Piloto::getIdP ( ) const
{
   return _idP;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener incidencias;
 *       haz esta comprobación y lanza la excepción correspondiente
 */
Piloto& Piloto::setIncidenciasUltimaMision ( string incidenciasUltimaMision )
{
    if(this->_numMisiones ==0){
        throw std::invalid_argument("[Piloto::setIncidenciasUltimaMision]: Si el numero de misiones es 0 no puede tener incidencias");
    }
   this->_incidenciasUltimaMision = incidenciasUltimaMision;
   return *this;
}

string Piloto::getIncidenciasUltimaMision ( ) const
{
   return _incidenciasUltimaMision;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
Piloto& Piloto::setFechaUltimaMision ( long fechaUltimaMision )
{
    if(this->_numMisiones ==0){
        throw std::invalid_argument("[Piloto::setFechaUltimaMision]: Si el numero de misiones es 0 no puede tener fecha de incidencias");
    }
   this->_fechaUltimaMision = fechaUltimaMision;
   return *this;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
long Piloto::getFechaUltimaMision ( ) const
{
    if(this->_numMisiones ==0){
        throw std::invalid_argument("[Piloto::getFechaUltimaMision]: Si el numero de misiones es 0 no podemos acceder a una fecha de incidencias porque no tiene");
    }
   return _fechaUltimaMision;
}

string Piloto::toCSV () const
{
   std::stringstream aux;

   aux << _nombre << " ; "
       << _nacionalidad << " ; "
       << _numMisiones << " ; "
       << _fechaUltimaMision << " ; "
       << _incidenciasUltimaMision;

   return ( aux.str () );
}

Piloto& Piloto::operator = ( const Piloto& otro )
{
   if ( this != &otro )
   {
      _nombre = otro._nombre;
      _nacionalidad = otro._nacionalidad;
      _numMisiones = otro._numMisiones;
      _fechaUltimaMision = otro._fechaUltimaMision;
      _incidenciasUltimaMision = otro._incidenciasUltimaMision;
      nave = otro.nave;
      droide = otro.droide;
   }
   
   return ( *this );
}

/**
 * @brief Consulta la nave del piloto
 * @return La dirección de memoria de la nave. Si no hay ninguna
 *         devuelve nullptr
 */
StarFighter *Piloto::getNave() const {
    return nave;
}


/**
 * @brief Cambia la nave del piloto
 * @param nave
 * @return La dirección de memoria de la nave que
 *         había previamente
 */
StarFighter* Piloto::setNave(StarFighter *nave) {
    StarFighter* aux = this->nave;
    Piloto::nave = nave;

    return aux;
}

/**
 * @brief Consulta los droides de un piloto
 * @return Dirección de memoria del Droide de un piloto
 */
Droide *Piloto::getDroide() const {
    return droide;
}

/**
 * @brief Cambiamos el droide de un piloto
 * @param droide
 * @return La dirección de memoria del droide anterior al que
 *         le queremos añadir
 */
Droide* Piloto::setAyudadoPorDroide(Droide *droide) {
    Droide* aux = this->droide;
    Piloto::droide = droide;

    return aux;
}

/**
 * @brief Dada un piloto , esto le permite generar un informe
 * @return El objeto de tipo informe
 * @post En el informe ponemos el idPiloto, la fecha de su ultima misión
 *       y en los datos: idNave, idDroide y las incidencias de la última misión del piloto
 */
Informe Piloto::generaInforme() {

    std::stringstream aux;
    std::string datos="";

    Informe i1(this->getFechaUltimaMision());

    i1.setIdPiloto(this->getIdP()); ///<Obtenemos el Id del piloto
    aux<< "ID de la nave: "<<this->getNave()->getIdSF()<<".Id del droide: "<< this->getDroide()->getIdD()<<".Incidencias ultima mision: "<<this->getIncidenciasUltimaMision();
    datos = aux.str();
    i1.setDatosInforme(datos);

    return i1;
}
/**
 * @brief Asignamos un valor a los atributos de Piloto a través del formato CSV indicado
 * @param formatoCSV
 */


void Piloto::fromCSV(std::string formatoCSV) {
    std::stringstream ss;

    //El formato CSV  es: NOMBRE-NACIONALIDAD-NUMMISIONES-FECHA-INCIDENCIAS
    //Luego es este el orden que hay que seguir ya que es lo que nos vamos a encontrar primero

    std::string nombre, nacionalidad;
    int numMisiones;
    long fechaUltimaMision;
    std::string incidencias;

    //Inicializamos el contenido de ss. Otra forma de hacerlo es ss << formatoCSV;

    ss.str(formatoCSV);

    std::getline(ss,nombre,';');
    std::getline(ss,nacionalidad,';');
    ss>>numMisiones;
    ss.ignore(1);
    ss>>fechaUltimaMision;
    ss.ignore(1);
    std::getline(ss,incidencias);

    this->setNombre(nombre).setNacionalidad(nacionalidad).setNumMisiones(numMisiones).setFechaUltimaMision(fechaUltimaMision).setIncidenciasUltimaMision(incidencias);

}
