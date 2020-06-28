#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(reconstruirTEST, reconstruirValidos){
    senial hablante1 = { 1, 3, -3, 4, 6, 0, 0, -8, 0, -15 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 1, 3, -3, 4, 6, -1, -1, -8, -11, -15 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, reconstruirSenialSinCeros)
{
    senial hablante1 = { 1, 3, -3, 4, 6, 2, 1, -8, 9, -15 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 1, 3, -3, 4, 6, 2, 1, -8, 9, -15 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, reconstruirSenialConDistanciaCinco)
{
    senial hablante1 = { 6, 0, 0, 0, 0, -8, 0, 0, 0, 0, 6 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 6, -1, -1, -1, -1, -8, -1, -1, -1, -1, 6 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, reconstruirValidosConPasajePorCero)
{
    senial hablante1 = { 1, 0, -3, 4, 6, 0, 0, -8, 0, -15 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 1, 0, -3, 4, 6, -1, -1, -8, -11, -15 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}
