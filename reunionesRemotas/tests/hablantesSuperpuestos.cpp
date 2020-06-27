#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestosValidos){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {2, 6, 3, 8, 6, 10, 2, 12, 10, -15};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST,  noHayHablantesSuperpuestos){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {2, 6, 3, 8, 6, 10, 2, 12, 10, -15};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;
    int umbral = 20;

    EXPECT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestosAlFinalEigualAlUmbral){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -20};
    senial hablante2 = {2, 6, 3, 8, 6, 10, 2, 12, 10, 20};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;
    int umbral = 20;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestosAlFinal){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -21};
    senial hablante2 = {2, 6, 3, 8, 6, 10, 2, 12, 10, -21};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;
    int umbral = 20;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}