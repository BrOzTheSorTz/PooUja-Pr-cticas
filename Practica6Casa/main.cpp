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
#include "StarFighter.h"
#include <stdexcept>


using namespace std;

void mostrarEscuadron(Escuadron &e){
    int tama= e.getNumPilotos();

    std::cout<<"Nombre: "<<e.getNombre()<<std::endl;
    std::cout<<"Base: "<<e.getBase()<<std::endl;

    for(int i=0;i<tama;++i){
        std::cout<<"Piloto "<<i+1<<std::endl;

        std::cout<<e.obtenerPiloto(i+1).toCSV();
        std::cout<<std::endl;
    }

}

void mostrarNave(StarFighter &n){
    int tama= n.getNumPiezas();
    std::cout<<"Marca: "<<n.getMarca()<<std::endl;
    std::cout<<"Modelo: "<<n.getModelo()<<std::endl;
    for(int i=0;i<tama;++i){
        std::cout<<"Pieza "<<i+1<<std::endl;
        std::cout<<n.obtenerPieza(i+1).toCSV()<<std::endl;
    }
}

/**
 * @done Ver el enunciado del ejercicio 5 de la práctica
 */
int main ( int argc, char** argv )
{
    try{
        string datosPilotos[5] = {"Dameron Poe;Jakku;100;123456;---",
                                  "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos",
                                  "Han Solo;Corellia;247;126786;Impacto en motor izquierdo",
                                  "Chewbacca;Kashyyk;115;136786;---",
                                  "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos"};
        int tama = 5;
        Piloto pilotos[tama];

        //Introducimos los datos de los pilotos mediante fromCSV()
        for (int i = 0; i < tama; ++i) {
            pilotos[i].fromCSV(datosPilotos[i]);
        }

        //Creamos 2 escuadrones

        ///El 1º escuadrón está formado por los 2 primeros pilots
        Escuadron e1 = {"Escuadron Salchicha", "Andorra", &pilotos[0]};
        e1.addPiloto(pilotos[1]);

        //Probando funcionalidad de los métodos del Escuadrón
        mostrarEscuadron(e1);
        e1.quitarPiloto(1);
        std::cout<<"Quitamos un piloto: "<<std::endl;
        mostrarEscuadron(e1);
        std::cout<<std::endl;

        ///El 2º escuadrón está formado por los otros 3
        Escuadron e2;

        e2.addPiloto(pilotos[2]).addPiloto(pilotos[3]).addPiloto(pilotos[4]);

        //Mostramos por consola el nombre y el promedio
        //de misiones de cada escuadrón
        std::cout << "Nombre ESCUADRON 1: " << e1.getNombre() << ". Promedio de misiones: " << e1.promedioMisones()
                  << std::endl;
        std::cout << "Nombre ESCUADRON 2: " << e2.getNombre() << ". Promedio de misiones: " << e2.promedioMisones()
                  << std::endl;

        //Creamos 2 star Fighters y añadimos 3 piezas a cada uno
        StarFighter n1("Tesla", "AX34");
        StarFighter n2 = {"BMW", "X3"};
        Pieza *nueva= new Pieza("Amortiguadores",34.5,"Mayor fluidez al aterrizar");

        n1.addPieza("Tornillo", 0.12, "Necesario para sujetar el motor").addPieza("Tubo de Escape", 14,
                                                                                  "Expulsion de gases").addPieza(
                "Ventanilla", 24, "Para poder ver a los enemigos");
        ///Me interesa que esto este justo debajo porque puede ser que la nave1 se construya pero la otra no
        //Mostramos la nave1
        std::cout<<"NAVE 1:"<<std::endl;

        mostrarNave(n1);
        std::cout<<std::endl;
        n1.addPieza(*nueva);
        n1.quitarPieza(4);
        //@todo No sé porque no se elimina la pieza una vez eliminada de la nave
        std::cout<<"Comprobamos si se ha eliminado la pieza: "<<nueva->toCSV()<<std::endl;
        mostrarNave(n1);
        std::cout<<std::endl;

        std::cout << "Peso de la NAVE 1: " << n1.calculaPeso() << std::endl;


        n2.addPieza("Radio", 14.12, "Necesario para escuchar a los aliados").addPieza("Tubo de Escape", 14,
                                                                                      "Expulsion de gases").addPieza(
                "Motor", 224, "Mejora del ultimo motor");
        std::cout << "Peso de la NAVE 2: " << n2.calculaPeso() << std::endl;
    }// las excepciones que hemos usado de la librería de c++ fueron: invalid_argument & out_of_range
    catch (std::invalid_argument &e){
        std::cerr<<e.what()<<std::endl;

    }
    catch (std::out_of_range &e){
        std::cerr<<e.what()<<std::endl;

    }
    //Los recursos tratados en memoria dinámica
    //En este caso las piezas de las naves
    //se encargaría de liberarlo el destructor ,verdad?

    return 0;
}

