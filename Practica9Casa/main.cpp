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

using namespace std;
/*
/**Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a nullptr
 * @return número de posiciones del vector con items creados
int inicializaItems(Item* v[], int tamv) {
    int numItems=0;

    //Para poder inicializar los objetos, ha sido necesario
    //crear los constructores por defecto y parametrizado necesarios
    v[numItems++] = new Bloque("Bloque de tierra (5)");
    v[numItems++] = new Bloque("Bloque de tierra (8)");
    v[numItems++] = new Bloque("Bloque de tierra (1)");
    v[numItems++] = new Espada("Espada de madera");
    v[numItems++] = new Filete("Muslo de pollo");

    //Asigna nullptr el resto de posiciones no ocupadas
    for (int i = numItems; i < tamv; i++) {
        v[i] = nullptr;
    }        
    return numItems;
}*/
/**Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a nullptr
 * @return número de posiciones del vector con items creados*/
int inicializaItems(Item* v[], int tamv) {
    int numItems=0;

    //Para poder inicializar los objetos, ha sido necesario
    //crear los constructores por defecto y parametrizado necesarios
    v[numItems++] = new Bloque("Bloque de tierra");
    v[numItems++] = new Bloque("Bloque de tierra");
    v[numItems++] = new Bloque("Bloque de tierra");
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

void visualiza(Cofre &c) {
    std::cout << "CONTENIDO DEL COFRE" << std::endl
              << "===================" << std::endl;
    for (int i = 1; i <= c.cuantosHay(); i++) {
        std::cout << i <<".- "
                  << c.consulta(i).getDescripcion() << std::endl;
    }

}


/**@brief Probando los Cofres
 * 
 */
int main(int argc, char** argv) {

    try {
        const int MAXITEMS = 10;
        Item *objetos[MAXITEMS];

        //Inicializamos algunos objetos de prueba
        int numObjetos = inicializaItems(objetos, MAXITEMS);

        Cofre c; //Creamos un cofre con 27 posiciones

        ItemApilable *i1 = new Bloque("Bloque de tierra");
        i1->incrementaNumElementos(4);
        ItemApilable *i2 = new Bloque("Bloque de tierra");
        i2->incrementaNumElementos(7);
        ItemApilable *i3 = new Bloque("Bloque de tierra");

        c.mete(i1);
        c.mete(i2);
        c.mete(i3);

        visualiza(c);
        /*
         * ERRORES :
         i2->incrementaNumElementos(300);
         c.saca(5);
         */

        //Liberamos recursos
        liberaItems(objetos, numObjetos);
        delete i1;
        i1 = nullptr;
        delete i2;
        i2 = nullptr;
        delete i3;
        i3 = nullptr;


    }///Ojo! Hay que ponerlo de la más específica, a la más general
    catch (std::out_of_range &e){
        std::cerr<<e.what()<<std::endl;
    }catch (EmptyContainer &e){
        std::cerr<<e.what()<<std::endl;
    }catch (std::exception &e){
        std::cerr<<"Ha habido un error inesperado !"<<std::endl;
        std::cerr<<e.what()<<std::endl;
    }
    return 0;
}

