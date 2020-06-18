#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"
#include <iostream>

/************* Ejercicio 4 *************/

senial leerSenial(string nombreArchivo);
void escribirSenial(senial  s, string nombreArchivo);

/************* Ejercicio 4 *************/

/************* ordenar *************/

vector<pair<hablante, float> > obtenerReunionYSusPromedios(reunion r);
void ordenarPromedios(vector<pair<hablante, float> > &promedios);
void ordenarReunionAcordeAPromedios(reunion &r, vector<pair<hablante, float> > promediosOrdenados);

/************* ordenar *************/

/************* silencios *************/

void actualizarIndicesYFlags(int &inicioSilencio, int indiceActual, bool &outCandidatoSilencio, bool &outEsSilencio, int freq);
void agregarIntervalo(vector<intervalo> &listaDeSilencios, int inicioSilencio, int finSilencio);
vector<intervalo> obtenerSilencios(senial s, int freq, int umbral);

/************* silencios *************/

void ASSERT_SENIAL_EQ(senial s1, senial s2);
void ASSERT_REUNION_EQ(reunion reunion1, reunion reunion2);
void ASSERT_HABLANTES_EQ(vector<hablante> s1, vector<hablante> s2);
void ASSERT_INTERVALOS_EQ(vector<intervalo> s1, vector<intervalo> s2);

#endif //REUNIONESREMOTAS_AUXILIARES_H
