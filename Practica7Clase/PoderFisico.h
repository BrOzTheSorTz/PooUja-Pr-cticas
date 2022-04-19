//
// Created by soria on 10/04/2022.
//

#ifndef PRUEBA_PODERFISICO_H
#define PRUEBA_PODERFISICO_H
#include "Poder.h"

class PoderFisico: public Poder  {

public:
    PoderFisico();
    PoderFisico(std::string nombre, std::string descripcion,std::string afectaA,float capacidad);
    PoderFisico(const PoderFisico &orig);
    PoderFisico& operator=(const PoderFisico &otro);

};


#endif //PRUEBA_PODERFISICO_H
