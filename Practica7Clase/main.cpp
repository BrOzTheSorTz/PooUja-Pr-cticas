/**
 * @file main.cpp
 * @author 
 *
 */

#include <iostream>
#include <fstream>  //Esta biblioteca nos permite leer y escribir en archivos

/**Hay otras 2 bibliotecas:
 * -Ofstream -> Para escribir en archivos
 * -Ifstream -> Para leer en archivos
 *
 * (No me detecta la primera el clion)
 * **/

#include "EquipoMutante.h"

using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza( Mutante& m) {
    std::cout << "MUTANTE: " 
              << m.toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    for(int i=0;i<m.getNumPoderes();++i){
        //No se si hace falta crear un obtenerPoder() para cada uno de los poderes
        std::cout<<m.obtenerPoder(i+1)->toCSV()<<std::endl;
    }


}
/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza( EquipoMutante& eq) {
    std::cout << "EQUIPO: " << eq.getNombre() 
              << " (Base: " << eq.getBase()<< ")" <<std::endl
              << "============================"
              << std::endl;
    std::cout<<" Miembros: "<<std::endl;
    for(int i=0;i<eq.getNumMiembros();++i){
        //Usando la función anterior
        visualiza(*eq.getMutante(i+1));

        /* Otra manera de hacerlo:
        std::cout<<eq.getMutante(i+1)->toCSV()<<std::endl;*/
    }


}

//ToDo, Método para almacenar un vector de punteros a mutantes
void almacenaMutantesCSV(Mutante* v[],int tama,std::string nombreArchivo){
    fstream  aux;
    //Abrimos el archivo

    ///Importante std::ios::out -> Lo he mirado en internet porque si no lo pongo , no se me abre el archivo
    ///std::ios Con esto queremos indicar el modo del archivo, es decir;
    ///     -IN(entrada), para leer de un archivo
    ///     -OUT(salida),para escribir en un archivo y mostrarlo

    aux.open(nombreArchivo,std::ios::out);
    //Comprobamos si se ha podido abrir el fichero
    if(aux.good()){
        //Recorremos el vector de punteros a mutantes para almacenarlos en el archivo
        for(int i=0;i<tama;++i){
            //Almacenamos cada mutante en formato CSV en el archivo
            aux<<"Mutante "<<i+1<<".-"<<v[i]->toCSV()<<endl;
        }

        //Cerramos el archivo
        aux.close();
    }else{
        std::cerr<<"No se ha podido abrir el archivo."<<std::endl;
    }

}

void almacenaMutantesCSV1(Mutante* v[],int tama,std::string nombreArchivo){
    ofstream  aux;
    //Abrimos el archivo

    ///Al usar la biblioteca ofstream no hace falta poner el std::ios::out

    aux.open(nombreArchivo);
    //Comprobamos si se ha podido abrir el fichero
    if(aux.good()){
        //Recorremos el vector de punteros a mutantes para almacenarlos en el archivo
        for(int i=0;i<tama;++i){
            //Almacenamos cada mutante en formato CSV en el archivo
            aux<<"Mutante "<<i+1<<".-"<<v[i]->toCSV()<<endl;
        }

        //Cerramos el archivo
        aux.close();
    }else{
        std::cerr<<"No se ha podido abrir el archivo."<<std::endl;
    }

}

void almacena( EquipoMutante &eq,std::string nombreArchivo){
    ofstream aux;

    //Abrimos el archivo
    aux.open(nombreArchivo);
    //Comprobamos que se a abierto correctamente
    if(aux.good()){
        //Habría que comprobar que hay suficiente espacio
        /**
         * Para hacer lo anterior habría que utilizar una biblioteca externa.
         * En este habría alguna función para calcular la memoria restante de la unidad de almacenamiento
         * Y en fstream habría una función para calcular el tamaño del archivo y con esto puedes ir comprobando
         * */
        aux<<eq.getNombre()<<";"<<eq.getBase()<<".Miembros: "<<std::endl;
        for(int i=0;i<eq.getNumMiembros();++i){
            //Si en el parámetro
            aux<<"-"<<eq.getMutante(i+1)->getNombreReal()<<std::endl;

        }

        //cerramos el archivo
        aux.close();

    }else{
        std::cerr<<"[almacena()]No se ha abierto correctamente el archivo"<<std::endl;
    }
}
int main(int argc, char** argv) {

    
   // Crea un array de 5 punteros a mutantes, asignándoles los valores a sus
   // atributos directamente en el código fuente
   Mutante m1,m2,m3,m4,m5;
   m1.setNombreReal("paquito").setNacionalidad("espaniol").setFechaDeNacimiento(22112003).setApodo("Elcabesa");
   m2.setNombreReal("Lola").setNacionalidad("americana").setFechaDeNacimiento(22111903).setApodo("Latrera");
   m3.setNombreReal("Pablito").setNacionalidad("senegales").setFechaDeNacimiento(10112001).setApodo("Pinocho");
   m4.setNombreReal("Clavito").setNacionalidad("espaniol").setFechaDeNacimiento(22111999).setApodo("Elbotas");
   m5.setNombreReal("Marc").setNacionalidad("esloveno").setFechaDeNacimiento(22111000).setApodo("Metelios");


   Mutante* mutantes[5]={&m1,&m2,&m3,&m4,&m5};

    
   // Crea dos equipos mutantes, asignando al primero los mutantes que ocupan
   // las posiciones pares del array, y al segundo los de las posiciones impares
    EquipoMutante eq1={"Equipo A","Jaen"};
    EquipoMutante eq2 ={"Equipo Z","Vilches"};

    eq1.addMutante(mutantes[0]).addMutante(mutantes[2]).addMutante(mutantes[4]);
    eq2.addMutante(mutantes[1]).addMutante(mutantes[3]);

    
   // Añade varios poderes a cada mutante, utilizando los métodos ya
   // implementados: usando datos o objetos de tipo Poder
   // Muestra por la consola la información de cada equipo mutante en formato CSV
   Poder p1={"Laziest","Puede dormir a cualquier persona en cualquier momento",200};
   Poder p2={"EstiraZ","Puede alargar cualquier parte de su cuerpo tanto como desee"};
   Poder p3={"CupidoX","Con solo un guiño de ojo puede enamorar a 2 personas"};
   PoderPsiquico pPsiquico ={"ThinkMore","Lee la mente de las personas","A todos menos a los muertos",1000};

   mutantes[0]->addPoder(p1).addPoder("SpeedAX","Puede alcanzar velocidades inalcanzables","Afecta a seres vivos terrestres",100);
   mutantes[3]->addPoder(p2);
   mutantes[2]->addPoder(p3);
   mutantes[4]->addPoderPsiquico(pPsiquico).addPoder(p2);
   mutantes[1]->addPoderFisico("ReparteGalletas","Con un solo galletón mata a una persona","Seres vivos terrestres",120);


   std::cout<<"Información del equipo mutante 1: "<<eq1.toCSV()<<std::endl<<std::endl;
   std::cout<<"Información del equipo mutante 2: "<<eq2.toCSV()<<std::endl;
    
   //Guardamos datos de mutantes en fichero CSV

    /**
     *- Si al nombre del archivo no le pones ninguna extensión , el editor tomará .txt
     *-Puedes poner la extensión .csv para que se muestre en este formato
     *
     * OJO. EL archivo se crea dentro de la carpeta - cmake-build-debug
     *
     */
   // almacenaMutantesCSV(mutantes,5,"mutantesArchivo");
    
    
   // Destruye todos los objetos creados en memoria dinámica antes de la
   // finalización del programa

   //Los creados son los debidos a la composición y estos son eliminados en el destructor



   std::cout<<"==================================================="<<std::endl;
   //Probamos el programa
   std::cout<<"Capacidad destructiva del mutante 1: "<<mutantes[0]->capacidadDestructiva()<<std::endl;
   //Al poder 1 lo inhibimos
   mutantes[0]->obtenerPoder(1)->cambiarInhibido();
   std::cout<<"Capacidad destructiva del mutante 1 al inhibir el poder 1: "<< mutantes[0]->capacidadDestructiva()<<std::endl;


   //Creamos un archivo txt para el equipo mutante primero
    almacena(eq1,"EquipoMutanteText.txt");

    return 0;
}

