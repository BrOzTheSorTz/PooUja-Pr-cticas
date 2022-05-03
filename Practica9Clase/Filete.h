//
// Created by soria on 30/04/2022.
//

#ifndef PRUEBA_FILETE_H
#define PRUEBA_FILETE_H
#include "Item.h"


class Filete:public Item {
private:
    std::string descripcion = "Un Filete";
public:

    Filete()=default;
    Filete (std::string descripcion);
    virtual std::string getDescripcion() override;

};


#endif //PRUEBA_FILETE_H
