//
// Created by soria on 10/04/2022.
//

#ifndef PRUEBA_PODERPSIQUICO_H
#define PRUEBA_PODERPSIQUICO_H
#include "Poder.h"

class PoderPsiquico:public Poder {


public:
    PoderPsiquico();
    PoderPsiquico(std::string nombre, std::string descripcion,std::string afectaA,float capacidad);
    PoderPsiquico(const PoderPsiquico &orig);
    PoderPsiquico& operator=(const PoderPsiquico &otro);


};


#endif //PRUEBA_PODERPSIQUICO_H
