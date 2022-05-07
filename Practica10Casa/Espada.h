//
// Created by soria on 30/04/2022.
//

#ifndef PRUEBA_ESPADA_H
#define PRUEBA_ESPADA_H
#include "Item.h"

class Espada: public Item{
private:
    std::string descripcion ="Una Espada";
public:

    Espada()=default;
    Espada (std::string descripcion);
    virtual std::string getDescripcion() override;
    Espada(const Espada &orig);
    virtual ~Espada();

};


#endif //PRUEBA_ESPADA_H
