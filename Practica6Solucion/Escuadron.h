//
// Created by soria on 02/04/2022.
//

#ifndef PRUEBA_ESCUADRON_H
#define PRUEBA_ESCUADRON_H


#include <string>
#include "Piloto.h"


class Escuadron {
public:
    static const int MAX=50;
private:
    std::string nombre ="";
    int numPilotos=0;
    std::string base= "";
    Piloto *integrantes[MAX];

public:
    Escuadron();
    Escuadron(const std::string &nombre, int numPilotos, const std::string &base);
    virtual ~Escuadron();
    Escuadron(const Escuadron &orig)=default;

    Escuadron& addPiloto( Piloto &p);
    Piloto& obtenerPiloto(int cual);
    Escuadron& quitarPiloto(int cual);
    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);
    int getNumPilotos() const;
    void setNumPilotos(int numPilotos);
    const std::string &getBase() const;
    void setBase(const std::string &base);

    float promedioMisones();
    Escuadron operator+(const Escuadron &e);

};


#endif //PRUEBA_ESCUADRON_H
