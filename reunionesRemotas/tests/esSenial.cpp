#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(esSenialTEST, frecuenciaValida){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, frecuenciaInvalida){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 25;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, frecuenciaNegativa){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = -10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, frecuenciaIgualACero){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 0;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, muestrasEnRango){
    senial s = {1,3,-3,127,6,0,-128,-8,9,-15,7};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, muestrasNoEnRango1){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,145};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, muestrasNoEnRango2){
    senial s = {1,3,-313,4,6,0,-2,-8,9,-223,145};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, profundidadValida1){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, profundidadValida2){
    senial s = { 1, 3, -3, 4, 6, 32000, -2, -8, 9, -15, 7 };
    int prof = 16;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, profundidadValida3){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 32;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, profundidadValida4)
{
    senial s = { 1, 3, -3, 4, 6, 0, -2, -8, 70000, -15, 7 };
    int prof = 32;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, profundidadInvalida){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 3;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, profundidadInvalida2)
{
    senial s = { 1, 3, -3, 4, 6, 0, -2, -8, 70000, -15, 7 };
    int prof = 16;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, profundidadInvalidaNegativa){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = -8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, profundidadIgualACero){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 0;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, duracionValida){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, duracionBorde){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, duracionInvalida){
    senial s = {1,3,-3,4,6,0,-2,-8};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, secuenciaVacia){
    senial s = { };
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, secuenciaDeSolo1Elemento){
    senial s = { 7 };
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}
