//
// Created by soria on 26/02/2022.
//

#ifndef PRACTICA2CASA_FECHA_H
#define PRACTICA2CASA_FECHA_H

//Obtener la fecha actual
#include <iostream>
#include <ctime>



class Fecha {
private:
    std::time_t t= std::time(0); // obtiene el tiempo ahora
    std::tm* now = std::localtime(&t);

    int dia =now->tm_mday;
    int mes = (now->tm_mon+1);
    int anio = (now->tm_mday+1996);

public:
    Fecha ()=default;
    Fecha ( int _dia, int _mes, int _anio);
    Fecha(const Fecha &orig);

    //GETTERS AND SETTERS
    int getDia() const;
    void setDia(int dia);

    int getMes() const;
    void setMes(int mes);

    int getAnio() const;
    void setAnio(int anio);

};


#endif //PRACTICA2CASA_FECHA_H
