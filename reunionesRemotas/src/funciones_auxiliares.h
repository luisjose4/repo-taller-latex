//
// Created by Luijo on 13/06/2020.
//

#ifndef TPI_FUNCIONES_AUXILIARES_H
#define TPI_FUNCIONES_AUXILIARES_H

#include "definiciones.h"

//esSenial
bool esValida(senial s, int prof, int freq);
bool freqValida(int freq);
bool enRango(senial s, int prof);
bool profValida(int prof);
bool duraMasDe(senial s, int freq, float seg);

//seEnojo
bool existeSubseqEnojada(senial s, int umbral, int prof, int freq);

//esReunionValida
bool reunionValida(reunion r, int prof, int freq);

//acelerar
void acelerarSenial(senial& s, int prof, int freq);

//hablantesSuperpuestos
bool hayHablantesSuperpuestos(reunion r,int freq,int umbral);

//reconstruir
senial reconstruirSenial(senial s);

//filtradoMediana
bool Filtrada(senial s, int R);

#endif //TPI_FUNCIONES_AUXILIARES_H