#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(acelerarTEST, aceleracionValidaSenialesLongitudImpar){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {3, 4, 0, -8, -15, 1, -3, 6, -2, 9};
    senial hablante2Acelerado = {3, 4, 0, -8, -15, 1, -3, 6, -2, 9};
    reunion reunionAcelerada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}

TEST(acelerarTEST, aceleracionValidaSenialesLongitudPar){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 0};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 0};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {3, 4, 0, -8, -15, 1, -3, 6, -2, 9, 0};
    senial hablante2Acelerado = {3, 4, 0, -8, -15, 1, -3, 6, -2, 9, 0};
    reunion reunionAcelerada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}

TEST(acelerarTEST, aceleracionValida1)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    senial hablante2 = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    senial hablante3 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    senial hablante4 = { -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1 };
    reunion reunionOriginal = { make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2), make_pair(hablante4, 3) };
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = { 2, 4, 6, 8, 10, 2, 4, 6, 8, 10 };
    senial hablante2Acelerado = { 3, 5, 7, 9, 11, 3, 5, 7, 9, 11 };
    senial hablante3Acelerado = { 9, 7, 5, 3, 1, 9, 7, 5, 3, 1 };
    senial hablante4Acelerado = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    reunion reunionAcelerada = { make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1), make_pair(hablante3Acelerado, 2), make_pair(
            hablante4Acelerado, 3) };

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}

TEST(acelerarTEST, aceleracionValida2)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    reunion reunionOriginal = { make_pair(hablante1, 0) };
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = { 2, 4, 6, 8, 10, 9, 7, 5, 3, 1 };
    reunion reunionAcelerada = { make_pair(hablante1Acelerado, 0) };

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}

TEST(acelerarTEST, aceleracionValida3)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 30 };
    reunion reunionOriginal = { make_pair(hablante1, 0) };
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = { 2, 4, 6, 8, 10, 9, 7, 5, 3, 1 };
    reunion reunionAcelerada = { make_pair(hablante1Acelerado, 0) };

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}

TEST(acelerarTEST, aceleracionValida4)
{
    senial hablante1 = { 1, -2, 3, 4, 5, -6, 7, 8, 9, -10, 10, 9, 8, -7, 6, 5, 4, -3, 2, 1, 30 };
    reunion reunionOriginal = { make_pair(hablante1, 0) };
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = { -2, 4, -6, 8, -10, 9, -7, 5, -3, 1 };
    reunion reunionAcelerada = { make_pair(hablante1Acelerado, 0) };

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}

TEST(acelerarTEST, aceleracionValida5)
{
    senial hablante1 = { 1, -2, 3, 4, 5, -6, 7, 8, 9, -10, 10, 9, 8, -7, 6, 5, 4, -3, 2, 1, 30 };
    senial hablante2 = { 1, 10, 3, 4, 5, -6, 7, 8, 9, -10, 10, 9, 8, -7, 6, 5, 4, -3, 2, 1, 30 };
    reunion reunionOriginal = { make_pair(hablante1, 0), make_pair(hablante1, 1) };
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = { -2, 4, -6, 8, -10, 9, -7, 5, -3, 1 };
    senial hablante2Acelerado = { 10, 4, -6, 8, -10, 9, -7, 5, -3, 1 };
    reunion reunionAcelerada = { make_pair(hablante1Acelerado, 0), make_pair(hablante1Acelerado, 1) };

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}

TEST(acelerarTEST, aceleracionValida6)
{
    senial hablante1 = { 1, -2, 3, 4, 5, -6, 7, 8, 9, -10, 10, 9, 8, -7, 6, 5, 4, -3, 2, 1, 30 };
    senial hablante2 = { 1, 10, 3, 4, 5, -6, 7, 8, 9, -10, 10, 9, 8, -7, 6, 5, 4, -3, 2, 1, 30 };
    senial hablante3 = { 1, 15, 3, 4, 5, -6, 7, 8, 9, -10, 10, 9, 8, -7, 6, 5, 4, -3, 2, 1, 30 };
    senial hablante4 = { 1, 40, 3, 4, 5, -6, 7, 8, 9, -10, 10, 9, 8, -7, 6, 5, 4, -3, 2, 1, 30 };
    reunion reunionOriginal = { make_pair(hablante1, 2), make_pair(hablante2, 3), make_pair(hablante3, 0), make_pair(hablante4, 1) };
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = { -2, 4, -6, 8, -10, 9, -7, 5, -3, 1 };
    senial hablante2Acelerado = { 10, 4, -6, 8, -10, 9, -7, 5, -3, 1 };
    senial hablante3Acelerado = { 15, 4, -6, 8, -10, 9, -7, 5, -3, 1 };
    senial hablante4Acelerado = { 40, 4, -6, 8, -10, 9, -7, 5, -3, 1 };
    reunion reunionAcelerada = { make_pair(hablante1Acelerado, 2), make_pair(hablante2Acelerado, 3), make_pair(hablante3Acelerado, 0), make_pair(
            hablante4Acelerado, 1) };

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}
