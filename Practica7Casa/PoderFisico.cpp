//
// Created by soria on 10/04/2022.
//

#include "PoderFisico.h"


/**
 * @brief Constructor por defecto
 * @post Debemos inicializar la superclase también
 */
PoderFisico::PoderFisico() :Poder("No asignado","-","-",0) {

}

/**
 * @Constructor de copia
 * @param orig
 * @post Copiamos los datos de la clase padre primero
 */
PoderFisico::PoderFisico(const PoderFisico &orig)
        :Poder(orig){

}

/**
 * @brief Constructor parametrizado
 * @param nombre Nombre del poder
 * @param descripcion Descripcion del poder
 */
PoderFisico::PoderFisico(std::string nombre, std::string descripcion,std::string afectaA,float capacidad)
:Poder(nombre,descripcion,afectaA,capacidad)
{
}

/**
 * @brief Asignamos el contenido de un poder fisico a otro
 * @param otro
 * @return Referencia al objeto
 */
PoderFisico &PoderFisico::operator=(const PoderFisico &otro) {

    if(this != &otro){
        //Los atributos heredados hay que copiarlos con la asignación de la clase que hereda
        this->Poder::operator=(otro);
    }



    return *this;
}
