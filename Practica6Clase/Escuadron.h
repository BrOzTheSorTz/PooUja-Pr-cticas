//
// Created by soria on 25/03/2022.
//

#ifndef PRUEBA_ESCUADRON_H
#define PRUEBA_ESCUADRON_H
#include <string>
#include "Piloto.h"


class Escuadron {
public:
    static const int TAM_MAX=50;
private:
    std::string nombre = "Desconocido";
    int numPilotos =0;///<Siempre que se crea un escuadrón hay al menos 1 integrante
    Piloto *integrantes[TAM_MAX];
    std::string base ="No asignada";
    bool enMision=false;

public:
    Escuadron(); ///Creo que no me interesa que haya
                ///Un constructor por defecto ya que en este caso
                ///se me crearía un escuadrón sin ningún Piloto
    Escuadron(const std::string &nombre, const std::string &base,Piloto *p);

    Escuadron(const std::string &nombre, const std::string &base);

    Escuadron& addPiloto(Piloto &p);

    int getNumPilotos() const;

    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);

    void setNumPilotos(int numPilotos);

    void quitarPiloto(int cual);
    Piloto& obtenerPiloto(int cual);
    int promedioMisones();
    virtual ~Escuadron();

    const std::string &getBase() const;
    void setBase(const std::string &base);
    Escuadron& operator+(Escuadron &e);
    Escuadron& operator=( Escuadron& otro);
    bool estaEnMision();
    void comenzarMision();


};


#endif //PRUEBA_ESCUADRON_H
