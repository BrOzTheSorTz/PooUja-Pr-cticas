//
// Created by soria on 30/04/2022.
//

#ifndef PRUEBA_EMPTYCONTAINER_H
#define PRUEBA_EMPTYCONTAINER_H
#include <stdexcept>

class EmptyContainer:public std::domain_error{

public:
    ///Lo necesario para crear este tipo de clases es:
    EmptyContainer(std::string error="Operacion no valida"):std::domain_error(error){};
    virtual ~EmptyContainer() noexcept =default;


};


#endif //PRUEBA_EMPTYCONTAINER_H
