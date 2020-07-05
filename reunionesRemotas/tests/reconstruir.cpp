#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(reconstruirTEST, reconstruirValidos){
    senial hablante1 = { 1, 3, -3, 4, 6, 0, 0, -8, 0, -15 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 1, 3, -3, 4, 6, -1, -1, -8, -12, -15 };

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

    senial hablante1Reconstruido = { 1, 0, -3, 4, 6, -1, -1, -8, -12, -15 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, reconstruirValidos2)
{
    senial hablante1 = { 1, 0, -3, 4, 0, -5, 0, 6, 0, 5, 0, -8, 0, -8 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 1, 0, -3, 4, 0, -5, 0, 6, 5, 5, 0, -8, -8, -8 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, reconstruirValidos3)
{
    senial hablante1 = { 5, 7, 9, -6, 0, 0, -2, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 5 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 5, 7, 9, -6, -4, -4, -2, 0, 0, 0, 0, 2, 2, 2, 3, 3, 3, 3, 5 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, reconstruirValidos4)
{
    senial hablante1 = { 5, 0, 0, 5, -2, 0, 0, 10, 2, 2, 0, 0, -5 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 5, 5, 5, 5, -2, 4, 4, 10, 2, 2, -2, -2, -5 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, reconstruirValidos5)
{
    senial hablante1 = { 5, 0, 0, 5, -5, 0, 0, 7, 5, 5, 0, 0, -5 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 5, 5, 5, 5, -5, 1, 1, 7, 5, 5, 0, 0, -5 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, reconstruirValidos6)
{
    senial hablante1 = { 5, 7, 9, -6, 0, -2, -2, 0, 0, 10, 0, 2, 0, 2, 0, 0, -5, 0, 5 };
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = { 5, 7, 9, -6, -4, -2, -2, 4, 4, 10, 6, 2, 2, 2, -2, -2, -5, 0, 5 };

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

