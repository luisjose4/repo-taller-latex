#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"
#include <iostream>



/************* esSenial ************/
bool esValida(senial s, int prof, int freq);
bool duraMasDe(senial s, int freq, float seg);


/************* seEnojo *************/
float tono(senial s);
bool existeSubseqEnojada(senial s, int umbral, int prof, int freq);


/******** esReunionValida **********/
bool reunionValida(reunion r, int prof, int freq);


/************* accelerar ***********/
void acelerarSenial(senial &s, int prof, int freq);


/************* relentizar **********/
void ralentizarSenial(senial &s, int prof, int freq);


/******** tonosDeVozElevados *******/
vector<hablante> hablantesConTonosElevados(reunion r, int freq, int prof);


/************* ordenar *************/
void ordenarReunionAcordeAPromedios(reunion &r);


/************ silencios ************/
void actualizarIndicesYFlags(int &inicioSilencio, int indiceActual, bool &outCandidatoSilencio, bool &outEsSilencio, int freq);
void agregarIntervalo(vector<intervalo> &listaDeSilencios, int inicioSilencio, int finSilencio);
vector<intervalo> obtenerSilencios(senial s, int freq, int umbral);


/****** hablantesSuperpuestos ********/
bool hayHablantesSuperpuestos(reunion r, int freq, int umbral);


/*********** reconstruir *************/
senial reconstruirSenial(senial s);


/********* friltradoMediana **********/
senial filtrada(senial s, int R);




/************* Ejercicio 4 *********/
senial leerSenial(string nombreArchivo);
void escribirSenial(senial s, string nombreArchivo);
/************* Ejercicio 4 *********/



void ASSERT_SENIAL_EQ(senial s1, senial s2);
void ASSERT_REUNION_EQ(reunion reunion1, reunion reunion2);
void ASSERT_HABLANTES_EQ(vector<hablante> s1, vector<hablante> s2);
void ASSERT_INTERVALOS_EQ(vector<intervalo> s1, vector<intervalo> s2);

#endif //REUNIONESREMOTAS_AUXILIARES_H
