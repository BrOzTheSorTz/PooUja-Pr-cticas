//
// Created by admin on 26/04/2022.
//

#include <stdexcept>
#include "MutanteAstral.h"


/**
 * @brief Añadimos un poder psiquico al mutante astral
 * @param p Poder Psiquico
 * @pre Hay que introducir un poder psiquico
 */
void MutanteAstral::addPoder(const PoderPsiquico &p) {

    ++numPoderes;
    if(numPoderes==1){Mutante::addPoder(p);}
    else{
        throw std::invalid_argument("MutanteAstral::addPoder.No se le puede añadir otro poder Psiquico");
    }
}
/**
 * @brief Constructor por defecto
 */
MutanteAstral::MutanteAstral() :Mutante(){

}

/**
 * @brief Constructor de copia
 * @param orig Mutante astral del cual queremos copiar
 */
MutanteAstral::MutanteAstral(const MutanteAstral &orig):Mutante(orig),usado(orig.usado) {
    //FIXME Problema en el constructor de copia de mutante


}

Mutante &MutanteAstral::operator=(const MutanteAstral &otro) {
    if(this != &otro){
        //FIXME Problema en el operador de asignacion de mutante ya que no se tiene en cuenta el tipo de los poeres
        this->Mutante::operator=(otro);
        usado=otro.usado;
    }

    return *this;
}

/**
 * @brief Calculamos la capacidad destructiva de un mutante astral
 * @return La capacidad total
 * @throw std::out_of_range Si se han usado sus poderes una vez , no se pueden volver a usar
 */
float MutanteAstral::capacidadDestructivaTotal() {
    float capacidad=0;
    if(!usado){
        capacidad=Mutante::capacidadDestructivaTotal();
        usado = true; ///<Una vez que lo pedimos ya lo ha usado
        return capacidad;

    }else{
        throw std::out_of_range ("MutanteAstral::capacidadDestructivaTotal. Ya se han usado sus poderes , por lo que no se pueden volver a usar");
    }

}

/**
 * @brief Añadimos poder fisico
 * @param p
 * @throw std::invalid_argument Al utilizar este método
 */
void MutanteAstral::addPoder(const PoderFisico &p) {
    throw std::invalid_argument("MutanteAstral::addPoder. No se puede añadir un Poder Fisico");
}
/**
 * @brief Añadimos poder
 * @param p
 * @throw std::invalid_argument Al utilizar este método
 */
void MutanteAstral::addPoder(const Poder &p) {
    throw std::invalid_argument("MutanteAstral::addPoder. No se puede añadir un Poder ");

}
