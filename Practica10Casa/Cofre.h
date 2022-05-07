/** 
 * @file    Cofre.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Item.h"
#include <string>

#ifndef COFRE_H
#define COFRE_H
#include "Item.h"
#include "Contenedor.h"
#include <sstream>

//Los cofres implementan la interfaz de item
//poque pueden formar parte del inventario
class Cofre :public Contenedor<Item>,public Item{

public:
    Cofre(int cuantosCaben=27);
    virtual std::string getDescripcion() override;
    virtual void mete(Item *item) override;
    virtual ~Cofre();


};
#endif /* COFRE_H */

