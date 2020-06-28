#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(ordenarTEST, ordenarValido)
{
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {2, 6, 3, 8, 6, 10, 2, 12, 10, -15};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    reunion reunionOrdenada = {make_pair(hablante2, 1), make_pair(hablante1, 0)};

    ordenar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionOrdenada);
}

TEST(ordenarTEST, ordenarValido2)
{
    senial hablante = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    reunion reunionOriginal = { make_pair(hablante, 0) };
    int prof = 32;
    int freq = 10;

    reunion reunionOrdenada = { make_pair(hablante, 0) };

    ordenar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionOrdenada);
}

TEST(ordenarTEST, ordenarValido3)
{
    senial hablante = { };
    reunion reunionOriginal = { make_pair(hablante, 0) };
    int prof = 32;
    int freq = 10;

    reunion reunionOrdenada = { make_pair(hablante, 0) };

    ordenar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionOrdenada);
}

TEST(ordenarTEST, ordenarValido4)
{
    senial hablante1 = { 5, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    senial hablante2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    reunion reunionOriginal = { make_pair(hablante1, 0), make_pair(hablante2, 1) };
    int prof = 32;
    int freq = 10;

    reunion reunionOrdenada = { make_pair(hablante1, 0), make_pair(hablante2, 1) };

    ordenar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionOrdenada);
}

TEST(ordenarTEST, ordenarValido5)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    senial hablante2 = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    senial hablante3 = { 10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    senial hablante4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    senial hablante5 = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    senial hablante6 = { 20, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    senial hablante7 = { 20000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    
    
    reunion reunionOriginal = { make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2), make_pair(hablante4, 3), make_pair(
            hablante5, 4), make_pair(hablante6, 5), make_pair(hablante7, 6), };
    int prof = 32;
    int freq = 10;

    reunion reunionOrdenada = { make_pair(hablante7, 6), make_pair(hablante6, 5), make_pair(hablante5, 4), make_pair(hablante1, 0), make_pair(
            hablante4, 3), make_pair(hablante3, 2), make_pair(hablante2, 1), };

    ordenar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionOrdenada);
}

TEST(ordenarTEST, ordenarValido6)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    senial hablante2 = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    senial hablante3 = { 10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    senial hablante4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    senial hablante5 = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    senial hablante6 = { 20, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    senial hablante7 = { 20000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    reunion reunionOriginal = { make_pair(hablante1, 0), make_pair(hablante5, 4), make_pair(hablante7, 6), make_pair(hablante4, 3), make_pair(
            hablante6, 5), make_pair(hablante2, 1), make_pair(hablante3, 2), };
    int prof = 32;
    int freq = 10;

    reunion reunionOrdenada = { make_pair(hablante7, 6), make_pair(hablante6, 5), make_pair(hablante5, 4), make_pair(hablante1, 0), make_pair(
            hablante4, 3), make_pair(hablante3, 2), make_pair(hablante2, 1), };

    ordenar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionOrdenada);
}

TEST(ordenarTEST, ordenarValido7)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    senial hablante2 = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    senial hablante3 = { 10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    senial hablante4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    senial hablante5 = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    senial hablante6 = { 20, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    senial hablante7 = { 20000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    senial hablante8 = { 20000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    reunion reunionOriginal = { make_pair(hablante1, 0), make_pair(hablante5, 4), make_pair(hablante7, 6), make_pair(hablante4, 3), make_pair(
            hablante6, 5), make_pair(hablante2, 1), make_pair(hablante3, 2), make_pair(hablante8, 7) };
    int prof = 32;
    int freq = 10;

    reunion reunionOrdenada = { make_pair(hablante7, 6), make_pair(hablante8, 7), make_pair(hablante6, 5), make_pair(hablante5, 4), make_pair(
            hablante1, 0), make_pair(hablante4, 3), make_pair(hablante3, 2), make_pair(hablante2, 1), };

    ordenar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionOrdenada);
}

TEST(ordenarTEST, ordenarValido8)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    senial hablante2 = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    senial hablante3 = { 10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    senial hablante4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    senial hablante5 = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    senial hablante6 = { 20, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    senial hablante7 = { 20000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    senial hablante8 = { 20000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    reunion reunionOriginal = { make_pair(hablante1, 0), make_pair(hablante5, 4), make_pair(hablante7, 6), make_pair(hablante4, 3), make_pair(
            hablante6, 5), make_pair(hablante3, 2), make_pair(hablante2, 1), make_pair(hablante8, 7) };
    int prof = 32;
    int freq = 10;

    reunion reunionOrdenada = { make_pair(hablante7, 6), make_pair(hablante8, 7), make_pair(hablante6, 5), make_pair(hablante5, 4), make_pair(
            hablante1, 0), make_pair(hablante4, 3), make_pair(hablante3, 2), make_pair(hablante2, 1), };

    ordenar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionOrdenada);
}
