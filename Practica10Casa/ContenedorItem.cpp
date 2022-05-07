//
// Created by soria on 06/05/2022.
//

#include "ContenedorItem.h"

ContenedorItem::ContenedorItem(int cuantosCaben) :_maxItems(cuantosCaben),_numItems(0){

    _items=new Item*[cuantosCaben];

    for(int i=0;i<cuantosCaben;++i){
        _items[i]= nullptr;
    }


}

///Se crea un contenedor del mismo tamaño que el pasado
///No obstante no se copian los items que hayan
ContenedorItem::ContenedorItem(const ContenedorItem &orig):_maxItems(orig._maxItems),_numItems(orig._numItems) {

    _items=new Item*[orig._maxItems];
    for(int i=0;i<_maxItems;++i){
        _items[i]= nullptr;
    }

}

ContenedorItem::~ContenedorItem() {

    delete[] _items;

}

int ContenedorItem::cuantosCaben() {
    return _maxItems;
}

int ContenedorItem::cuantosHay() const {
    return _numItems;
}

void ContenedorItem::mete(Item *item) {
    if(item == nullptr){
        throw std::invalid_argument("[Codre::mete] No se puede añadir ningún objeto");
    }
    if (_numItems==_maxItems)
        throw std::out_of_range("[Cofre::mete] No caben más elementos en el cofre");
    _items[_numItems++]=item;

}

Item &ContenedorItem::consulta(int cual) {
    if (cual<=0 || cual >_numItems)
        throw EmptyContainer("[Cofre::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}

/**@param cual nº orden del elemento a extraer
* @return Extrae del cofre y devuelve el puntero al Item indicado
@throw EmptyContainer si el elemento no exist*/
Item* ContenedorItem::saca(int cual) {
    if (cual<=0 || cual >_numItems)
        throw EmptyContainer("[Cofre::mete] El elemento indicado no existe");
    Item* elemento = _items[cual-1];

    for(int i=cual;i<_numItems-1;++i){
        _items[i]=_items[i+1];
    }
    _items[_numItems-1]= nullptr;
    _numItems--;

    return elemento;
}
