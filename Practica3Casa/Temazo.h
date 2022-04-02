//
// Created by soria on 26/02/2022.
//

#ifndef PRACTICA2CASA_TEMAZO_H
#define PRACTICA2CASA_TEMAZO_H


#include <string>
#include "Fecha.h"

class Temazo {
private:
    std::string titulo = "";
    std::string interprete = "";
    int duracion = 0;
    int puntuacion = 0;
    std::string genero = "Pop";
    std::string nombreUltimoGarito = "";
    Fecha fechaUltimoUso; //Se inicializa por defecto a la fecha actual


public:
    //Constructor por defecto
    Temazo () = default;
    //Constructor parametrizado usando valores por defecto que me permiten no tener que usar todos los parametros cada vez que llamemos al constructor
    //OJO!: Los parámetros por defecto siempre van al final
    Temazo (std::string _titulo,std::string _interprete,int _duracion,std::string _nombreUltimoGarito,Fecha _fechaUltimoGarito,std::string _genero="Pop");
    //Constructor de copia
    Temazo(const Temazo &orig);
    //Destructor
    ~Temazo();

    //Getters y Setters
    ///TITULO

    std::string getTitulo() const;
    //Modificamos el setter para permitir llamarlo encadenados
    Temazo& setTitulo(const std::string &titulo);
    ///INTERPRETE

    std::string getInterprete() const;

    //Modificamos el setter para permitir llamarlo encadenados
    Temazo& setInterprete(const std::string &interprete);
    ///DURACION

    int getDuracion() const;
    //Modificamos el setter para permitir llamarlo encadenados
    Temazo& setDuracion(const int &duracion);
    ///PUNTUACION

    int getPuntuacion() const;

    ///GENERO
    //Como no puede modificarse el genero una vez construido, no vamos a utilizar un set si no que solamente vamos a utilizar un get
    std::string getGenero() const;

    ///Nombre Ultimo Garito
    Temazo& setNombreUltimoGarito (std::string nombre);
    std::string getNombreUltimoGarito() const;

    ///Fecha Ultimo Uso
    Temazo& setFechaUltimoUso (const Fecha &f);
    Fecha getFechaUltimoUso() const ;

};


#endif //PRACTICA2CASA_TEMAZO_H
