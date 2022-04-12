//
// Created by soria on 10/04/2022.
//

#include "PoderPsiquico.h"

/**
 * @brief Constructor por defecto
 * @post Debemos inicializar la superclase también
 */
PoderPsiquico::PoderPsiquico() :Poder("No asignado","-","-",0) {

}

/**
 * @Constructor de copia
 * @param orig
 * @post Copiamos los datos de la clase padre primero
 */
PoderPsiquico::PoderPsiquico(const PoderPsiquico &orig)
:Poder(orig){

}

/**
 * @brief Constructor parametrizado
 * @param nombre Nombre del poder
 * @param descripcion Descripcion del poder
 */
PoderPsiquico::PoderPsiquico(std::string nombre, std::string descripcion,std::string afectaA,float capacidad):
Poder(nombre,descripcion,afectaA,capacidad)
{
}

/**
 * @brief Asignamos el contenido de un poder psiquico a otro
 * @param otro
 * @return Referencia al objeto
 */
PoderPsiquico &PoderPsiquico::operator=(const PoderPsiquico &otro) {

    if(this != &otro){
        //Los atributos heredados hay que copiarlos con la asignación de la clase que hereda
        this->Poder::operator=(otro);
    }



    return *this;
}
