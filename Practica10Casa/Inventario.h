//
// Created by soria on 06/05/2022.
//

#ifndef PRUEBA_INVENTARIO_H
#define PRUEBA_INVENTARIO_H
#include "Contenedor.h"
#include "Item.h"

class Inventario:public Contenedor<Item> {
public:
    //Por defecto puede guardar 35 objetos distintos
    //No nos interesa que se cree un inventario por defecto
    Inventario (int cuantosCaben =35);
    virtual ~Inventario();


};


#endif //PRUEBA_INVENTARIO_H
