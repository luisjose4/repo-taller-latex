#include "../lib/gtest.h"
#include "definiciones.h"
#include "auxiliares.h"
#include <fstream>


senial subSeq(senial s, int i, int r)
{
    senial w;
    for (int j = i; j < r; ++j) {
        w.push_back(s[j]);
    }
    return w;
}


/************* esSenial *************/
bool freqValida(int freq)
{
    return freq == 10;
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

bool esValida(vector<int> s, int prof, int freq){
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


/************ esReunionValida ******/
bool esMatriz(reunion r)
{
    bool res = true;
    senial senialModelo = r[0].first;

    for (int i = 1; i < r.size() && res; ++i) {
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
    bool res = true;

    for (int i = 0; i < r.size() && res; ++i) {
        for (int j = i + 1; j < r.size() && res; ++j) {
            res = ( r[i].second != r[j].second );
        }
    }

    return res;
}

bool hablantesDeReunionValidos(reunion r, int prof, int freq)
{
    bool res = todosHablantesDistintos(r);

    for (int i = 0; i < r.size() && res; ++i) {
        res = ( 0 <= r[i].second  &&  r[i].second < r.size() );
    }

    return res;
}


/************ acelerar *************/
void acelerarSenial(senial &s, int prof, int freq)
{
    senial salida;
    for (int i = 1; i < s.size(); i = i+2) {
        salida.push_back(s[i]);
    }
    s = salida;
}


/*********** ralentizar ************/
void ralentizarSenial(senial &s, int prof, int freq)
{
    int longFinal = 2 * s.size() - 1;
    senial salida(longFinal, 0);

    for (int i = 0; i < salida.size(); ++i) {
        if (i % 2 == 0) {
            salida[i] = s[i / 2];
        } else {
            salida[i] = (s[(i - 1) / 2] + s[(i + 1) / 2]) / 2;
        }
    }

    s = salida;
}


/********* tonosDeVozElevados ******/
// Sin auxiliares


/************* ordenar *************/
void swapPorTono(reunion &reunion, int i, int j)
{
    pair<senial, hablante> k = reunion[i];
    reunion[i] = reunion[j];
    reunion[j] = k;
}


/************* silencios *************/
bool superaUmbral(int valor, int umbral)
{
    return abs(valor) >= umbral;
}

void actualizarIndicesYFlags(int &outInicioSilencio, int indiceActual, bool &outCandidatoSilencio, bool &outEsSilencio, int freq)
{
    if ( !outCandidatoSilencio ) {
        outInicioSilencio = indiceActual;
    }

    outCandidatoSilencio = true;

    if (indiceActual - outInicioSilencio + 1 >= freq * 0.2) {
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


/****** hablantesSuperpuestos ********/
int valorAbsoluto(int x)
{
    return (x < 0) ? (-x) : x;
}

bool estaHablando(senial s, int pos, int umbral)
{
    bool superaUmbral = valorAbsoluto( s[pos] )  >= umbral;
    bool algunoConsecutivoSuperaUmbral;
    if ( pos == 0 ) {
        algunoConsecutivoSuperaUmbral = (valorAbsoluto(s[pos + 1]) >= umbral);
    } else if ( pos == s.size() - 1 ) {
        algunoConsecutivoSuperaUmbral = (valorAbsoluto(s[pos - 1]) >= umbral);
    } else {
        algunoConsecutivoSuperaUmbral = ( valorAbsoluto( s[pos - 1] ) >= umbral && ( valorAbsoluto( s[pos + 1] ) >= umbral ) );
    }
    return ( superaUmbral || algunoConsecutivoSuperaUmbral );
}


/*********** reconstruir *************/
int valor(vector<int> s, int i)
{
    int m = 0;
    int n = 0;
    for (int j = i - 1; j != 0 && n == 0; --j) {
        if (s[j] != 0) {
            n = j;
        }
    }
    for (int k = i + 1; k != s.size() && m == 0; ++k) {
        if (s[k] != 0) {
            m = k;
        }
    }

    return (s[n] + s[m]) / 2;
}

int signo(int k)
{
    if (k > 0) {
        return 1;
    } else if (k < 0) {
        return -1;
    } else {
        return 0;
    }
}

bool esPasajePorCero(vector<int> s, int i)
{
    return signo(s[i - 1]) * signo(s[i + 1]) == -1;
}


/********* filtradoMediana **********/
bool coincidenExtremos(senial s, int i, int r)
{
    return i < r || i >= s.size() - r;
}

void swap(senial &lista, int i, int j)
{
    int k = lista[i];
    lista[i] = lista[j];
    lista[j] = k;
}

void insertar(senial &lista, int i)
{
    while (i > 0 && lista[i] < lista[i - 1]) {
        swap(lista, i, i - 1);
        i--;
    }
}

senial insertionSort(senial lista)
{
    for (int i = 0; i < lista.size(); i++) {
        insertar(lista, i);
    }
    return lista;
}

senial ordenarSenialW(senial w)
{
    return insertionSort(w);
}


/************* Ejercicio 4 *************/
senial leerSenial(string nombreArchivo)
{
    senial s(0);
    string StringDeLaSenial;
    ifstream inputArchivo;


    inputArchivo.open(nombreArchivo.c_str(), ios_base::in);
    if (inputArchivo.is_open() == false) {
        return s;
    }

    getline(inputArchivo, StringDeLaSenial);

    for (int k = 0; k < StringDeLaSenial.size(); k++) {

        int numeroDeSenial = 0;

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

    outputArchivo.open(nombreArchivo.c_str(), ios_base::app);
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
