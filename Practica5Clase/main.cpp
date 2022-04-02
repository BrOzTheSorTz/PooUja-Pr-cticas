/** 
 * @file main.cpp
 * @author Casipro Gramo 
 * @author Yoyapro GRamo
 *
 * @date Fecha estelar 20160309
 */
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Piloto.h"
#include "StarFighter.h"
#include "Droide.h"
#include "Informe.h"

using namespace std;


int main ( int argc, char** argv )
{
   string datosPilotos[5] = {"Dameron Poe;Jakku;100;123456;---", 
                             "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos", 
                             "Han Solo;Corellia;247;126786;Impacto en motor izquierdo", 
                             "Chewbacca;Kashyyk;115;136786;---", 
                             "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos"};
   string datosNaves[5] = {"Kuat Systems;Delta-7;1", 
                           "Kuat Systems;Delta-7B;1", 
                           "Incom Corporation;T-65B X-wing;1", 
                           "Koensayr Manufacturing;Y-wing;2", 
                           "Kuat Systems;A-wing;1"};
   string datosDroides[5] = {"Industrial Automation;R2-D2", 
                             "Industrial Automation;R2-KT", 
                             "AccuTronics;R3-D3",
                             "AccuTronics;R3-KT", 
                             "Arakyd Industries;C3PO"};

   //Creamos array de clase pilotos, naves y droides
   int tam=5;
   Piloto pilotos[tam];
   StarFighter naves[tam];
   Droide droides[tam];

   //Utilizadndo el método frommCSV se carguen en cada array creado anteriormente
   //los datos proporcionados en los arrays de texto

   //Creacion de los pilotos

   for(int i=0;i<tam;++i){
       pilotos[i].fromCSV(datosPilotos[i]);


   }
   //Creacion de las naves
   for(int i=0;i<tam;++i){
       naves[i].fromCSV(datosNaves[i]);
   }
   //Creación de los droides

   for(int i=0;i<tam;++i){
       droides[i].fromCSV(datosDroides[i]);
   }
   //Vamos a capturar las posibles excepciones
    try{
        //Asociamos el primer piloto con el 3º droide y la 2º nave
        pilotos[0].setNave(&naves[1]);
        pilotos[0].setAyudadoPorDroide(&droides[2]);


        //Asociamos el segundo piloto con el 1º droide y la 4º nave
        pilotos[1].setNave(&naves[3]);
        pilotos[1].setAyudadoPorDroide(&droides[0]);

        //Generar informes con los datos de las últimas misiones de los dos primeros pilotos
        Informe iPiloto1;
        Informe iPiloto2;
        Informe i3;

        iPiloto1 = pilotos[0].generaInforme();
        iPiloto2 = pilotos[1].generaInforme();


        //Mostramos los datos de los informes
        std::cout << "Informe 1: " << iPiloto1.toCSV() << std::endl;
        std::cout << "Informe 2: " << iPiloto2.toCSV() << std::endl;


        //Ponemos como averiado el droide R2

        droides[0].setAveriado(true);

        //Ahora se lo asignamos a Han Solo
        try{
            pilotos[2].setAyudadoPorDroide(&droides[0]);
        }catch (std::invalid_argument &e){
            std::cout<<e.what()<<std::endl;

        }
        //Generamos el informe
        i3=pilotos[2].generaInforme();
        //Mostramos el informe
        std::cout<<"Informe 3: "<<i3.toCSV()<<endl;

        //Probamos los métodos toCSV y fromCSV de droide

        //Mostramos en CSV el droide 2
        std::cout<<"Probando metodo toCSV: "<<droides[2].toCSV()<<std::endl;
        std::string formatoCSV ="Arakyd Industries;C3PO;VERDADERO";
        Droide d2;
        d2.fromCSV(formatoCSV);

        //Mostramos el dato para ver si lo hemos hecho bien
        std::cout <<"Probando metodo fromCSV: "<<d2.toCSV()<<std::endl;


    }catch (std::invalid_argument &e){
        //La biblioteca estandar de excepciones de c++ , en cada excepcion
        //tiene un método que permite obtener la información de la excepción
        // y ese método es el what()
        std::cerr<<e.what()<<std::endl;
    }



    return 0;
}

