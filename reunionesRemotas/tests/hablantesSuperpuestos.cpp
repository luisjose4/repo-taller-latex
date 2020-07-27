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

TEST(hablantesSuperpuestosTEST, noHayHablantesSuperpuestos)
{
    senial hablante1 = { 1, 3, -3, 4, 6, 0, -2, -8, 9, -15 };
    senial hablante2 = { 2, 6, 3, 8, 6, 10, 2, 12, 10, -15 };
    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1) };
    int prof = 8;
    int freq = 10;
    int umbral = 20;

    EXPECT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestosAlFinalEigualAlUmbral)
{
    senial hablante1 = { 1, 3, -3, 4, 6, 0, -2, -8, 9, -20 };
    senial hablante2 = { 2, 6, 3, 8, 6, 10, 2, 12, 10, 20 };
    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1) };
    int prof = 8;
    int freq = 10;
    int umbral = 20;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestosAlFinal)
{
    senial hablante1 = { 1, 3, -3, 4, 6, 0, -2, -8, 9, -21 };
    senial hablante2 = { 2, 6, 3, 8, 6, 10, 2, 12, 10, 4 };
    senial hablante3 = { 2, 6, 3, 8, 6, 10, 2, 12, 20, -2 };
    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2) };
    int prof = 8;
    int freq = 10;
    int umbral = 20;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, noHablantesSuperpuestosAlFinalPeroSuperanElUmbral)
{
    senial hablante1 = { 11, 3, -3, 12, 6, 0, 11, -8, 9, 2 };
    senial hablante2 = { 2, 11, 3, 8, 13, 1, 2, 9, 11, 4 };
    senial hablante3 = { 2, 6, 11, 8, 6, 13, 2, 8, 3, -21 };
    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2) };
    int prof = 8;
    int freq = 10;
    int umbral = 10;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, noHablantesSuperpuestos1)
{
    senial hablante1 = { 11, 3, -3, 12,  6,  0, 11, -8,  9,  2 };
    senial hablante2 = {  2, 1, 11,  8,  3,  1,  2,  9, 11,  4 };
    senial hablante3 = {  2, 6, -9,  8, 16, 13,  2,  8,  3, -1 };
    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2) };
    int prof = 8;
    int freq = 10;
    int umbral = 10;

    ASSERT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestos1)
{
    senial hablante1 = { 11, 13, -3, 12,  6,  0, 11, -8,  9,   2 };
    senial hablante2 = {  2,  1, 11,  8,  3,  1,  2,  9, 11,   4 };
    senial hablante3 = {  2,  6, -9,  8, 16, 13,  2,  8,  3, -21 };
    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2) };
    int prof = 8;
    int freq = 10;
    int umbral = 10;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestos2)
{
    senial hablante1 = {   1, 13, -3, 12,  6,  0, 11, -8,  9,   2 };
    senial hablante2 = {  12,  1,  0,  8,  3,  1,  2,  9, 11,   4 };
    senial hablante3 = {   2,  6, -9,  8, 16, 13,  2,  8,  3, -21 };
    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2) };
    int prof = 8;
    int freq = 10;
    int umbral = 10;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}