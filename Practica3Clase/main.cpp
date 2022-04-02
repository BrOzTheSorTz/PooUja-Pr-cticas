#include <iostream>
#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"
#include "djutils.h"

int main() {

    int MAX_TEMAZOS = 20;
    int MAX_GARITOS = 10;
    int nuevoTama=0;

    Fecha miCumple(22,11,2003);
    Fecha ultimaChampionsMadrid(26,5,2018);
    Fecha ultimaChampionsBarcelona(6,6,2015);
    Temazo* lista[MAX_TEMAZOS];
    //Creamos un temazo en memoria dinamica
    Temazo *t1=new Temazo("Paquito chocolate Segi's remastered edition plus","Segismundo",350,"Su casa",miCumple);


    //Creamos un vector de temazos
    Temazo canciones[MAX_TEMAZOS]; //Vector que almacena 20 temazos, aunque realmente hay 3
    int tama=3;

    canciones[0].setTitulo("Malamente").setInterprete("Rosalia").setDuracion(190).setFechaUltimoUso(miCumple).setNombreUltimoGarito("NOSEEEEE");
    canciones[1].setTitulo("Ultima noche").setInterprete("Rafael").setDuracion(180).setFechaUltimoUso(ultimaChampionsMadrid).setNombreUltimoGarito("LUGARRRRR");
    canciones[2].setTitulo("Castle on the hill").setInterprete("Ed Sheeran").setDuracion(420).setFechaUltimoUso(ultimaChampionsBarcelona).setNombreUltimoGarito("ujaaaa");

    //Visualizamos aquellos temazos del vector con una duración superior a la del temazo t1
    verTemazosMasLargosQue(canciones,tama,*t1);

    if(canciones[0]>canciones[1]){
        std::cout<<"La cancion mayor es: ";
        mostrarTemazo(canciones[0]);
    }
    //Obtener una lista de temazos cuya duracion sea menor que la indicada en conjunto
    nuevoTama= listaRelleno(canciones,tama,lista,tama,600);
    std::cout<<"Mostramos las canciones que en su conjunto en duración emplean menos que lo indicado:"<<std::endl;
    std::cout<<"======================================================================================="<<std::endl;
    //Mostramos los datos
    for(int i=0;i<nuevoTama;++i){
        mostrarTemazo(*lista[i]);
    }











    return 0;
}
