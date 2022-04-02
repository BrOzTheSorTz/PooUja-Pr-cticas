/** 
 * @file StarFighter.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef STARFIGHTER_H
#define STARFIGHTER_H

#include <string>
#include "Pieza.h"

/**
 * @brief
 */
class StarFighter
{
public:
    static const int TAM_MAX = 50;

private:
      static int _numStarFighters; ///< Número de objetos de esta clase instanciados
      int _idSF=0; ///< Identificador único de la nave
      std::string _marca; ///< Marca de la nave (parece que las VW contaminan más)
      std::string _modelo; ///< Modelo de la nava
      int _numPlazas = 0; ///< Número de plazas de la nave
      Pieza *partes[TAM_MAX];
      int numPiezas=0;

public:
      StarFighter ();
      StarFighter ( std::string marca, std::string modelo );
      StarFighter ( const StarFighter& orig );
      virtual ~StarFighter ( );
      void addPieza(Pieza &p);
      StarFighter& addPieza(std::string _nombre,float _peso,std::string _descripcion);
      StarFighter& addPieza(Pieza *p);
      Pieza& obtenerPieza(int cual);
      void quitarPieza(int cual);
      float calculaPeso();
      StarFighter& setNumPlazas ( int numPlazas );
      int getNumPlazas ( ) const;
      StarFighter& setModelo ( std::string modelo );
      std::string getModelo ( ) const;
      StarFighter& setMarca ( std::string marca );
      std::string getMarca ( ) const;
      int getIdSF ( ) const;
      std::string toCSV () const;
      StarFighter& operator= ( const StarFighter& otro );
      void fromCSV ( std::string& datos );

      int getNumPiezas() const;
};

#endif /* STARFIGHTER_H */

