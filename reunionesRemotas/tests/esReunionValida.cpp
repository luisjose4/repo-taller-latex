#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(esReunionValidaTEST, reunionValida){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, reunionValidaDeUnSoloHablante){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante1, 0)};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, reunionVacia){
    reunion reunion = {};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, noEsMatriz){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 4, 1, -4};
    senial hablante2 = {0, 1, 4, 6, 0, -2, 3, -3, 4, -9, 5};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, hablanteConSenialNoValida){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante2 = {-2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, hablantesRepetidos){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante3 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 0)};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, hablanteConNumeroFueraDeRango){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante3 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante1, 5), make_pair(hablante2, 1), make_pair(hablante3, 0)};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}


