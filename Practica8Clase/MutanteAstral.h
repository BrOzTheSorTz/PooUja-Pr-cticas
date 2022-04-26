//
// Created by admin on 26/04/2022.
//

#ifndef PRUEBA_MUTANTEASTRAL_H
#define PRUEBA_MUTANTEASTRAL_H

#include "Mutante.h"
class MutanteAstral:public Mutante{

private:
    bool usado =false;
    int numPoderes =0;///<No puede tener mas de 1

public:

    MutanteAstral();
    MutanteAstral(const MutanteAstral &orig);
    Mutante& operator= (const MutanteAstral &otro);
    //Solo permitemos que se añadan poderes Psiquicos
    virtual void addPoder(const PoderPsiquico &p) override;
    virtual void addPoder(const PoderFisico &p) override;
    virtual void addPoder(const Poder &p) override;
    virtual float capacidadDestructivaTotal () override;

};


#endif //PRUEBA_MUTANTEASTRAL_H
