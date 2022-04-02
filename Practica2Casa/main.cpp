#include <iostream>
#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"
#include "djutils.h"

int main() {

    int respuesta =0;

    //Crear un temazo por defecto y otro parametrizado
    Temazo cancion1;
    Temazo cancion2("Shivers","Ed sheeran",240);
    //Crear dos garitos , uno por parametrización y otro usando el constructor de copia
    Garito puesto1 ("Nuit","Avenidad de madrid");
    Garito puesto2=puesto1;
    //Crear dos fechas, una por defecto y otra con el constructor parametrizado
    Fecha fecha1;
    Fecha fecha2(1,3,2022);


    //Mostramos los datos de los objetos anteriores
    std::cout<<"CANCIONES: "<<std::endl;
    mostrarTemazo(cancion1);
    mostrarTemazo(cancion2);

    std::cout<<"GARITOS: "<<std::endl;
    mostrarGarito(puesto1);
    mostrarGarito(puesto2);

    std::cout<<"FECHA: "<<std::endl;
    mostrarFecha(fecha1);
    mostrarFecha(fecha2);

    //Modificamos los datos del segundo garito
    modificarGarito(puesto2);
    mostrarGarito(puesto2);


    //MENU
    std::cout<<"Que desea hacer hacer??:"<<std::endl;
    std::cout<<"1-Mostrar Datos de temazos, 2- Mostrar Datos de garitos,"
               <<" 3-Mostrar los datos de las Fechas, 4-Modificar los datos del segundo Garito, 5-Terminar programa"<<std::endl;
    std::cin >>respuesta;
    do{
        if (respuesta == 1) {
            std::cout<<"CANCIONES: "<<std::endl;
            mostrarTemazo(cancion1);
            mostrarTemazo(cancion2);
            std::cout<<"Que desea hacer hacer??:"<<std::endl;
            std::cout<<"1-Mostrar Datos de temazos, 2- Mostrar Datos de garitos,"
                     <<" 3-Mostrar los datos de las Fechas, 4-Modificar los datos del segundo Garito, 5-Terminar programa"<<std::endl;
            std::cin >>respuesta;

        } else if (respuesta == 2) {
            std::cout<<"GARITOS: "<<std::endl;
            mostrarGarito(puesto1);
            mostrarGarito(puesto2);

            std::cout<<"Que desea hacer hacer??:"<<std::endl;
            std::cout<<"1-Mostrar Datos de temazos, 2- Mostrar Datos de garitos,"
                     <<" 3-Mostrar los datos de las Fechas, 4-Modificar los datos del segundo Garito, 5-Terminar programa"<<std::endl;
            std::cin >>respuesta;
        } else if (respuesta == 3) {
            std::cout<<"FECHA: "<<std::endl;
            mostrarFecha(fecha1);
            mostrarFecha(fecha2);

            std::cout<<"Que desea hacer hacer??:"<<std::endl;
            std::cout<<"1-Mostrar Datos de temazos, 2- Mostrar Datos de garitos,"
                     <<" 3-Mostrar los datos de las Fechas, 4-Modificar los datos del segundo Garito, 5-Terminar programa"<<std::endl;
            std::cin >>respuesta;
        } else if (respuesta == 4) {
            modificarGarito(puesto2);

            std::cout<<"Que desea hacer hacer??:"<<std::endl;
            std::cout<<"1-Mostrar Datos de temazos, 2- Mostrar Datos de garitos,"
                     <<" 3-Mostrar los datos de las Fechas, 4-Modificar los datos del segundo Garito, 5-Terminar programa"<<std::endl;
            std::cin >>respuesta;
        }
    }while(respuesta !=5);


    return 0;
}
