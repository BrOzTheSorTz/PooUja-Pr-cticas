#include <iostream>
#include "Vehiculo.h"

int main() {
    Vehiculo vehiculos[10];
    Vehiculo v1,v2;
    std::string matricula = "";
    int posicion = -2;
    Vehiculo *concesionario= nullptr; //Recomendable inicializar el vector a vacío

    int tama = 0;
    v1.muestraEnPantalla();

    std::cout<<"Introduzca el numero de elementos: "<<std::endl;
    std::cin>>tama;
    //Creo el espacio en memoria dinámica
    concesionario = new Vehiculo[tama];

    concesionario->rellenarVector(concesionario,tama);
    concesionario->mostrarVectorEnPantalla(concesionario,tama);
    std::cout<<"El vehiculo con mayor precio es: "<<concesionario->maxPrecio(concesionario,tama)<<std::endl;

    std::cout<<"Introduzca la matricula del vehiculo que quiere modificar: "<<std::endl;
    std::cin>>matricula;


    posicion=concesionario->buscarPorMatricula(matricula, concesionario, tama);
    if(posicion != -1){
        //Modificamos el dato que hay en esa posicion
        concesionario[posicion].leePorTeclado();
    }



    delete[] concesionario;




    return 0;
}
