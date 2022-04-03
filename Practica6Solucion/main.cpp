/** 
 * @file main.cpp
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "Piloto.h"
#include "Escuadron.h"

using namespace std;

/**
 * @todo Ver el enunciado del ejercicio 5 de la práctica
 */
int main ( int argc, char** argv )
{
    string datosPilotos[5] = {"Dameron Poe;Jakku;100;123456;---",
                              "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos",
                              "Han Solo;Corellia;247;126786;Impacto en motor izquierdo",
                              "Chewbacca;Kashyyk;115;136786;---",
                              "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos"};

    Piloto pilotos[5];
    for(int i=0;i<5;++i){
        pilotos[i].fromCSV(datosPilotos[i]);
    }

    Pieza p1 ={"tubo escape",23,"Expulsion gases"};
    Pieza p2 ={"Aleron",124,"Descenso mejorado"};
    Pieza p3 ={"Radio",12,"Mejor comunicacion"};
    Pieza p4 ={"Tornillo",1,""};

    Escuadron e1,e2;
    e1.setNombre("La vaca loca");
    e2.setNombre("OMG");

    e1.addPiloto(pilotos[0]).addPiloto(pilotos[1]);
    e2.addPiloto(pilotos[2]).addPiloto(pilotos[3]).addPiloto(pilotos[4]);


    std::cout<<"Promedio misiones e1: "<<e1.promedioMisones()<<std::endl;
    std::cout<<"Promedio misiones e2: "<<e2.promedioMisones()<<std::endl;

    StarFighter n1,n2;
    n1.setMarca("BM2");
    n2.setMarca("TESLA");

    n1.addPieza(p1).addPieza(p3).addPieza(p2);
    n2.addPieza(p4).addPieza(p3).addPieza(p1);

    std::cout<<"Peso n1: "<<n1.calculaPeso()<<std::endl;
    std::cout<<"Peso n2: "<<n2.calculaPeso()<<std::endl;
    Escuadron suma;
    suma=e1 +e2;

    for(int i=0;i<suma.getNumPilotos();++i){
        std::cout<<suma.obtenerPiloto(i+1).getNombre()<<std::endl;
    }
    return 0;
}

