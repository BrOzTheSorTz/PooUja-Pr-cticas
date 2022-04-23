/**
 * @file PoderPsiquico.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef PODERPSIQUICO_H
#define PODERPSIQUICO_H

#include "Poder.h"

/**
 * @brief
 */
class PoderPsiquico : public Poder
{
   public:
      PoderPsiquico ( ) = default;
      PoderPsiquico ( std::string nmb, std::string dsc, std::string aA, float cD );
      PoderPsiquico ( const PoderPsiquico& orig );
      virtual ~PoderPsiquico ( );

      /*FIXME Preguntar al profesor si se puede hacer una referencia
            a la clase padre, en lugar de al propio objeto
       */
      Poder& operator= ( const PoderPsiquico& orig );

    float getLucidez() const;
    Poder& setLucidez(float lucidez);


    //No haría falta poner el virtual ya que una vez que se lo pones
    //a la clase padre ,este se le asigna a todos los métodos redefinidos
    //de las clases hijas
    virtual float getCapacidadDestructiva() const override;
    /*No haría falta redefinir un método de setCapacidadDestructiva()
     * ya que la capacidad Destructiva del poder psiquico se modifica internamente
     * al llamar al método getCapacidadDestructiva()*/
    std::string toCSV() const override;


   private:
      float lucidez =0; ///< El valor está entre 0 y 1
};

#endif /* PODERPSIQUICO_H */

