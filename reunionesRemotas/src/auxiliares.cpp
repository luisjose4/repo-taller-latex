#include "../lib/gtest.h"
#include "definiciones.h"
#include "auxiliares.h"
#include "funciones_auxiliares.h"

/************* Ejercicio 4 *************/

void escribirSenial(senial  s, string nombreArchivo){
    // Implementacion
    return;
}

senial leerSenial(string nombreArchivo){
    senial s;
    // Implementacion
    return s;
}

/************* Ejercicio 4 *************/


/************* ordenar *************/

vector<pair<hablante, float> > obtenerReunionYSusPromedios(reunion r)
{
    vector<pair<hablante, float> > ret;
    pair<hablante, float> nodo;

    for (int m = 0; m < r.size(); m++) {
        nodo.first = r[m].second;
        nodo.second = tono(r[m].first);

        ret.push_back(nodo);
    }

    return ret;
}

void ordenarPromedios(vector<pair<hablante, float> > &promedios)
{
    /* Insertion sort */

    for (int i = 1; i < promedios.size(); i++) {
        for (int j = i; j > 0 && promedios[j - 1].second < promedios[j].second; j--) {
            iter_swap(promedios.begin() + j, promedios.begin() + j - 1);
        }
    }

}

void ordenarReunionAcordeAPromedios(reunion &r, vector<pair<hablante, float> > promediosOrdenados)
{
    int nHablante;
    reunion reunionOriginal = r;

    for (int k = 0; k < r.size(); k++) {
        nHablante = promediosOrdenados[k].first;
        r[k] = reunionOriginal[nHablante];
    }
}

/************* ordenar *************/

/************* silencios *************/

bool superaUmbral(int valor, int umbral)
{
    return abs(valor) >= umbral;
}

void actualizarIndicesYFlags(int &inicioSilencio, int indiceActual, bool &outCandidatoSilencio, bool &outEsSilencio, int freq)
{
    if (outCandidatoSilencio == false) {
        inicioSilencio = indiceActual;
    }
    outCandidatoSilencio = true;

    if (indiceActual - inicioSilencio >= freq * 0.1) {
        outEsSilencio = true;
    }
}

void agregarIntervalo(vector<intervalo> &listaDeSilencios, int inicioSilencio, int finSilencio)
{
    intervalo silencio;

    silencio.first = inicioSilencio;
    silencio.second = finSilencio;

    listaDeSilencios.push_back(silencio);
}

vector<intervalo> obtenerSilencios(senial s, int freq, int umbral)
{
    vector<intervalo> ret(0);
    int inicioSilencio = 0;
    bool candidatoASilencio = false;
    bool esSilencio = false;


    for (int i = 0; i < s.size(); i++) {

        if (superaUmbral(s[i], umbral) == false) {
            actualizarIndicesYFlags(inicioSilencio, i, candidatoASilencio, esSilencio, freq);
        }

        else {
            if (esSilencio) {
                agregarIntervalo(ret, inicioSilencio, i - 1);
            }
            esSilencio = false;
            candidatoASilencio = false;
        }
    }



    if (esSilencio) { /* agregar silencio en caso de que termine al final */
        agregarIntervalo(ret, inicioSilencio, s.size() - 1);
    }

    return ret;
}

/************* silencios *************/

bool senialesOrdenadasIguales(senial s1, senial s2){

    if(s1.size() != s2.size())
        return false;

    for (int i = 0; i < s1.size(); ++i){
        if (s1[i] != s2[i]){
        	return false;
        }
    }

    return true;
}

bool reunionesIguales(reunion reunion1, reunion reunion2){
    if(reunion1.size() != reunion2.size())
        return false;

    for (int i = 0; i < reunion1.size(); ++i) {
        if(reunion1[i].second != reunion2[i].second)
            return false;

        if(reunion1[i].first.size() != reunion2[i].first.size())
            return false;

        sort(reunion1[i].first.begin(), reunion1[i].first.end());
        sort(reunion2[i].first.begin(), reunion2[i].first.end());

        if(!senialesOrdenadasIguales(reunion1[i].first, reunion2[i].first))
            return false;
    }

    return true;
}

bool hablantesOrdenadosIguales(vector<hablante> s1, vector<hablante> s2){
    if(s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

bool intervalosOrdenadosIguales(vector<intervalo> s1, vector<intervalo> s2){
    if(s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

void ASSERT_SENIAL_EQ(senial s1, senial s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    ASSERT_TRUE(senialesOrdenadasIguales(s1, s2));
}

void ASSERT_REUNION_EQ(reunion reunion1, reunion reunion2) {
    ASSERT_TRUE(reunionesIguales(reunion1, reunion2));
}

void ASSERT_HABLANTES_EQ(vector<hablante> s1, vector<hablante> s2) {
    ASSERT_TRUE(hablantesOrdenadosIguales(s1, s2));
}

void ASSERT_INTERVALOS_EQ(vector<intervalo> s1, vector<intervalo> s2) {
    ASSERT_TRUE(intervalosOrdenadosIguales(s1, s2));
}
