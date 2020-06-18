#include "solucion.h"
#include "auxiliares.h"
#include "definiciones.h"

// Ejercicios

bool esSenial(vector<int> s, int prof, int freq) {
    return esValida(s, prof, freq);
}

bool seEnojo(senial s, int umbral, int prof, int freq) {
    return existeSubseqEnojada(s, umbral, prof, freq);
}

bool esReunionValida(reunion r, int prof, int freq) {
    return reunionValida(r, prof, freq);
}

void acelerar(reunion& r, int prof, int freq) {
    for (int i = 0; i < r.size(); ++i) {
        acelerarSenial(r[i].first, prof, freq);
    }
}

void ralentizar(reunion& r, int prof, int freq) {
    for (int i = 0; i < r.size(); ++i) {
        ralentizarSenial(r[i].first, prof, freq);
    }
}

vector<hablante> tonosDeVozElevados(reunion r, int freq, int prof) {
    return hablantesConTonosElevados(r, freq, prof);
}

void ordenar(reunion& r, int freq, int prof) {
    vector<pair<hablante, float> > promedios;

    promedios = obtenerReunionYSusPromedios(r);
    ordenarPromedios(promedios);
    ordenarReunionAcordeAPromedios(r, promedios);
}

vector<intervalo> silencios(senial s, int prof, int freq, int umbral)
{
    vector<intervalo> intervalos;
    intervalos = obtenerSilencios(s, freq, umbral);
    return intervalos;
}

bool hablantesSuperpuestos(reunion r, int prof, int freq, int umbral) {
    bool resp = false;
    // Implementacion
    return resp;
}

senial reconstruir(senial s, int prof, int freq) {
    senial senalReconstruida;
    // Implementacion
    return senalReconstruida;
}

void filtradoMediana(senial& s, int R, int prof, int freq){
    // Implementacion
    return;
}
