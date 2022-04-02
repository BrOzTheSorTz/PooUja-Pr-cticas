//
// Created by soria on 26/02/2022.
//

#ifndef PRACTICA2CASA_GARITO_H
#define PRACTICA2CASA_GARITO_H


#include <string>

class Garito {
private:
    //No hace falta poner el private porque se asigna por defecto

    std::string nombre = "";
    std::string direccion = "";
public:
    Garito() = default;
    Garito (std::string _nombre,std::string _direccion);
    Garito ( const Garito &orig);
    ~Garito();

    //GETTERS AND SETTERS
    std::string getNombre() const;
    void setNombre(const std::string &nombre);

    std::string getDireccion() const;
    void setDireccion(const std::string &direccion);

    //Métodos
    std::string toCSV ()const;

};


#endif //PRACTICA2CASA_GARITO_H
