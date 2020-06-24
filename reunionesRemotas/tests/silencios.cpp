#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(silenciosTEST, silenciosValidos){
    senial hablante = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    vector<intervalo> intervalos = { make_pair(5, 6) };

    vector<intervalo> a = silencios(hablante, prof, freq, umbral);

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

TEST(silenciosTEST, silenciosValidos2)
{
    senial hablante = { -1, 4, -1, -1, 0, -3, 0, -3, -5, -2, -4, -5, 3, 2, -4 };
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    vector<intervalo> intervalos = { make_pair(2, 4) };

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

TEST(silenciosTEST, silenciosValidos3)
{
    senial hablante = { 4, 2, -4, 3, 0, -1, 4, -4, -4, 0, 3, 2, 4, 0, -4 };
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    vector<intervalo> intervalos = { make_pair(4, 5) };

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

TEST(silenciosTEST, silenciosValidos4)
{
    senial hablante = { 0, 2, -4, 3, 0, -1, 4, 0, 2, 0, -1, 2, 4, 0, -4 };
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    vector<intervalo> intervalos = { make_pair(0, 1), make_pair(4, 5), make_pair(7, 11) };

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

TEST(silenciosTEST, silenciosValidos5)
{
    senial hablante = { 0, 2, -4, 3, 0, -1, 4, 0, 2, 0, -1, 2, 0, 0, 0 };
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    vector<intervalo> intervalos = { make_pair(0, 1), make_pair(4, 5), make_pair(7, 14) };

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

