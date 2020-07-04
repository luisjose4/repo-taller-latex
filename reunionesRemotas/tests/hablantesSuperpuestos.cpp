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
    senial hablante3 = { 2, 6, 3, 8, 6, 10, 2, 12, 10, -21 };
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

    ASSERT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestos2)
{
    senial hablante1 = { 9,0,0,0,0,0,9,0,0,0 };
    senial hablante2 = { 0,9,0,0,0,0,0,9,0,0 };
    senial hablante3 = { 0,0,9,0,0,0,0,0,9,0 };
    senial hablante4 = { 0,0,0,9,0,0,0,0,0,9 };
    senial hablante5 = { 0,0,0,0,9,0,0,0,0,0 };
    senial hablante6 = { 0,0,0,0,0,9,0,0,0,0 };

    reunion reunion = { make_pair(hablante1, 0),
                        make_pair(hablante2, 1),
                        make_pair(hablante3, 2),
                        make_pair(hablante4, 3),
                        make_pair(hablante5, 4),
                        make_pair(hablante6, 5),};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestos3)
{
    senial hablante1 = { 9,9,0,0,0,0,9,0,0,0 };
    senial hablante2 = { 0,-9,0,0,0,0,0,9,0,0 };
    senial hablante3 = { 0,0,9,0,0,0,0,0,9,0 };
    senial hablante4 = { 0,0,0,9,0,0,0,0,0,9 };
    senial hablante5 = { 0,0,0,0,9,0,0,0,0,0 };
    senial hablante6 = { 0,0,0,0,0,9,0,0,0,0 };

    reunion reunion = { make_pair(hablante1, 0),
                        make_pair(hablante2, 1),
                        make_pair(hablante3, 2),
                        make_pair(hablante4, 3),
                        make_pair(hablante5, 4),
                        make_pair(hablante6, 5),};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestos4)
{
    senial hablante1 = { 9,0,0,0,0,0,9,0,0,0 };
    senial hablante2 = { 5,-2,3,-4,5,2,2,-10,15,20 };
    senial hablante3 = { 5,10,-6,6,2,3,-5,4,1,2 };
    senial hablante4 = { 2,-3,4,1,-2,3,-5,4,1,2 };
    senial hablante5 = { 3,3,2,1,-70,3,1,2,3,1 };
    senial hablante6 = { 0,0,0,0,0,-9,0,0,0,0 };

    reunion reunion = { make_pair(hablante1, 0),
                        make_pair(hablante2, 1),
                        make_pair(hablante3, 2),
                        make_pair(hablante4, 3),
                        make_pair(hablante5, 4),
                        make_pair(hablante6, 5),};
    int prof = 8;
    int freq = 10;
    int umbral = 6;

    ASSERT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestos5)
{
    senial hablante1 = { 9,0,0,0,0,0,9,0,0,0 };
    senial hablante2 = { 5,2,3,4,5,2,2,10,15,20 };
    senial hablante3 = { 5,10,6,6,2,3,5,4,1,2 };
    senial hablante4 = { 2,3,4,1,2,3,5,4,1,2 };
    senial hablante5 = { 3,3,2,1,70,3,1,2,3,1 };
    senial hablante6 = { 0,0,0,0,-7,9,0,0,0,0 };

    reunion reunion = { make_pair(hablante1, 0),
                        make_pair(hablante2, 1),
                        make_pair(hablante3, 2),
                        make_pair(hablante4, 3),
                        make_pair(hablante5, 4),
                        make_pair(hablante6, 5),};
    int prof = 8;
    int freq = 10;
    int umbral = 6;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}
