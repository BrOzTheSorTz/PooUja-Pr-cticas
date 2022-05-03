//
// Created by admin on 03/05/2022.
//

#ifndef PRUEBA_ITEMAGOTADO_H
#define PRUEBA_ITEMAGOTADO_H
#include <stdexcept>

class ItemAgotado:public std::out_of_range{
public:
    ItemAgotado(std::string error ="Hay un problema colega!"): std::out_of_range(error){};///<Parámetro por defecto, asi si no ponemos nada, sale un mensaje
    virtual ~ItemAgotado() noexcept=default;

};

#endif //PRUEBA_ITEMAGOTADO_H
