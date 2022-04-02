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


        ///Creamos el 3º escuadrón con 3 pilotos
        Escuadron e3;

        e3.addPiloto(pilotos[1]).addPiloto(pilotos[0]).addPiloto(pilotos[3]);

        //Creamos un escuadron resultado de la suma de e2 y e3
        Escuadron& eSuma=e2+e3;

        //Le cambiamos el nombre
        eSuma.setNombre("escuadronRojo");
        //Visualizamos el nombre de todos los pilotos del escuadrón rojo
        for(int i=0;i<eSuma.getNumPilotos();++i){
            std::cout<<"Piloto "<<i+1<<" ; "<<eSuma.obtenerPiloto(i+1).getNombre()<<std::endl;
        }

        //Comprobamos si el escuadron rojo está preparado
        try{
            eSuma.comenzarMision();
        }catch(std::logic_error &e){
            std::cout<<eSuma.getNombre()<<" no puede empezar una mision porque sus pilotos no estan preparados"<<std::endl;
        }



    }// las excepciones que hemos usado de la librería de c++ fueron: invalid_argument & out_of_range
    catch (std::invalid_argument &e){
        std::cerr<<e.what()<<std::endl;

    }
    catch (std::out_of_range &e){
        std::cerr<<e.what()<<std::endl;

    }
    catch(std::logic_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    //Los recursos tratados en memoria dinámica
    //En este caso las piezas de las naves
    //se encargaría de liberarlo el destructor ,verdad?

    return 0;
}

