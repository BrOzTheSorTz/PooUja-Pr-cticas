//
// Created by soria on 06/05/2022.
//

#ifndef PRUEBA_CONTENEDORITEM_H
#define PRUEBA_CONTENEDORITEM_H
#include "Item.h"
#include "stdexcept"
#include "EmptyContainer.h"
class ContenedorItem {
public:
    ///No nos interesa que haya un constructor por defecto
    //ContenedorItem();
    ContenedorItem(int cuantosCaben);
    ContenedorItem(const ContenedorItem& orig);
    virtual ~ContenedorItem();
    int cuantosCaben();
    int cuantosHay() const;
    virtual void mete(Item *item);
    Item& consulta(int cual);
    Item* saca(int cual);
private:
    int _maxItems = 0; ///< Tamaño del vector de punteros
    Item* *_items = nullptr; ///< Vector de punteros creado dinámicamente
    int _numItems = 0; ///< Primeras posiciones del vector ocupadas (máximo maxItems)
};




#endif //PRUEBA_CONTENEDORITEM_H
