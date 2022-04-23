/**
 * @file main.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <iostream>
#include <fstream>

#include "EquipoMutante.h"
#include "ordena.h"

using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza ( Mutante& m)
{
   std::cout << "MUTANTE: " 
             << m.toCSV() << std::endl;
   std::cout << "  Poderes : " << std::endl;
   for (int i = 0; i < m.getNumPoderes(); i++)
   {
      std::cout << "    - " << m.getPoder(i).toCSV()<<std::endl;
   }
}

/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza ( EquipoMutante& eq )
{
   std::cout << "EQUIPO: " << eq.getNombre() 
             << " (Base: " << eq.getBase()<< ")" <<std::endl
             << "============================"
             << std::endl;
   for ( int i = 0; i < eq.getNumMiembros(); i++ )
   {
      visualiza ( *(eq.getMutante(i)) );
   }
}

/***@brief Visualiza un vector de mutantes en formato CSV*/
void visualiza ( Mutante* v[], int tamv)
{
    for(int i=0;i<tamv;++i){
        std::cout<<"Mutante "<<i+1<<" : "<<v[i]->toCSV()<<std::endl;
    }
}


/**@brief Almacena los mutantes de un vector en una archivo CSV 
   @param Mutante* v[], vector de punteros a objetos mutantes
   @param unsigned int tamv, número de mutantes almacenados en el vector
   @param string nomArchivo, archivo donde se almacenarán los mutantes. Si ya sobreescribirá.
   @post  Almacena los datos simples (sin poderes) de cada mutante en formato CSV en una línea diferente del Archivo indicado
 */
void almacenaMutantesCSV ( Mutante* v[], unsigned int tamv,
                           std::string nomArchivo)
{
   std::ofstream archivo;
   archivo.open ( nomArchivo.c_str() ); //c_str() no es necesario si compilador soporta >= C++11

   if ( archivo.good ( ) )
   {
      for ( unsigned int i = 0; i < tamv; i++ )
      {
         archivo << v[i]->toCSV() << std::endl;
      }
      
      archivo.close ( );
   }
}


/**@brief Recupera los mutantes de un fichero CSV en un vector
   @param Mutante* v[], vector de punteros a objetos mutantes
   @param int tamv, número máximo de mutantes que se pueden almacenar en v
   @param string nomArchivo, archivo de donde se recuperarán los mutantes en formato CSV
   @post  Las posiciones del vector se sobreescribirán
   @post  Recupera mutantes del fichero y los crea en memoria dinámica, asociando cada uno a una posición del vector
   @return número de mutantes leídos y creados (como máximo será tamv)
 */
int recuperaMutantesCSV ( Mutante* v[], int tamv, std::string nomArchivo)
{
    //Como estamos leyendo desde un archivo hay que utilizar ifstream
    //Si tu viesemos que escribir en él , habría que utilizar ofstream
    ifstream aux;
    int cont=0; ///<Iremos contando el número de mutantes que se añaden
    std::string cadena=""; ///<En esta variable almacenamos las líneas en CSV del archivo

    aux.open(nomArchivo.c_str());
    //Si se abre el archivo correctamente, continuamos
    if(aux.good()){
        /*Solo se leeran mutantes del archivo hasta:
         *      -Se alcance el tamaño máximo indicado
         *      -Hasta que se acabe el archivo
         * */
        while(!aux.eof() && cont < tamv ){
            getline(aux,cadena); //Toma una línea del archivo

            //Comprobamos que la línea no esté vacía
            if(cadena!=""){

                v[cont++]->fromCSV(cadena); //Pasamos los datos del atributo al mutante en la posición indicada por cont
                //++cont;
                //std::cout<<"hola"<<std::endl;
                cadena="";//Inicializamos de nuevo la línea



            }

        }
        //Cerramos el archivo
        aux.close();


    }else{
        std::cerr<<"No se ha podido abrir el archivo"<<std::endl;
    }
    return cont;//Número de mutantes leidos
}

/**@brief inicializa vector de mutantes y crea algunos
   @pre v debe tener al menos tamv posiciones
   @post se inicializan todas las posiciones de v a 0 o a un nuevo mutante 
   @return número de muntantes creados en el vector*/
int inicializaMutantes ( Mutante* v[], int tamv )
{
   for ( int i = 0; i < tamv; i++ )
   {
      v[i]=0;
   }

   int creados = 0;
   v[creados++] = new Mutante("Logan", "Lobezno", 19320101, "Estadounidense");
   v[creados++] = new Mutante("Marie", "Rogue", 19700101, "Estadounidense");
   v[creados++] = new Mutante("Ororo", "Tormenta", 19500101, "Keniata");
   v[creados++] = new Mutante("Scott", "Cíclope", 19300101, "Estadounidense");
   v[creados++] = new Mutante("Charles", "Profesor X", 19200101, "Estadounidense");

   return creados;
}


int main ( int argc, char** argv )
{
   const int MAXMUTANTES = 5;
   Mutante* mutantes[MAXMUTANTES];
   int numMutantes = 0;
   std::string archivoMutantes="mutantes.csv";

   numMutantes = inicializaMutantes ( mutantes, MAXMUTANTES );

   ///recuperar mutantes del archivo
   int nuevoTama =0;
   int tamArch=5;
   Mutante* mutantesArchivo[tamArch];
   //Inicializamos el vector de mutantes con mutantes por defecto
   for(int i=0;i<tamArch;++i){
       mutantesArchivo[i]=new Mutante();
   }


   nuevoTama=recuperaMutantesCSV(mutantesArchivo,tamArch,archivoMutantes);

   /// Visualizar vector de mutantes en formato CSV
   if(nuevoTama>0){

       visualiza(mutantesArchivo,nuevoTama);
   }

   //Creación de los equipos y configuración de poderes
   EquipoMutante equipo1 ( "Patrulla X", "Mansión" );
   equipo1.addMutante ( mutantes[1] );
   equipo1.addMutante ( mutantes[3] );

   EquipoMutante equipo2 ( "Los malos", "Casa Magneto" );
   equipo2.addMutante ( mutantes[0] );
   equipo2.addMutante ( mutantes[2] );
   equipo2.addMutante ( mutantes[4] );

   //Diferentes formas de añadir poderes: usando datos o objetos de tipo Poder
   mutantes[0]->addPoder ( "longevidad", "vivir mucho", "su cuerpo", 0 );
   mutantes[1]->addPoder ( Poder( "absorción", "absorve poderes de otros mutantes",
                                  "cualquier mutante", 100 ) );
   mutantes[2]->addPoderFisico ( "clima", "puede manejar el clima", "atmósfera",
                                 150 );
   mutantes[3]->addPoder( PoderFisico ( "rayo", "expulsa láser por los ojos",
                                        "lo que pille por delante", 500 ) );
   mutantes[4]->addPoder ( PoderPsiquico ( "AtacaMente",
                                           "ataca la mente de su enemigo",
                                           "cualquiera", 150 ) );
/*
   visualiza ( equipo1 );
   visualiza ( equipo2 );
*/

    ///Creamos un vector de punteros a poderes
    PoderFisico p1( "rayo", "expulsa láser por los ojos",
                           "lo que pille por delante", 100 ),p2( "clima", "puede manejar el clima", "atmósfera",
                                                                 150 );
    PoderPsiquico p3( "AtacaMente",
                      "ataca la mente de su enemigo",
                      "cualquiera", 150 );
    p3.setLucidez(0.8);
    Poder p4( "longevidad", "vivir mucho", "su cuerpo", 800 );

    Poder * poderes[]={&p1,&p2,&p3,&p4};
    //Mostramos el listado de poderes generado

    for(int i=0;i<4;++i){
        std::cout<<"Poder "<<i+1<<" ; "<<poderes[i]->toCSV()<<std::endl;
    }
    std::cout<<endl<<endl;
    //A continuación ordenamos el vector según su capacidad destructiva
    //Para ello utilizamos la plantilla de función


    ordena(poderes,4);
    //Y lo mostramos de nuevo
    for(int i=0;i<4;++i){
        std::cout<<"Poder "<<i+1<<" ; "<<poderes[i]->toCSV()<<std::endl;
    }
    std::cout<<endl<<endl;


   /// Crear poder físico asfixia y añadir a un mutante
   PoderPsiquico asfixia;
   asfixia.setCapacidadDestructiva(600);
   asfixia.setLucidez(0.75);
   asfixia.setAfectaA("Oponentes biologicos");

   std::cout<<"Mostramos la capacidad destructiva del Profesor X ANTES de añadirle el poder de axfisia: "<<mutantesArchivo[4]->capacidadDestructivaTotal()<<std::endl;

   mutantesArchivo[4]->addPoder(asfixia);
   std::cout<<"Mostramos la capacidad destructiva del mutante 1 DESPUES de añadirle el poder de axfisia: "<<mutantesArchivo[4]->capacidadDestructivaTotal()<<std::endl;



    /// Ordenar y visualizar vector de mutantes con plantilla de método Ordena
    ordena(mutantesArchivo,nuevoTama);
    //Y lo visualizamos
    visualiza(mutantesArchivo,nuevoTama);

   //Comprobar que DoctorX a mejorado su posición por que ha aumentado su capacidad
   //Destructiva

   almacenaMutantesCSV ( mutantes, 5, archivoMutantes );


   for ( int i = 0; i < MAXMUTANTES; i++ )
   {
      delete mutantes[i];
      mutantes[i] = nullptr;
   }

   for(int i=0;i<tamArch;++i){
       delete mutantesArchivo[i];
       mutantesArchivo[i]= nullptr;
   }

   return 0;
}