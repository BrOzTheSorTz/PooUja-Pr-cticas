#include <iostream>
#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"
#include "djutils.h"
#include "ParametroNoValido.h"

int main() {

    Fecha actual;
    int MAX_GARITO=10;
    //No estoy trabajando en memoria dinámica por eso no es necesario usar ni new , ni delete
    Garito* pGaritos[MAX_GARITO];
    for(int i=0;i<MAX_GARITO;++i){
        pGaritos[i]= nullptr;
    }


    try{

        Garito g1;
        g1.setNombre("La nuit");
        g1.setDireccion("Avenida Madrid");
        pGaritos[0]=&g1;

        Garito g2;
        g2.setDireccion("DJ's house");
        g2.setNombre("ElTriqui");
        pGaritos[1]=&g2;

        int MAX_TEMAZOS=5;
        Temazo temazos[MAX_TEMAZOS];
        try {
            temazos[0].setTitulo("Malamamente").setInterprete("Rosalia").setDuracion(240).setPuntuacion(0).setNombreUltimoGarito("La nuit").setFechaUltimoUso(actual);
            temazos[1].setTitulo("Como el agua").setInterprete("Camaron").setDuracion(140).setPuntuacion(0).setNombreUltimoGarito(g1.getNombre()).setFechaUltimoUso(actual);
            temazos[2].setTitulo("Ultima Noche").setInterprete("Rafael").setDuracion(340).setPuntuacion(0).setNombreUltimoGarito("Kharma").setFechaUltimoUso(actual);



            //Bucles que recorran los vectores anteriores mostrando la información en formato Comma Separated Values(CSV)

            //Garitos
            for(int i=0;i<MAX_GARITO;++i){
                if(pGaritos[i]!= nullptr){
                    std::cout<<pGaritos[i]->toCSV()<<std::endl;
                }
            }
            //Temazos
            std::cout<<std::endl;
            for(int i=0;i<3;++i){
                std::cout<<temazos[i].toCSV()<<std::endl;
            }

        }catch (ParametroNoValido &e){
            std::cerr<<e.queOcurre()<<std::endl;
        }

    }catch (ParametroNoValido &e){
        std::cerr<<e.queOcurre()<<std::endl;
    }













    return 0;
}
