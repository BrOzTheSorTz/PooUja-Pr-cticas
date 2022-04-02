//
// Created by soria on 17/02/2022.
//

#include "Vehiculo.h"
#include <iostream>
#include <string>



/**
 * @brief Método selector
 * @return Devuelve la marca del vehículo
 */
std::string Vehiculo::getMarca() const {
    return marca;
}
/**
 * @brief Asigana al atributo marca un valor
 * @param marca
 */
void Vehiculo::setMarca(const std::string &marca) {
    this->marca = marca;
}
/**
 * @brief Método selector
 * @return Devuelve el modelo del vehículo
 */
std::string Vehiculo::getModelo() const {
    return modelo;
}
/**
 * @brief Asigana al atributo modelo un valor
 * @param modelo
 */
void Vehiculo::setModelo(const std::string &modelo) {
    this->modelo = modelo;
}
/**
 * @brief Método selector
 * @return Devuelve la matrícula del vehículo
 */
std::string Vehiculo::getMatricula() const {
    return matricula;
}
/**
 * @brief Asigana al atributo matrícula un valor
 * @param matricula
 */
void Vehiculo::setMatricula(const std::string &matricula) {
    this->matricula = matricula;
}
/**
 * @brief Método selector
 * @return Devuelve el anio de fabricación del vehículo del vehículo
 */
int Vehiculo::getAnioFabricacion() const {
    return anioFabricacion;
}
/**
 * @brief Asigana al atributo anio de fabricacion un valor
 * @param anioFabricacion
 */
void Vehiculo::setAnioFabricacion(int anioFabricacion) {
    this->anioFabricacion = anioFabricacion;
}
/**
 * @brief Método selector
 * @return Devuelve el precio del vehículo
 */
float Vehiculo::getPrecio() const {
    return precio;
}
/**
 * @brief Asigana al atributo precio un valor
 * @param precio
 */
void Vehiculo::setPrecio(float precio) {
    this->precio = precio;
}

/**
 * @brief Muestra el pantalla los datos de un vehículo
 *
 */
void Vehiculo::leePorTeclado(){
    std::string marca="" ;
    std::string modelo="";
    std::string matricula = "";
    int anio = 0;

    try{
        std::cout << "Introduzca la marca: ";
        std::cin >> marca;
        this->setMarca(marca);
        if (marca.length() < 3 || marca.length() > 20) {
            throw std::string("Problema con la longitud.(Max: 20 y Min: 3)");
        }
    }catch(std::string &e){
        std::cout<<e<<std::endl;
    }

    try{
        std::cout << "Introduzca el modelo: ";
        std::cin >> modelo;
        if(modelo.length()<1 || modelo.length()>30){
            throw std::string("Recuerda: Longitud Max: 30 y Min: 1");
        }
        this->setModelo(modelo);


    }catch (std::string &e){
        std::cout<<e<<std::endl;

    }

    try{
        std::cout << "Introduzca la matricula: ";
        std::cin >> matricula;
        if(matricula.length()!=6){
            throw std::string ("Error: Longitud debe ser 6");
        }
        this->setMatricula(matricula);
    }catch(std::string &e){
        std::cout<<e<<std::endl;

    }

    std::cout<<"Introduzca el anio de fabricacion: ";
    std::cin>>anio;
    this->setAnioFabricacion(anio);

    try {
        std::cout << "Introduzca un precio: ";
        std::cin >> precio;
        if(precio<0){
            throw std::string("Error: Precio debe ser mayor que 0");
        }
        this->setPrecio(precio);
    }catch (std::string &e){
        std::cout<<e<<std::endl;
    }

}




/**
 * @brief Muestra el pantalla los datos de un vehículo
 * @param vehiculo
 */
void Vehiculo::muestraEnPantalla() {
    std::cout<<"Los datos del vehiculo son : "<<std::endl;
    std::cout<<"Marca: "<<this->getMarca()<<
             ". Modelo: "<<this->getModelo()<<
             ". Matricula: "<<this->getMatricula()<<
             ". Anio de fabricacion: "<<this->getAnioFabricacion()<<
             ". Precio: "<<this->getPrecio()<<std::endl;

}
/**
 * @brief Rellenar un vector de vehículos
 * @param vehiculos
 * @param tama
 */
 //Los arrayas se pasan por referencia aunque no lo indiquemos

void Vehiculo::rellenarVector(Vehiculo vehiculos[], const int &tama) {
    try {
        if (tama < 0) {
            throw std::string("El tamanio no puede ser negativo !");

        }
        for(int i=0;i<tama;++i){
            vehiculos[i].leePorTeclado();
            std::cout<<std::endl<<std::endl;
        }
    }catch(std::string &e){
        std::cout<<e<<std::endl;
    }



}
/**
 * @brief Muestra un vector de vehículos por pantalla considerando:
 *        -Los vehículos se muestran de 5 en 5
 *        -Hacer pausa cada 5 y esperar que el usuario pulse una tecla para empezar
 * @param vehiculos
 * @param tama
 */
void Vehiculo::mostrarVectorEnPantalla( const Vehiculo vehiculos[], const int &tama) {
    char tecla ='0';
    Vehiculo v1= vehiculos[0];

    for(int i=0;i<tama;++i){
        v1 = vehiculos[i];

        if(i % 5==0 && i!=0){
            do{
                std::cout<<"Introduzca '1' para mostrar los siguientes vehículos: ";
                std::cin>>tecla;
            }while(tecla != '1');
        }
        v1.muestraEnPantalla();

    }
}

/**
 * @brief Busca y devuelve la posición del vector de un vehículo a partir de su matrícula
 * @param matricula
 * @param vehiculos
 * @param tama
 * @return
 */
int Vehiculo::buscarPorMatricula(const std::string &matricula, const Vehiculo *vehiculos, const int &tama) {
    int posicion =-1;
    for(int i=0;i<tama;++i){
        if(matricula == vehiculos[i].matricula){
            posicion = i;
        }
    }
    try {
        if (posicion == -1) {
            throw std::string("Vehiculo NO encontrado !");
        }
    }catch (std::string &e){
        std::cout<<e<<std::endl;
    }
    return posicion;

}
/**
 * @brief Calcula y devuelve la posición en el vector del vehículo con precio máximo
 *
 * @param vehiculos
 * @param tama
 * @return
 */
int Vehiculo::maxPrecio(const Vehiculo vehiculos[], const int &tama) {
    int posicion=0;
    //Supongo que el primer elemento es el mayor
    int mayor = vehiculos[posicion].precio;

    for(int i=1;i<tama;++i){
        if(vehiculos[i].precio > mayor){
            mayor=vehiculos[i].precio;
            posicion=i;
        }
    }


    return posicion;
}




