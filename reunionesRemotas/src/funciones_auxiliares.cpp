
#include "funciones_auxiliares.h"

/************* Ejercicio 1 - esSenial *************/

bool esValida(senial s, int prof, int freq){
    return freqValida(freq) && enRango(s, prof) && profValida(prof) && duraMasDe(s, freq, 1);
}

bool freqValida(int freq){
    return freq == 10; //preguntar si efectivamente esto es 10Hz o 10kHz
}

bool enRango(senial s, int prof){
    int umbralSuperior = pow(2, prof - 1) - 1;
    int umbralInferior = - pow(2, prof - 1);
    bool res = true;
    for (int i = 0; i < s.size() && res; i++)
    {
        res = res && (umbralInferior <= s[i]) && (s[i] <= umbralSuperior);
    }
    return res;
}

bool profValida(int prof){
    return prof == 8 || prof == 16 || prof == 32;
}

bool duraMasDe(senial s, int freq, float seg){//preguntar
    return s.size() >= freq * seg;
}

/************* Ejercicio 2 - seEnojo *************/

float tono(senial s)
{

    float sum = 0;

    for (int i = 0; i < s.size(); i++)
    {
        sum = sum + abs(s[i]);	//hace falta pasarlo a double??
    }
    return sum / s.size();
}

bool superaUmbral(senial s, int umbral){
    return tono(s) > umbral;
}

bool existeSubseqEnojada(senial s, int umbral, int prof, int freq){
    for (int i = 0; i < s.size() - 2*freq; ++i) {
        for (int j = i + 2*freq; j < s.size(); ++j) {
            senial subseq = senial ( s.begin() + i, s.begin() + j );
            if ( superaUmbral(subseq, umbral) ) return true;
        }
    }
    return false;
}

/*
bool umbralValido(int umbral){
  return umbral > 0;
}
*/

/************* Ejercicio 3 - esReunionValida *************/

bool esMatriz(vector<pair<senial, hablante>> r){
    for (int i = 0; i < r.size(); ++i) {
//        if ( typeid(r[i]) != typeid(pair<senial, hablante>) ) return false;
    } //comparo los tipos (que sean de tipo pair<senial, hablante>
    return true;
}//esta bien que sea asi la entrada? me parece que entonces no tendria sentido ver si es matriz
//preguntar si mas bien no seria comprobar la longitud de las señales

bool senialesValidas(reunion r, int prof, int freq){
    for (int i = 0; i < r.size(); ++i) {
        if ( !esValida(r[i].first, prof, freq) ) return false;
    }
    return true;
}

bool todosHablantesDistintos(reunion r){
    for (int i = 0; i < r.size(); ++i) {
        for (int j = i + 1; j < r.size(); ++j) {
            if ( r[i].second == r[j].second ) return false;
        }
    }
    return true;
}

bool hablantesDeReunionValidos(reunion r, int prof, int freq) {//para que recibe aca prof y freq??
    bool res = todosHablantesDistintos(r);
    for (int i = 0; i < r.size() && res; ++i) {
        res = res && (0 <= r[i].second) && (r[i].second < r.size());
    }
    return res;
}

bool reunionValida(reunion r, int prof, int freq){
    return (r.size() > 0) && esMatriz(r) && senialesValidas(r, prof, freq) && hablantesDeReunionValidos(r, prof, freq);
}

/************* Ejercicio 4 - acelerar *************/

void acelerarSenial(senial& s, int prof, int freq){
    for (int i = 0; i < s.size(); ++i) {
        s.erase(s.begin() + i);
    }
    return;
}

/************* Ejercicio 5 - ralentizar *************/

void ralentizarSenial(senial& s, int prof, int freq){
    int longFinal = 2 * s.size() - 1;
    senial salida(longFinal, 0);
    for (int i = 0; i < salida.size(); ++i) {
        int valor;
        if ( i % 2 == 0 ) {
            salida[i] = s[i/2];
        }
        else {
            salida[i] = ( s[i/2] + s[i/2 + 1] ) / 2;
        }
    }
    s = salida;
    return;
}

/************* Ejercicio 6 - tonosDeVozElevados *************/

vector<hablante> hablantesConTonosElevados(reunion r, int freq, int prof){
    vector<hablante> hablantes = {};
    float mayorTono = 0;
    for (int i = 0; i < r.size(); ++i) {
        float iesimoTono = tono( r[i].first );

        if ( iesimoTono > mayorTono ){
            mayorTono = iesimoTono;
            hablantes = { r[i].second };
        }
        if ( iesimoTono == mayorTono ) {
            hablantes.push_back(r[i].second);
        }
    }
    return hablantes;
}
