//
// Created by admin on 26/04/2022.
//

#ifndef PRUEBA_UTILIDADES_H
#define PRUEBA_UTILIDADES_H
#include <fstream>

template <typename T>
int numElementosSuperiores(T* v[],int tamv,T elemento){
    int contador=0;
    for(int i=0;i<tamv;++i){
        //Como no está implementado el operador '>' podemos hacer los siguiente
        if(!(*v[i]<elemento)){
            ++contador;
        }
    }
    return contador;
}

template <typename T>
int RecuperaCSV(T* v[],int tamv, std::string nombreArchivo){
    std::ifstream aux;
    int cont=0; ///<Iremos contando el número de mutantes que se añaden
    std::string cadena=""; ///<En esta variable almacenamos las líneas en CSV del archivo

    aux.open(nombreArchivo);
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

                cadena="";//Inicializamos de nuevo la línea



            }

        }
        //Cerramos el archivo
        aux.close();


    }else{
        std::cerr<<"No se ha podido abrir el archivo"<<std::endl;
    }
    return cont;//Número de 'T' leidos
}
#endif //PRUEBA_UTILIDADES_H
