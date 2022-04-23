/**
 * @file PoderFisico.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef PODERFISICO_H
#define PODERFISICO_H

#include "Poder.h"

/**
 * @brief
 */
class PoderFisico: public Poder
{
   public:
      PoderFisico ( ) = default;
      PoderFisico ( std::string nmb, std::string dsc, std::string aA, float cD );
      PoderFisico ( const PoderFisico& orig );
      virtual ~PoderFisico ( );
      PoderFisico& operator= ( const PoderFisico& orig );
      //Esto lo hago para que se puede ordenar un vector de punteros a poderes
      virtual float getCapacidadDestructiva()const override;
};

#endif /* PODERFISICO_H */

