//
// Created by soria on 17/02/2022.
//

#ifndef PRACTICA1CASA_VEHICULO_H
#define PRACTICA1CASA_VEHICULO_H
#include <string>


class Vehiculo {
private:
    std::string marca;
    std::string modelo;
    std::string matricula;
    int anioFabricacion;
    float precio;


public:

    //Getter and Setter//

    std::string getMarca() const;
    void setMarca(const std::string &marca);

    std::string getModelo() const;
    void setModelo(const std::string &modelo);

    std::string getMatricula() const;
    void setMatricula(const std::string &matricula);

    int getAnioFabricacion() const;
    void setAnioFabricacion(int anioFabricacion);

    float getPrecio() const;
    void setPrecio(float precio);


    //Constructores

    //Necesario el constructor por defecto ya que si queremos pasar un vector
    //de vehiculos, estos solo se pasan por defecto, aun así hay uno implementado por
    //defecto aunque si añades otro, este se pierde, por eso lo he dejado indicado

    Vehiculo()=default;

    //Métodos

    void leePorTeclado();
    void muestraEnPantalla ();

    void rellenarVector(Vehiculo vehiculos[],const int &tama);
    void mostrarVectorEnPantalla(const Vehiculo vehiculos[],const int &tama);

    int maxPrecio(const Vehiculo vehiculos[],const int &tama);
    int buscarPorMatricula(const std::string &matricula,const Vehiculo vehiculos[],const int &tama);

};




#endif //PRACTICA1CASA_VEHICULO_H
