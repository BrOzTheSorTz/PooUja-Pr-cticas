//
// Created by soria on 10/04/2022.
//

#ifndef PRUEBA_PODER_H
#define PRUEBA_PODER_H


#include <string>

class Poder {

private:
    std::string nombre ="";
    std::string descripcion = "";
    std::string afectaA= "";
    float capacidadDestructiva=0;


public:
    Poder();
    Poder(const std::string &nombre, const std::string &descripcion);

    Poder(const std::string &nombre, const std::string &descripcion, float capacidadDestructiva);

    Poder(std::string _nombre,std::string _descripcion,std::string _afectaA, float _capacidadDestructiva);
    Poder(const Poder &orig);
    virtual ~Poder();

    Poder& operator=(const Poder &otro);
    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);
    const std::string &getDescripcion() const;
    void setDescripcion(const std::string &descripcion);
    const std::string &getAfectaA() const;
    void setAfectaA(const std::string &afectaA);
    float getCapacidadDestructiva() const;
    void setCapacidadDestructiva(float capacidadDestructiva);

    std::string toCSV();



};


#endif //PRUEBA_PODER_H
