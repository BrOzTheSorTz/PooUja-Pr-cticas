//
// Created by admin on 03/05/2022.
//

#ifndef PRUEBA_ITEMARROJABLE_H
#define PRUEBA_ITEMARROJABLE_H
#include <string>
#include "Item.h" ///<Necesario para la implementación de la descripcion

class ItemArrojable:public Item{
public:
    virtual std::string lanzar()=0;
    virtual std::string getDescripcion()=0;


};

#endif //PRUEBA_ITEMARROJABLE_H
