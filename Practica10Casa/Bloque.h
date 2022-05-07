//
// Created by soria on 30/04/2022.
//

#ifndef PRUEBA_BLOQUE_H
#define PRUEBA_BLOQUE_H

#include "ItemApilable.h"
class Bloque: public ItemApilable{
    std::string descripcion ="Un bloque de tierra";
public:

    Bloque()=default;
    Bloque (std::string descripcion);
    Bloque (std::string descripcion, int numElementos);
    virtual std::string getDescripcion() override;
    virtual ~Bloque();

};


#endif //PRUEBA_BLOQUE_H
