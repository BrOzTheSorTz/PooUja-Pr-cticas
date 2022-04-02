//
// Created by soria on 26/02/2022.
//

#ifndef PRACTICA2CASA_DJUTILS_H
#define PRACTICA2CASA_DJUTILS_H
#include <iostream>

#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"


void mostrarTemazo ( const Temazo &c);
void mostrarGarito(const Garito &g);
void modificarGarito ( Garito &g);
void mostrarFecha(const Fecha &f);
void mostrarTemazosAnteriores(const Temazo v[], const int &tama, const Fecha &f);
void verTemazosMasLargosQue(const Temazo v[],const int &tama, const Temazo &t);
///Método para obtener una lista de punteros a TEMAZOS
///con una duración conjunto inferior a un valor determinado
//ToDo

// void temazosConDuracionInferior(int duracionTotal,Temazo* pv,int &tamaPv,const Temazo v[],int tamanio );
int listaRelleno( Temazo v[],int tamv,Temazo* lista[],int tamLista,int duracionTotal);

#endif //PRACTICA2CASA_DJUTILS_H
