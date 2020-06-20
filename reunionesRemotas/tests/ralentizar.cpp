#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(ralentizarTEST, ralentizacionValidaSenialesLongitudPar){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15};
    senial hablante2Acelerado = {1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15};
    reunion reunionRalentizada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizacionValidaSenialesLongitudImpar){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 25};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 25};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15, 5, 25};
    senial hablante2Acelerado = {1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15, 5, 25};
    reunion reunionRalentizada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizacionValidaSenialesDistintas){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {1, 5, -5, 15, 11, 7, -1, -8, -4, -1, 3};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15};
    senial hablante2Acelerado = {1, 3, 5, 0, -5, 5, 15, 13, 11, 9, 7, 3, -1, -4, -8, -6, -4, -2, -1, 1, 3};
    reunion reunionRalentizada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}
