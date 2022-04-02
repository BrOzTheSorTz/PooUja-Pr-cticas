//
// Created by soria on 13/03/2022.
//

#ifndef PRUEBA_PARAMETRONOVALIDO_H
#define PRUEBA_PARAMETRONOVALIDO_H
#include <string>


class ParametroNoValido {
private:
    std::string fichero=""; ///<  Nombre del fichero donde se realiza el throw
    std::string funcion = "";///<Nombre del método en el que se realiza el throw
    std::string descripcion = ""; ///< Descripición de la excepcion

public:

    std::string queOcurre() const;

    const std::string &getFichero() const;
    const std::string &getFuncion() const;
    const std::string &getDescripcion() const;

    //No nos interesa un constructor por defecto, ya que siempre
    //que creemos uno debemos especificar dónde ocurre etc.
    ParametroNoValido (std::string _fichero,
                       std::string _funcion,
                       std::string _descripcion);
    ParametroNoValido(const ParametroNoValido &orig);

    virtual ~ParametroNoValido();
};


#endif //PRUEBA_PARAMETRONOVALIDO_H
