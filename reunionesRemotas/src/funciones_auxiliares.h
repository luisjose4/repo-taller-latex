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

float tono(senial s);

//seEnojo
bool existeSubseqEnojada(senial s, int umbral, int prof, int freq);

//esReunionValida
bool reunionValida(reunion r, int prof, int freq);

//acelerar
void acelerarSenial(senial& s, int prof, int freq);

//ralentizar
void ralentizarSenial(senial& s, int prof, int freq);

//tonosDeVozElevados
vector<hablante> hablantesConTonosElevados(reunion r, int freq, int prof);

#endif //TPI_FUNCIONES_AUXILIARES_H
