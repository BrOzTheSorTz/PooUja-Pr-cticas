#include <iostream>
#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"
#include "djutils.h"

int main() {

    int MAX_TEMAZOS = 20;
    int MAX_GARITOS = 10;

    Fecha miCumple(22,11,2003);
    Fecha ultimaChampionsMadrid(26,5,2018);
    Fecha ultimaChampionsBarcelona(6,6,2015);

    Temazo canciones[MAX_TEMAZOS]; //Vector que almacena 20 temazos

    //Creamos un puntero a un objeto en el cual estén los datos de la casa del DJ
    Garito* pMiCasa = nullptr;
    pMiCasa = new Garito("CasaDJ","Jaen");

    //Vector de 10 punteros a garitos y se creen objetos para los 2 primeros punteros
    Garito* pGaritos[MAX_GARITOS];
    std::string nombre = "";
    std::string direccion = "";

    ///Creamos objetos para los 2 primeros punteros
    for(int i=0;i<MAX_GARITOS;++i){
        if(i<2){
            std::cout << "Introduzca el nombre: ";
            std::getline(std::cin >> std::ws, nombre);

            std::cout << "Introduzca la direccion: ";
            std::getline(std::cin >> std::ws, direccion);

            pGaritos[i] = new Garito(nombre, direccion);
        }else{
            pGaritos[i]= nullptr;
        }

    }


    //Para los 3 primeros temazos del vector modificar sus atributos

    ///El primer temazo, el ultimo garito en que se ha usado debe ser la casa del DJ
    ///Para los otros dos puede ser cualquiera
    ///La fecha de último uso del primer temzazo debe ser mi cumpleaños
    ///La del 2º temazo debe ser la fecha en la que el Madrid ganó su última champions
    ///La del 3º la del día que lo hizo el Barcelona

    //Utilizamos el encadenamientos de set ya lo que hemos puesto en estos que devuelvan una referencia al objeto para poder encadenarlos
    canciones[0].setTitulo("Malamente").setInterprete("Rosalia").setDuracion(120).setFechaUltimoUso(miCumple).setNombreUltimoGarito(pMiCasa->getNombre());
    canciones[1].setTitulo("Ultima noche").setInterprete("Rafael").setDuracion(180).setFechaUltimoUso(ultimaChampionsMadrid).setNombreUltimoGarito(pGaritos[0]->getNombre());
    canciones[2].setTitulo("Castle on the hill").setInterprete("Ed Sheeran").setDuracion(220).setFechaUltimoUso(ultimaChampionsBarcelona).setNombreUltimoGarito(pGaritos[1]->getNombre());



    //Vamos a mostrar los temazos usados por última vez antes del 1 de enero de 2016
    Fecha f(1,1,2016);
    mostrarTemazosAnteriores(canciones,MAX_TEMAZOS,f);






    //Si hay new , hay que crear los deletes correspondientes

    delete pMiCasa;
    pMiCasa= nullptr; ///Recomendable hacer esto
        ///Para borrar los elementos de un vector de punteros
    for(int i= 0;i<MAX_GARITOS;++i){
        if(pGaritos[i]!= nullptr){
            delete pGaritos[i];
            pGaritos[i]= nullptr;
        }
    }


    return 0;
}
