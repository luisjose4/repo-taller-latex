#include "solucion.h"
#include "auxiliares.h"
#include "definiciones.h"

// Ejercicios

bool esSenial(vector<int> s, int prof, int freq) {
    return freqValida(freq)  &&  enRango(s, prof)  &&  profValida(prof)  &&  duraMasDe(s, freq, 1);
}

bool seEnojo(senial s, int umbral, int prof, int freq) {
    int cantMinimaDeElementos = 2 * freq;

    if ( s.size() < cantMinimaDeElementos ) return false;

    bool res = false;

    for (int i = 0; ( i <= s.size() - cantMinimaDeElementos ) && !res; ++i) {
        for (int j = i + cantMinimaDeElementos; ( j <= s.size() ) && !res; ++j) {
            senial subseq = subSeq(s, i, j);

            res = superaUmbral(subseq, umbral);
        }
    }

    return res;}

bool esReunionValida(reunion r, int prof, int freq) {
    return (
                r.size() > 0  &&
                esMatriz(r)  &&
                senialesValidas(r, prof, freq)  &&
                hablantesDeReunionValidos(r, prof, freq)
            );
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
    vector<hablante> hablantes = { };
    float mayorTono = 0;

    for (int i = 0; i < r.size(); ++i) {
        float iesimoTono = tono(r[i].first);

        if (iesimoTono > mayorTono) {
            mayorTono = iesimoTono;
            hablantes = { r[i].second };
        }
        else if (iesimoTono == mayorTono) {
            hablantes.push_back(r[i].second);
        }
    }

    return hablantes;
}

void ordenar(reunion& r, int freq, int prof) {

    for (int i = 1; i < r.size(); ++i) {
        pair<senial, hablante> elementoAOrdenar = r[i];
        for (int j = i-1; j >= 0; --j) {
            if (tono(elementoAOrdenar.first) > tono(r[j].first)) {
                swapPorTono(r, j+1, j);
            }
        }
    }
}

vector<intervalo> silencios(senial s, int prof, int freq, int umbral)
{
    vector<intervalo> ret(0);
    int inicioSilencio = 0;
    bool esSilencio = false;

    for (int i = 0; i < s.size(); i++) {

        if ( superaUmbral(s[i], umbral) ) {
        	agregarIntervaloSiCorresponde(ret,inicioSilencio, i-1, esSilencio);
        	inicioSilencio = i + 1;
        	esSilencio = false;
        }
        else if (i>0){
        	if(superaUmbral(s[i-1], umbral) ){
        		inicioSilencio = i;
        	}
        	if(i + 1 - inicioSilencio >= freq * 0.2){
        		esSilencio = true;
        	}
        }

    }

    if (esSilencio) { /* agregar silencio en caso de que termine al final */
    	agregarIntervaloSiCorresponde(ret, inicioSilencio, s.size() - 1, esSilencio);
    }

    return ret;
}

bool hablantesSuperpuestos(reunion r, int prof, int freq, int umbral)
{
    for (int i = 0; i < r[0].first.size(); ++i) {
        int personasHablando = 0;
        for (int j = 0; j < r.size(); ++j) {
            if ( estaHablando(r[j].first, i, umbral) ) {
                ++personasHablando;
            }
            if (personasHablando == 2) {
                return true;
            }
        }
    }
    return false;
}

senial reconstruir(senial s, int prof, int freq)
{
    vector<int> sCero = s;
    for (int i = 0; i <= s.size(); ++i) {
        if (s[i] == 0) {
            if (!esPasajePorCero(sCero, i)) {
                s[i] = valor(sCero, i);
            }
        }
    }

    return s;
}

void filtradoMediana(senial &s, int R, int prof, int freq)
{
    senial w; // 1
    senial sCero = s;
    for (int i = 0; i < s.size(); ++i) { // n
        if (!coincidenExtremos(sCero, i, R)) { // 1
            w = ordenarSenialW(subSeq(sCero, i - R, i + R + 1)); //
            s[i] = w[R]; // 1
        }
    }
}
