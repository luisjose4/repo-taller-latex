#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"
#include <iostream>

senial subSeq(senial s, int i, int r);

/************* esSenial ************/
bool freqValida(int freq);
bool enRango(senial s, int prof);
bool profValida(int prof);
bool duraMasDe(senial s, int freq, float seg);


/************* seEnojo *************/
float tono(senial s);
bool superaUmbral(senial s, int umbral);

/******** esReunionValida **********/
bool esMatriz(reunion r);
bool senialesValidas(reunion r, int prof, int freq);
bool todosHablantesDistintos(reunion r);
bool hablantesDeReunionValidos(reunion r, int prof, int freq);


/************* acelerar ***********/
void acelerarSenial(senial &s, int prof, int freq);


/************* relentizar **********/
void ralentizarSenial(senial &s, int prof, int freq);


/******** tonosDeVozElevados *******/
// Sin auxiliares


/************* ordenar *************/
void swapPorTono(reunion &reunion, int i, int j);


/************ silencios ************/
bool superaUmbral(int valor, int umbral);
void agregarIntervaloSiCorresponde(vector<intervalo> &outListaIntervalos, int inicioSilencio, int indiceActual, bool esSilencio);


/****** hablantesSuperpuestos ********/
int valorAbsoluto(int x);
bool estaHablando(senial s, int pos, int umbral);


/*********** reconstruir *************/
int valor(vector<int> s, int i);
int signo(int k);
bool esPasajePorCero(vector<int> s, int i);


/********* friltradoMediana **********/
bool coincidenExtremos(senial s, int i, int r);
void swap(senial &lista, int i, int j);
void insertar(senial &lista, int i);
senial insertionSort(senial lista);
senial ordenarSenialW(senial w);



/************* Ejercicio 4 *********/
senial leerSenial(string nombreArchivo);
void escribirSenial(senial s, string nombreArchivo);
/************* Ejercicio 4 *********/



void ASSERT_SENIAL_EQ(senial s1, senial s2);
void ASSERT_REUNION_EQ(reunion reunion1, reunion reunion2);
void ASSERT_HABLANTES_EQ(vector<hablante> s1, vector<hablante> s2);
void ASSERT_INTERVALOS_EQ(vector<intervalo> s1, vector<intervalo> s2);

#endif //REUNIONESREMOTAS_AUXILIARES_H
