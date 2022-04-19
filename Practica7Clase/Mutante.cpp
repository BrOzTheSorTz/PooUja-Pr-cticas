/**
 * @file Mutante.cpp
 * @author algarcia
 *
 */

#include <stdexcept>
#include <sstream>

#include "Mutante.h"


Mutante::Mutante(string nombre, string apodo, int fechaN, string nacionalidad) 
    : _nombreReal(nombre),
      _apodo(apodo),
      _fechaDeNacimiento(fechaN),
      _nacionalidad(nacionalidad)
      {
          for(int i=0;i<MAX_PODERES;++i){
              poderes[i]= nullptr;
          }
    
}

Mutante::Mutante(const Mutante& orig)
    : _nombreReal(orig._nombreReal),
    _apodo(orig._apodo),
    _fechaDeNacimiento(orig._fechaDeNacimiento),
    _nacionalidad(orig._nacionalidad)
 {
    for(int i=0;i<numPoderes;++i){
        poderes[i]=new Poder(*orig.poderes[i]); ///<Para que no apunten a los mismos poderes
    }
    for(int i=numPoderes;i<MAX_PODERES;++i){
        poderes[i]= nullptr;
    }
    
}

Mutante::~Mutante() {

    for(int i=0;i<MAX_PODERES;++i){
        if(poderes[i]!= nullptr){
            delete poderes[i];
            poderes[i]= nullptr;
        }
    }
}

Mutante& Mutante::setNombreReal(string nombreReal) {
    this->_nombreReal = nombreReal;return *this;
}

string Mutante::getNombreReal() const {
    return _nombreReal;
}

Mutante& Mutante::setNacionalidad(string nacionalidad) {
    this->_nacionalidad = nacionalidad;return *this;
}

string Mutante::getNacionalidad() const {
    return _nacionalidad;
}

Mutante& Mutante::setFechaDeNacimiento(int fechaDeNacimiento) {
    this->_fechaDeNacimiento = fechaDeNacimiento;return *this;
}

int Mutante::getFechaDeNacimiento() const {
    return _fechaDeNacimiento;
}

Mutante& Mutante::setApodo(string apodo) {
    this->_apodo = apodo;return *this;
}

string Mutante::getApodo() const {
    return _apodo;
}


/**@brief Representación CSV de un mutante
   @post  Genera la representación básica en CSV, incluiyendo los poderes*/
string Mutante::toCSV() const{
    std::stringstream aux;

    std::string cadenaPoderes="";
    for(int i=0;i<numPoderes;++i){
        cadenaPoderes = cadenaPoderes + poderes[i]->toCSV();
    }
    aux << _nombreReal << ";"
        << _apodo << ";"
        << _fechaDeNacimiento << ";"
        << _nacionalidad<<";"
        << cadenaPoderes;

    return aux.str();
}

Mutante& Mutante::operator=(const Mutante& orig) {
    if (this != &orig) {
        _nombreReal = orig._nombreReal;
        _apodo = orig._apodo;
        _fechaDeNacimiento = orig._fechaDeNacimiento;
        _nacionalidad = orig._nacionalidad;

    }
    for(int i=0;i<numPoderes;++i){
        poderes[i]=new Poder(*orig.poderes[i]); ///<Para que no apunten a los mismos poderes
    }
    for(int i=numPoderes;i<MAX_PODERES;++i){
        poderes[i]= nullptr;
    }

    return  *this;
}
/**
 * @brief Constructor por defecto
 */
Mutante::Mutante(): Mutante("-","-",0,"-") {

    //Llamos desde el constructor por defecto al constructor parametrizado
    //para apuntar directamente los datos a nullptr sin tener que copiar el bucle
    //for aquí de nuevo
}

/**
 * @brief Añadimos un poder a un Mutante
 * @param nombre Nombre del poder
 * @param descripcion Descripción del poder
 * @param afectaA A quien afecta el poder
 * @param capacidadD Capacidad de destrucción del poder
 * @trow std::invalid_argument Cuando no se pueden añadir más poderes
 * @return Referencia al objeto para encadenar métodos
 */
Mutante &Mutante::addPoder(std::string nombre, std::string descripcion, std::string afectaA, float capacidadD) {
    //Esta versión tiene un problema ya que si añadimos otros nuevos atributos, habría que añadirlos a esto también
    //por eso es mejor el método de addPoder() donde solo añadimos el objeto de tipo Poder
    if(numPoderes ==MAX_PODERES){
        throw std::invalid_argument("[Mutante::addPoder], No puede tener mas de 10 poderes");

    }

    poderes[numPoderes]=new Poder(nombre,descripcion,afectaA,capacidadD);
    ++numPoderes;







    return *this;
}


/**
 * @brief Quitamos el poder que nos diga el usuario
 * @param cual Indice del poder en el vector
 * @post Para acceder al poder en el vector , lo haremos con cual-1
 * @throw std::invalid_argument Cuando no hay ningun poder en la posición indicada
 * @return Referencia al objeto
 */
Mutante &Mutante::borrarPoder(int cual) {

    if(cual<1|| cual>numPoderes){
        throw std::invalid_argument("[Mutante::borrarPoder], No se puede acceder a la posición indicada");
    }

    delete poderes[cual-1];

    for(int i=cual-1;i<numPoderes-1;++i){
        poderes[i]=poderes[i+1];
    }

    delete poderes [numPoderes-1];
    poderes[numPoderes-1]= nullptr;

    --numPoderes;




    return *this;
}

/**
 * @brief Calcula la capacidad Destructiva del conjunto de todos los poderes
 * @return Suma de la capacidad destructiva de todos los poderes
 */
float Mutante::capacidadDestructiva() {
    float capacidad=0;

    for(int i=0;i<numPoderes;++i){
        capacidad =capacidad + poderes[i]->getCapacidadDestructiva();
    }


    return capacidad;
}
/**
 * @brief Añadimos un Poder Fisico al mutante
 * @param nombre
 * @param descripcion
 * @param afectaA
 * @param capacidadD
 * @return Referencia al propio objeto
 */
Mutante &Mutante::addPoderFisico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadD) {
    if(numPoderes ==MAX_PODERES){
        throw std::invalid_argument("[Mutante::addPoder], No puede tener mas de 10 poderes");

    }
    poderes[numPoderes]=new PoderFisico(nombre,descripcion,afectaA,capacidadD);
    ++numPoderes;


    return *this;
}

/**
 * @brief Añadimos un Poder Psiquico al mutante
 * @param nombre
 * @param descripcion
 * @param afectaA
 * @param capacidadD
 * @return Referencia al propio objeto
 */
Mutante &Mutante::addPoderPsiquico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadD) {
    if(numPoderes ==MAX_PODERES){
        throw std::invalid_argument("[Mutante::addPoder], No puede tener mas de 10 poderes");

    }
    poderes[numPoderes]=new PoderPsiquico(nombre,descripcion,afectaA,capacidadD);
    ++numPoderes;


    return *this;
}

/**
 * @brief Añadimos un poder al mutante
 * @param p Poder el cual queremos copiar
 * @throw std::invalid_argument En el caso de que se supere el número de poderes
 * @return Referencia al propio objeto
 */
Mutante &Mutante::addPoder(const Poder &p) {
    if(numPoderes ==MAX_PODERES){
        throw std::invalid_argument("[Mutante::addPoder], No puede tener mas de 10 poderes");

    }
    poderes[numPoderes]=new Poder(p);
    ++numPoderes;


    return *this;
}

/**
 * @brief Añadimos un poder al mutante
 * @param p Poder el cual queremos copiar
 * @return Referencia al propio objeto
 */
Mutante &Mutante::addPoderFisico(const PoderFisico &p) {
    if(numPoderes ==MAX_PODERES){
        throw std::invalid_argument("[Mutante::addPoder], No puede tener mas de 10 poderes");

    }
    poderes[numPoderes]=new PoderFisico(p);
    ++numPoderes;


    return *this;
}

/**
 * @brief Añadimos un poder al mutante
 * @param p Poder el cual queremos copiar
 * @return Referencia al propio objeto
 */
Mutante &Mutante::addPoderPsiquico(const PoderPsiquico &p) {
    if(numPoderes ==MAX_PODERES){
        throw std::invalid_argument("[Mutante::addPoder], No puede tener mas de 10 poderes");

    }
    poderes[numPoderes]=new PoderPsiquico(p);
    ++numPoderes;


    return *this;
}

/**
 * @brief Obtenemos el número de poderes totales del mutante
 * @return Número de poderes
 */
int Mutante::getNumPoderes() const {
    return numPoderes;
}

/**
 * @brief Devolvemos el poder que nos indique el usuario
 * @param cual
 * @post si cual =1 la posición del vector es 0 , y así respectivamente
 * @return Dirección de memoria del poder
 */
Poder *Mutante::obtenerPoder(int cual) {
    if(cual<1 || cual > numPoderes)
        throw std::invalid_argument("[Mutante::obtenerPoder].No se puede acceder al poder");


    return poderes[cual-1];
}

