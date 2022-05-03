//
// Created by admin on 03/05/2022.
//

#ifndef PRUEBA_BOLADENIEVE_H
#define PRUEBA_BOLADENIEVE_H
#include "ItemApilableArrojable.h"

class BolaDeNieve:public ItemApilableArrojable {
private:
    std::string descripcion ="Bola de nieve";
public:
    BolaDeNieve()=default;
    BolaDeNieve(std::string _descripcion):descripcion(_descripcion){}///<In line porque es algo muy corto
    virtual std::string getDescripcion() override;
    virtual std::string lanzar() override;
    virtual ~BolaDeNieve();

};


#endif //PRUEBA_BOLADENIEVE_H
