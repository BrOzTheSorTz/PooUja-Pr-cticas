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
#include "MutanteAstral.h"
#include "utilidades.h"

using namespace std;
bool almacenarPoderesEnCSV(Poder* v[],int tamv,std::string nombreArchivo){
    std::ofstream aux;
    aux.open(nombreArchivo);
    bool todoBien=false;

    if(aux.good()){
        for(int i=0;i<tamv;++i){
            aux <<v[i]->toCSV()<<std::endl;
        }

        aux.close();
        todoBien=true;

    }

    return todoBien;
}
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
      v[i]= nullptr;
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
    int tam;
    Mutante *mutantes[5];
    tam = inicializaMutantes(mutantes,5);
    MutanteAstral m1;
    m1.setApodo("banshee");
    PoderPsiquico poderAstral;poderAstral.setNombre("grito mortal");poderAstral.setCapacidadDestructiva(200);

    mutantes[0]->addPoder ( "longevidad", "vivir mucho", "su cuerpo", 0 );
    mutantes[1]->addPoder ( Poder( "absorción", "absorbe poderes de otros mutantes",
                                   "cualquier mutante", 100 ) );
    mutantes[2]->addPoderFisico ( "clima", "puede manejar el clima", "atmósfera",
                                  150 );
    mutantes[3]->addPoder( PoderFisico ( "rayo", "expulsa láser por los ojos",
                                         "lo que pille por delante", 500 ) );
    mutantes[4]->addPoder ( PoderPsiquico ( "AtacaMente",
                                            "ataca la mente de su enemigo",
                                            "cualquiera", 150 ) );



    m1.addPoder(poderAstral);
    MutanteAstral m2;

    std::cout<<"1º Obtenemos capacidad destructiva: "<<m1.capacidadDestructivaTotal()<<std::endl;
    try{
        std::cout<<m1.capacidadDestructivaTotal()<<std::endl;


    }catch (std::out_of_range &e){
        std::cerr<<e.what()<<std::endl;
    }


    try{
        //Asignamos un poder fisico
        PoderFisico pPrueba;
        m1.addPoder(pPrueba);
    }catch (std::invalid_argument &e){
        std::cerr<<e.what()<<std::endl;

    }
    Mutante mutantePrueba={"Magneto","---",22112003,"catalan"};
    mutantePrueba.addPoder(poderAstral);
    int numSuperiores=-1;
    numSuperiores= numElementosSuperiores(mutantes,5,mutantePrueba);

    std::cout<<"Mutantes superiores a "<<mutantePrueba.getNombreReal()<<" es: "<<numSuperiores<<std::endl;

    //Creamos un archivo de poderes
    Poder p1( "absorción", "absorve poderes de otros mutantes",
              "cualquier mutante", 100 );
    PoderFisico p2( "rayo", "expulsa láser por los ojos",
                    "lo que pille por delante", 500  );

    Poder* v[]={&p1,&p2};
    if(almacenarPoderesEnCSV(v,2,"poderes.csv")){
        //Ahora creamos un nuevo vector , para pasar los poderes
        //de .csv a objetos
        const int MAX=10;
        Poder* vPrueba[MAX];
        for(int i=0;i<MAX;++i){
            vPrueba[i]=new Poder;
        }
        int tam=2;
        RecuperaCSV(vPrueba,tam,"poderes.csv");

        //Mostramos los datos recuperados desde un archivo
        //usando una plantilla de función

        for(int i=0;i<tam;++i){
            std::cout<<i+1<<".-"<<vPrueba[i]->toCSV()<<std::endl;
        }

        for(int i=0;i<MAX;++i){
            delete vPrueba[i];
            vPrueba[i]= nullptr;
        }
    }else{
        std::cerr<<"No se ha podido almacenar correctamente los poderes"
                   "en el archivo"<<std::endl;
    }
   return 0;
}