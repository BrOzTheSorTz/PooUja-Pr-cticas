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

    int dia =0;
    int mes = 0;
    int anio =0;

public:
    Fecha (); //Constructor por defecto en donde hemos añadido código para que me incluya la fecha inicial
    Fecha ( int _dia, int _mes, int _anio);
    Fecha(const Fecha &orig);

    //GETTERS AND SETTERS
    int getDia() const;
    void setDia(int dia);

    int getMes() const;
    void setMes(int mes);

    int getAnio() const;
    void setAnio(int anio);

    ///Sobrecarga de operadores
    bool operator<(const Fecha &f2);
    bool operator==(const Fecha &f2);

    bool operator<=(const Fecha &f2);
    bool operator>=(const Fecha &f2);
    bool operator>(const Fecha &f2);
    bool operator!=(const Fecha &f2);

    ///Método CSV(Comma Separated Values)
    std::string toCSV() const ;

};


#endif //PRACTICA2CASA_FECHA_H
