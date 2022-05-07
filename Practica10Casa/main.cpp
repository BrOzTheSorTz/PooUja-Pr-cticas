/** 
 * @file   main.cpp
 * @author jrbalsas
 *
 * @date 15 de abril de 2016
 */

#include <cstdlib>
#include <iostream>

#include "Cofre.h"
#include "Item.h"
#include "ItemApilable.h"
#include "Bloque.h"
#include "Espada.h"
#include "Filete.h"
#include "EmptyContainer.h"
#include "Contenedor.h"
#include "ContenedorItem.h"
#include "Inventario.h"

using namespace std;


/*Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a nullptr
 * @return número de posiciones del vector con items creados
 * */
int inicializaItemsEnUnContendor(Contenedor<Item> &c, int tamv) {
    int numItems=0;

    //Para poder inicializar los objetos, ha sido necesario
    //crear los constructores por defecto y parametrizado necesarios

    c.mete( new Bloque("Bloque de tierra ",5));
    c.mete( new Bloque("Bloque de tierra ",8));
    c.mete( new Bloque("Bloque de tierra ",1));
    c.mete( new Espada("Espada de madera"));
    c.mete( new Filete("Muslo de pollo"));


    return numItems;
}

/**Libera los items de un contenedorItems creados en memoria dinámica*/
void liberaItemsEnUnContenedor(Contenedor<Item> &c, int numItems) {
    for (int i = 0; i < numItems; i++) {

        delete &c.consulta(i+1);

    }

}
/*
 Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a nullptr
 * @return número de posiciones del vector con items creados*/
int inicializaItems(Item* v[], int tamv) {
    int numItems=0;

    //Para poder inicializar los objetos, ha sido necesario
    //crear los constructores por defecto y parametrizado necesarios
    v[numItems++] = new Bloque("Bloque de tierra",5);
    v[numItems++] = new Bloque("Bloque de tierra",8);
    v[numItems++] = new Bloque("Bloque de tierra",1);
    v[numItems++] = new Espada("Espada de madera");
    v[numItems++] = new Filete("Muslo de pollo");

    //Asigna nullptr el resto de posiciones no ocupadas
    for (int i = numItems; i < tamv; i++) {
        v[i] = nullptr;
    }
    return numItems;
}
/**Libera los items del vector creados en memoria dinámica*/
void liberaItems(Item* v[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        delete v[i];
        v[i]=nullptr;
    }

}

///Modificamos la función para que acepte objetos de tipo ContenedorItem
///en general

void visualiza(Contenedor<Item> &c) {
    std::cout << "CONTENIDO " << std::endl
              << "===================" << std::endl;
    for (int i = 1; i <= c.cuantosHay(); i++) {
        std::cout << i <<".- "
                  << c.consulta(i).getDescripcion() << std::endl;
    }

}


int main(int argc, char** argv) {

    Item * v[5];
    inicializaItems(v,5);

    //Sustituimos el vector de punteros a Items por un objeto de la
    //nueva clase ContenedorItems

    //Una vez creada la plantilla hay que indicar el tipo de dato con el que hay vamos a trabajar
    Contenedor<Item> contenedor(10);
    /*
    for(int i=0;i<5;++i){
        contenedor.mete(v[i]);
    }*/
    inicializaItemsEnUnContendor(contenedor,10);


    //Creamos un cofre y lo añadimos al inventario
    Cofre c;
    for(int i=0;i<5;++i){
        c.mete(&contenedor.consulta(i+1));
    }
    //Visualizamos el cofre
    visualiza(c);

    Inventario i ;
    i.mete(&c);

    //Visualizamos el inventario
    visualiza(i);
    /**En el programa principal, recuperar el cofre del inventario del personaje usando el
    método consulta(cual). Comprobar que efectivamente es un cofre y, en su caso,
    mostrar el contenido por pantalla usando la función visualiza. Capturar adecuadamente
    las excepciones que pudieran originarse en su caso.
     * */
    try {


        Cofre *cofreRecuperado = dynamic_cast<Cofre *>(&i.consulta(1));
        if (cofreRecuperado != nullptr) {
            visualiza(*cofreRecuperado);
        }else{
            std::cout<<"Lo que ha introducido en el inventario no es un cofre"<<std::endl;
        }
    }catch (std::domain_error &e){
        std::cerr<<e.what()<<std::endl;

    }catch (EmptyContainer &e){
        std::cerr<<e.what()<<std::endl;

    }catch (std::exception &e){
        std::cerr<<e.what()<<std::endl;
    }

    //Liberamos los recursos
    liberaItems(v,5);
    liberaItemsEnUnContenedor(contenedor,5);

    return 0;
}

