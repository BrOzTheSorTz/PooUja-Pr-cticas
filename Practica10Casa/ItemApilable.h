//
// Created by soria on 30/04/2022.
//

#ifndef PRUEBA_ITEMAPILABLE_H
#define PRUEBA_ITEMAPILABLE_H
#include <string>
#include "Item.h"

class ItemApilable: public Item{
private:
    int numElementos =1;///<Entre 1 y 64
public:
    ItemApilable()=default;///Necesario para crear objetos derivados
    ItemApilable(int _numElementos);
    void incrementaNumElementos(int cantidad);
    void decrementaNumElementos(int cantidad);
    int getNumElementos() const;


    //Es una clase abstracta,lo que nos permite hacer
    //que objeto no relacionados, tengan el mismo comportamiento
    //Ej: Un bloque y un filete no están relacionados pero si son apilables
    virtual std::string getDescripcion() =0;
};


#endif //PRUEBA_ITEMAPILABLE_H
