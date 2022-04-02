#include <iostream>
#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"
#include "djutils.h"
#include "ParametroNoValido.h"

int main() {

    Fecha f={22,11,2003};
    Temazo t1={"Malamamente", "Rosalia",240,"La nuit",f};
    Temazo t2 ("Ultima noche","Rafael",320,"DJ's House"); ///<Como no se le ha asignado una fecha, se le asigna la del ultimo temazo
    //Comprobamos si esta correcto
    std::cout<<t2.getFechaUltimoUso().toString()<<std::endl;


    //Comprobación de la modificación de ParametroNoValido.h
    try{
        Garito g1("","Avenida Madrid");
    }catch (ParametroNoValido &e){
        std::cerr<<e.queOcurre()<<std::endl;
    }


    //Voy a crear un Temazo que su titulo no sea válida y me muestre en este caso su longitud
    try{
        Temazo t3={"","Cancion popular",420,"40 Festival"};
    }catch(ParametroNoValido &e){
        std::cerr<<e.queOcurre()<<std::endl;
    }













    return 0;
}
