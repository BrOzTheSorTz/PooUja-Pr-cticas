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
#include "BolaDeNieve.h"
#include "ItemApilableArrojable.h"
#include "ItemAgotado.h"

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


    const int MAXITEMS = 10;
    Item *objetos[MAXITEMS];

    //Inicializamos algunos objetos de prueba
    int numObjetos = inicializaItems(objetos, MAXITEMS);

    Cofre c; //Creamos un cofre con 27 posiciones

    //Creamos una bola de nieve
    ItemApilableArrojable *pB=new BolaDeNieve("Bola de nieve del Himalaya pero en puntero");
    pB->setDamage(1);
    pB->incrementaNumElementos(9);
    BolaDeNieve b={"Bola de nieve del Himalaya"};
    b.setDamage(1);
    b.incrementaNumElementos(9);

    //Metemos las bolas de nieve en el cofre
    c.mete(pB);
    c.mete(&b);

    //Ahora las lanzaremos
    try{

        for(int i=0;i<12;++i){
            std::cout<<"Lanzamiento "<<i+1<<"- "<<pB->lanzar()<<std::endl;
            std::cout<<"Bolas restantes: "<<pB->getNumElementos()<<std::endl;
        }

        delete pB;pB= nullptr;
    }catch (ItemAgotado &e){
        std::cerr<<e.what()<<std::endl;

    }catch (std::out_of_range &e){
        //Para capturar posibles excepciones de item apilable
        std::cerr<<e.what()<<std::endl;
    }catch (std::exception &e){
        //Utilizamos esto para que coga cualquier otra excepcion que se pueda producir
        std::cerr<<e.what()<<std::endl;
    }
    return 0;
}

