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
    bool inhibido =false; ///<Por defecto un poder siempre se puede usar
    float capacidadDestructiva=0;


public:
    ///OJO. Una vez que añadamos un atributo nuevo
    ///Hay que modificar constructor de copia, operador asignación y los métodos adecuados para gestionarlo
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

    bool isInhibido() const;
    void cambiarInhibido();

    std::string toCSV();



};


#endif //PRUEBA_PODER_H
