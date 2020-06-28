#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(filtradoMedianaTEST, filtradoMedianaValidos){
    senial hablante = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};

    int prof = 8;
    int freq = 10;
    int R = 4;

    senial hablanteResultante = {1, 3, -3, 4, 1, 0, -2, -8, 9, -15};

    filtradoMediana(hablante, R, prof, freq);

    ASSERT_SENIAL_EQ(hablante, hablanteResultante);
}

TEST(filtradoMedianaTEST, filtradoMedianaListaOrdenada){
    senial hablante = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int prof = 8;
    int freq = 10;
    int R = 2;

    senial hablanteResultante = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    filtradoMediana(hablante, R, prof, freq);

    ASSERT_SENIAL_EQ(hablante, hablanteResultante);
}

TEST(filtradoMedianaTEST, filtradoMedianaRigualDos){
    senial hablante = {6, 1, -4, 0, 8, -10, 5, -7, 8, 9};

    int prof = 8;
    int freq = 10;
    int R = 2;

    senial hablanteResultante = {6, 1, 1, 0, 0, 0, 5, 5, 8, 9};

    filtradoMediana(hablante, R, prof, freq);

    ASSERT_SENIAL_EQ(hablante, hablanteResultante);
}