//
// Created by soria on 07/05/2022.
//

#ifndef PRUEBA_CONTENEDOR_H
#define PRUEBA_CONTENEDOR_H


#include <stdexcept>
#include "EmptyContainer.h"

///Creamos la clase ContenedorItem en una plantilla de clase para que no solo
///podamos almacenar items si no más cosas, como personajes, etc.

///Lo que cambiaría ahora sería que las clases que heredaban de ContenedorItem
///deben heredar de este, además de los métodos cuyo nombre era de ContenedorItem, ahora
/// debería ser de Contenedor<Item>

template <typename T>
class Contenedor{
private:
    int _maxItems =0;
    T* *_items= nullptr; ///<Vector de punteros creados en memoria dinámica
    int _numItems =0;

public:
    Contenedor(int cuantosCaben);
    Contenedor(const Contenedor &orig);
    ~Contenedor();

    int cuantosCaben();
    int cuantosHay();
    virtual void mete(T* item);
    T& consulta(int cual);
    T* saca(int cual);

};

template <typename T>
Contenedor<T>::Contenedor(int cuantosCaben):_maxItems(cuantosCaben),_numItems(0){

    _items=new T*[cuantosCaben];

    for(int i=0;i<cuantosCaben;++i){
        _items[i]= nullptr;
    }
}
///Se crea un contenedor del mismo tamaño que el pasado
///No obstante no se copian los items que hayan
template <typename T>
Contenedor<T>::Contenedor(const Contenedor<T> &orig) :_maxItems(orig._maxItems),_numItems(orig._numItems){
    _items = new T*[_maxItems];
    for(int i=0;i<_maxItems;++i){
        _items[i]= nullptr;
    }
}

template<typename T>
Contenedor<T>::~Contenedor(){
    //FIXME No sería recorrer todos los items y asignarlos a nullptr ya que estamos en una agregacion
    delete _items;
}

template<typename T>
int Contenedor<T>::cuantosCaben() {
    return _maxItems;
}

template<typename T>
int Contenedor<T>::cuantosHay() {
    return _numItems;
}

template<typename T>
void Contenedor<T>::mete(T *item) {
    if(item == nullptr){
        throw std::invalid_argument("[Contenedor<T>::mete] No se puede añadir ningún objeto");
    }
    if (_numItems==_maxItems)
        throw std::out_of_range("[Contenedor<T>::mete] No caben más elementos en el contenedor");

    _items[_numItems++]=item;

}

template<typename T>
T &Contenedor<T>::consulta(int cual) {
    if (cual<=0 || cual >_numItems)
        throw EmptyContainer("[Contenedor<T>::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}

template<typename T>
T *Contenedor<T>::saca(int cual) {
    if(cual<1 || cual >_maxItems){
        throw EmptyContainer("[Contenedor<T>::mete] El elemento indicado no existe");
    }

    //Sustituyo en el hueco libre el úlimo elemento (LO FACIL)
    _items[cual-1]=_items[_numItems-1];
    --_numItems;

    return _items[cual-1];
}

#endif //PRUEBA_CONTENEDOR_H
