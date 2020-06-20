#include "../lib/gtest.h"
#include "definiciones.h"
#include "auxiliares.h"
#include <fstream>

/************* esSenial *************/
bool freqValida(int freq)
{
    return freq == 10; //preguntar si efectivamente esto es 10Hz o 10kHz
}

bool enRango(senial s, int prof)
{
    int umbralSuperior = pow(2, prof - 1) - 1;
    int umbralInferior = -pow(2, prof - 1);
    bool res = true;

    for (int i = 0; i < s.size() && res; i++) {
        res = ( umbralInferior <= s[i]  &&  s[i] <= umbralSuperior );
    }

    return res;
}

bool profValida(int prof)
{
    return prof == 8 || prof == 16 || prof == 32;
}

bool duraMasDe(senial s, int freq, float seg)
{
    return s.size() >= freq * seg;
}

bool esValida(senial s, int prof, int freq)
{
    return freqValida(freq)  &&  enRango(s, prof)  &&  profValida(prof)  &&  duraMasDe(s, freq, 1);
}


/************* seEnojo **************/
float tono(senial s)
{
    float sum = 0;

    for (int i = 0; i < s.size(); i++) {
        sum += abs(s[i]);
    }

    return sum / s.size();
}

bool superaUmbral(senial s, int umbral)
{
    return tono(s) > umbral;
}

bool existeSubseqEnojada(senial s, int umbral, int prof, int freq)
{
    int cantMinimaDeElementos = 2 * freq;

    if ( s.size() < cantMinimaDeElementos ) return false;

    bool res = superaUmbral(s, umbral);

    for (int i = 0; ( i <= s.size() - cantMinimaDeElementos ) && !res; ++i) {
        for (int j = i + cantMinimaDeElementos; ( j <= s.size() ) && !res; ++j) {
            senial subseq = senial(s.begin() + i, s.begin() + j);

            res = superaUmbral(subseq, umbral);
        }
    }

    return res;
}


/************ esReunionValida ******/
bool esMatriz(vector<pair<senial, hablante>> r)
{
    bool res = true;
    senial senialModelo = r[0].first;

    for (int i = 0; i < r.size() && res; ++i) {
        senial senial_i = r[i].first;

        res = ( senialModelo.size() == senial_i.size() );
    }

    return res;
}

bool senialesValidas(reunion r, int prof, int freq)
{
    bool res = true;

    for (int i = 0; i < r.size() && res; ++i) {
        res = esValida(r[i].first, prof, freq);
    }

    return res;
}

bool todosHablantesDistintos(reunion r)
{
    bool repetidos = false;

    for (int i = 0; i < r.size() && !repetidos; ++i) {
        for (int j = i + 1; j < r.size() && !repetidos; ++j) {
            repetidos = ( r[i].second == r[j].second );
        }
    }

    return true;
}

bool hablantesDeReunionValidos(reunion r, int prof, int freq)
{
    bool res = todosHablantesDistintos(r);

    for (int i = 0; i < r.size() && res; ++i) {
        res = ( 0 <= r[i].second  &&  r[i].second < r.size() );
    }

    return res;
}

bool reunionValida(reunion r, int prof, int freq)
{
    return r.size() > 0  &&  esMatriz(r)  &&  senialesValidas(r, prof, freq)  &&  hablantesDeReunionValidos(r, prof, freq);
}


/************ acelerar *************/
void acelerarSenial(senial &s, int prof, int freq)
{
    for (int i = 0; i < s.size(); ++i) {
        s.erase(s.begin() + i);
    }
}


/*********** ralentizar ************/
void ralentizarSenial(senial &s, int prof, int freq)
{
    int longFinal = 2 * s.size() - 1;
    senial salida(longFinal, 0);

    for (int i = 0; i < salida.size(); ++i) {
        int valor;
        if (i % 2 == 0) {
            salida[i] = s[i / 2];
        } else {
            salida[i] = (s[i / 2] + s[i / 2 + 1]) / 2;
        }
    }

    s = salida;
}


/********* tonosDeVozElevados ******/
vector<hablante> hablantesConTonosElevados(reunion r, int freq, int prof)
{
    vector<hablante> hablantes = { };
    float mayorTono = 0;

    for (int i = 0; i < r.size(); ++i) {
        float iesimoTono = tono(r[i].first);

        if (iesimoTono > mayorTono) {
            mayorTono = iesimoTono;
            hablantes = { r[i].second };
        }
        if (iesimoTono == mayorTono) {
            hablantes.push_back(r[i].second);
        }
    }

    return hablantes;
}


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


/************* silencios *************/
bool superaUmbral(int valor, int umbral)
{
    return abs(valor) >= umbral;
}

void actualizarIndicesYFlags(int &inicioSilencio, int indiceActual, bool &outCandidatoSilencio, bool &outEsSilencio, int freq)
{
    if ( !outCandidatoSilencio ) {
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

        if ( !superaUmbral(s[i], umbral) ) {
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




/************* Ejercicio 4 *************/

senial leerSenial(string nombreArchivo)
{
    senial s(0);
    string StringDeLaSenial;
    ifstream inputArchivo;
    char buf[100];
    int numeroDeSenial = 0;

    strncpy(buf, nombreArchivo.c_str(), 100);
    inputArchivo.open(buf, ios_base::in);
    if (inputArchivo.is_open() == false) {
        return s;
    }

    getline(inputArchivo, StringDeLaSenial);

    for (int k = 0; k < StringDeLaSenial.size(); k++) {

        if (StringDeLaSenial[k] != ' ') {
            numeroDeSenial *= 10;
            numeroDeSenial += StringDeLaSenial[k] - '0';
        }
        else {
            s.push_back(numeroDeSenial);
            numeroDeSenial = 0;
        }
    }

    inputArchivo.close();
    return s;
}

void escribirSenial(senial s, string nombreArchivo)
{
    ofstream outputArchivo;
    char buf[100];

    strncpy(buf, nombreArchivo.c_str(), 100);
    outputArchivo.open(buf, ios_base::app);
    if ( !outputArchivo.is_open() ) {
        return;
    }

    for (int k = 0; k < s.size(); k++) {
        outputArchivo << s[k] << ' ';
    }

    outputArchivo.close();
}

/************* Ejercicio 4 *************/


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
