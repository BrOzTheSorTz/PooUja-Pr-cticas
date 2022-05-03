//
// Created by admin on 03/05/2022.
//

#ifndef PRUEBA_ITEMAPILABLEARROJABLE_H
#define PRUEBA_ITEMAPILABLEARROJABLE_H
#include "ItemApilable.h"

class ItemApilableArrojable:public ItemApilable{
private:
    float damage=0;
public:
    virtual std::string lanzar()=0;
    virtual std::string getDescripcion()=0;

    float getDamage() const;
    void setDamage(float damage);

};



#endif //PRUEBA_ITEMAPILABLEARROJABLE_H
