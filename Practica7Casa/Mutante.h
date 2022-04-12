/**
 * @file Mutante.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef MUTANTE_H
#define MUTANTE_H

#include <string>
#include "Poder.h"
#include "PoderFisico.h"
#include "PoderPsiquico.h"

using std::string;

/**
 * @brief Clase Muntante
 */
class Mutante {
public:
    static const int MAX_PODERES = 10; ///< Max. poderes de un mutante

public:
    Mutante();
    Mutante(string nombre, string apodo, int fechaN,string nacionalidad);
    Mutante(const Mutante& orig);
    virtual ~Mutante();
    Mutante& setNombreReal(string nombreReal);
    string getNombreReal() const;
    Mutante& setNacionalidad(string nacionalidad);
    string getNacionalidad() const;
    Mutante& setFechaDeNacimiento(int fechaDeNacimiento);
    int getFechaDeNacimiento() const;
    Mutante& setApodo(string apodo);
    string getApodo() const;

    string toCSV() const;

    Mutante& operator=(const Mutante& orig);

    Mutante& addPoder(std::string nombre,std::string descripcion,std::string afectaA,float capacidadD);
    Mutante& borrarPoder(int cual);
    float capacidadDestructiva();
    Mutante& addPoderFisico(std::string nombre,std::string descripcion,std::string afectaA,float capacidadD);
    Mutante& addPoderPsiquico(std::string nombre,std::string descripcion,std::string afectaA,float capacidadD);

    int getNumPoderes() const;

    //Sobrecargamos los métodos de añadir poderes (utilizando el constructor de copia)
    //cuyo fin es que a la hora de que si cambiamos alguna cosa del poder ,los constructores
    //de copia se encarguen de cambiarlos en el objeto
    Mutante& addPoder(const Poder &p);
    Mutante& addPoderFisico(const PoderFisico &p);
    Mutante& addPoderPsiquico(const PoderPsiquico &p);

    Poder* obtenerPoder(int cual);

private:
    string _nombreReal = "---";
    string _apodo = "---";
    int _fechaDeNacimiento = 0;
    string _nacionalidad = "---";
    Poder* poderes[MAX_PODERES];
    int numPoderes=0;


};

#endif /* MUTANTE_H */

