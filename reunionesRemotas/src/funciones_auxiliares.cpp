//
// Created by Luijo on 13/06/2020.
//

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

float tono(senial s){
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
        if ( typeid(r[i]) != typeid(pair<senial, hablante>) ) return false;
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
    int i = 0;
    while ( i < s.size() ){
        s.erase(s.begin()+i);
        i = i + 1;//es i+1 porque al hacer el erase modifico la longitud de s y no necesito ir sumando 2
    }
    return;
}

/************* Ejercicio 9 - hablantesSuperpuestos *************/
bool hayHablantesSuperpuestos(reunion r,int freq,int umbral){
    for (int h1 = 0; h1 < r.size(); ++h1) {
        for (int h2 = h1 + 1; h2 < r.size() ; ++h2) {
            if (!(seRespetan(r,h1,h2,freq,umbral))){
                return true

            }
        }

    }
}

bool haySilencioQueLoContiene(senial s, int i, int freq, int umbral){
    for (int j = 0; j < s.size() ; ++j) {
        for (int k = j+1; k < s.size(); ++k) {
            if (j <= i && k>=i && esSilencio(s,j,k,freq,umbral)){
                return true;
            }
        }
    }
    return false;
}

bool seRespetan(reunion r,int h1,int h2,int freq,int umbral){
    bool res = true;
    for (int i = 0; i < r[h1].first && res ; ++i) {
        if(!(haySilencioQueLoContiene(r[h1].first,i,freq,umbral))) {
            if (!haySilencioQueLoContiene(r[h2].first, i, freq, umbral)) {
                res = false;
            }
        }
    }
}

/************* Ejercicio 10 - reconstruir *************/

senial reconstruirSenial(senial s){
    for (int i = 0; i < s.size() ; ++i) {
        if (s[i] == 0){
            if(esPasajePorCero(s, i) && s[0] = 0){
                // pasa al siguiente elemento.                                         queda raro...
            } else if(!esPasajePorCero(s,i) && esValorEnPosicion(s,s[i],i)){
                s[i] = valor(s,i);
            }
        }
    }

    return s;
}



bool esValorEnPosicion(senial s,int valor,int i){
    int j = i-1;
    int k = i+1;
    while (j!=0 && s[j]==0){
        --j;
    }
    while (k!= s.size() && s[k]==0){
        ++k;
    }
    return masCercanosNoNulos(s,i,j,k);

}

bool masCercanosNoNulos(senial s, int i, int j, int k){
    return distancia(j,k) <= 5;
}

bool reconstruirPosicionSiCorresponde(senial s,int i){
    return (esPasajePorCero(s,i) && s[0] == 0) || (!esPasajePorCero(s,i) && valorEnPosicion(s,i))
}

bool esPasajePorCero(senial s, int i){
    return signo(s[i - 1])* signo(s[i + 1]) == -1;
}

int valor(senial s, int i){
    int j = i-1;
    int k = i+1;
    for (j; j!=0 && s[j]==0 ; --j) {

    }
    for (k ; k!= s.size()  ; ++k) {
        // nada, solo queremos que vaya sumando.
    }

    return (s[k] + s[j]) / 2;
}

int distancia(int j, int i){
    if(j-i < 0){
        return (j-i)*-1;
    }else {
        return j-i;
    }
}

int signo(int k){
    if(k > 0){
        return 1;
    } else if(k<0){
        return -1;
    }else{
        return 0;
    }
}

/************* Ejercicio 11 - friltradoMediana *************/
senial filtrada(senial s, int r){
    senial w;
    for (int i = 0; i < s.size(); ++i) {
         if(!coincidenExtremos(s,i,r)){
            w = ordenarSenialW(subSec(s,i-r,i+r+1));
            s[i]=w[r];
        }
    }
    return s;
}
bool coincidenExtremos(senial s,int i,int r){
    return i < r || i>= s.size() - r;
}

senial subSec(senial s,int i, int r){
    senial w = [];
    for (int j = i; j < r ; ++j) {
        w.push_back(s[j]);
    }
}
senial ordenarSenialW (senial w){
    return insertionSort(w);
}
senial insertionSort (senial lista ) {
    for(int i=0; i < lista . size () ; i++) {
        insertar (lista ,i) ;
    }
    return lista ;
}
void insertar ( senial &lista , int i) {
    while (i > 0 && lista [i] < lista [i -1]) {
        swap (lista ,i,i -1) ;
        i - -;
    }
}
void swap ( senial &lista , int i, int j) {
    int k= lista [i];
    lista [i]= lista [j];
    lista [j]=k;
}