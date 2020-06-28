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

    senial hablante1Ralentizado = { 1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15 };
    senial hablante2Ralentizado = { 1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15 };
    reunion reunionRalentizada = { make_pair(hablante1Ralentizado, 0), make_pair(hablante2Ralentizado, 1) };

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizacionValidaSenialesLongitudImpar){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 25};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 25};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Ralentizado = { 1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15, 5, 25 };
    senial hablante2Ralentizado = { 1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15, 5, 25 };
    reunion reunionRalentizada = { make_pair(hablante1Ralentizado, 0), make_pair(hablante2Ralentizado, 1) };

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizacionValidaSenialesDistintas){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {1, 5, -5, 15, 11, 7, -1, -8, -4, -1, 3};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Ralentizado = { 1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15 };
    senial hablante2Ralentizado = { 1, 3, 5, 0, -5, 5, 15, 13, 11, 9, 7, 3, -1, -4, -8, -6, -4, -2, -1, 1, 3 };
    reunion reunionRalentizada = { make_pair(hablante1Ralentizado, 0), make_pair(hablante2Ralentizado, 1) };

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizacionValida)
{
    senial hablante1 = { 1, 4, -3, 0, 6, 0, -4, 55, 9, -15 };
    senial hablante2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    senial hablante3 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    senial hablante4 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    reunion reunionOriginal = { make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2), make_pair(hablante4, 3) };
    int prof = 8;
    int freq = 10;

    senial hablante1Ralentizado = { 1, 2, 4, 0, -3, -1, 0, 3, 6, 3, 0, -2, -4, 25, 55, 32, 9, -3, -15 };
    senial hablante2Ralentizado = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10 };
    senial hablante3Ralentizado = { 10, 9, 9, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1 };
    senial hablante4Ralentizado(19, 1);
    reunion reunionRalentizada = { make_pair(hablante1Ralentizado, 0), make_pair(hablante2Ralentizado, 1), make_pair(hablante3Ralentizado, 2),
            make_pair(hablante4Ralentizado, 3) };

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizacionValida2)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    reunion reunionOriginal = { make_pair(hablante1, 0) };
    int prof = 8;
    int freq = 10;

    senial hablante1Ralentizado = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12 };
    reunion reunionRalentizada = { make_pair(hablante1Ralentizado, 0) };

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizacionValida3)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    reunion reunionOriginal = { make_pair(hablante1, 0), make_pair(hablante1, 1) };
    int prof = 8;
    int freq = 10;

    senial hablante1Ralentizado = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12 };
    reunion reunionRalentizada = { make_pair(hablante1Ralentizado, 0), make_pair(hablante1Ralentizado, 1) };

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizacionValida4)
{
    senial hablante1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    reunion reunionOriginal = { make_pair(hablante1, 1), make_pair(hablante1, 0) };
    int prof = 8;
    int freq = 10;

    senial hablante1Ralentizado = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12 };
    reunion reunionRalentizada = { make_pair(hablante1Ralentizado, 1), make_pair(hablante1Ralentizado, 0) };

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}
