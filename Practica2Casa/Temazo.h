//
// Created by soria on 26/02/2022.
//

#ifndef PRACTICA2CASA_TEMAZO_H
#define PRACTICA2CASA_TEMAZO_H


#include <string>

class Temazo {
private:
    std::string titulo = "";
    std::string interprete = "";
    int duracion = 0;
    int puntuacion = 0;
    std::string nombreUltimoGarito = "";


public:
    //Constructor por defecto
    Temazo () = default;
    //Constructor parametrizado
    Temazo (std::string _titulo,std::string _interprete,int _duracion);
    //Constructor de copia
    Temazo(const Temazo &orig);
    //Destructor
    ~Temazo();

    //Getters y Setters
    ///TITULO
    std::string getTitulo() const;
    void setTitulo(const std::string &titulo);
    ///INTERPRETE
    std::string getInterprete() const;
    void setInterprete(const std::string &interprete);
    ///DURACION
    int getDuracion() const;
    void setDuracion(int duracion);
    ///PUNTUACION
    int getPuntuacion() const;

};


#endif //PRACTICA2CASA_TEMAZO_H
