#include "solucion.h"
#include "funciones_auxiliares.h"

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
    return;
}

void ralentizar(reunion& r, int prof, int freq) {
    // Implementacions
    return;
}

vector<hablante> tonosDeVozElevados(reunion r, int freq, int prof) {
    vector<hablante> maximos;
    // Implementacion
    return maximos;
}

void ordenar(reunion& r, int freq, int prof) {
    // Implementacion
    return;
}

vector<intervalo > silencios(senial s, int prof, int freq, int umbral) {
    vector<pair<int,int> > intervalos;
    // Implementacion
    return intervalos;
}


bool hablantesSuperpuestos(reunion r, int prof, int freq, int umbral) {
    bool resp = false;
    resp = hayHablantesSuperpuestos(r,freq,umbral);
    return resp;
}

senial reconstruir(senial s, int prof, int freq) {
    senial senalReconstruida;
    senalReconstruida = reconstruirSenial(s);
    return senalReconstruida;
}

void filtradoMediana(senial& s, int R, int prof, int freq){
    return esFiltrada(s,R)
}

