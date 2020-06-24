#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(seEnojoTEST, senialMenorADosSegundos){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialMenorADosSegundosTonoSuperaElUmbral){
    senial s = {11,33,-32,41,66,0,-21,-118,99,-15,7};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialMenorADosSegundosTodosCeros){
    senial s(15,0);
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialMayorADosSegundosTodosCeros){
    senial s(25,0);
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialEnojadaCompleta){
    senial s = {5,5,6,-8,123,14,11,-29,-29,-29,-8,9,-15,7,-12,65,24,34,24,5,5,6,-8,123,14,11,-29,-29,-29,-8,9,-15};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialConTonoIgualAlUmbral){
    senial s(20,-3);
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialConTonoMayorAlUmbral)
{
    senial s(20, -4);
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialConTonoMayorAlUmbra2)
{
    senial s { 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialEnojadaConLongitudBorde)
{
    senial s(19, -5);
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialEnojadaConLongitudMinima){
    senial s(20,-5) ;
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialEnojadaConSubseqMinimaEnojada){
    senial s = {0,0,0,0,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,1,-2,2,1,0,0,3};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialNoEnojadaConTodasMuestrasMenoresAlUmbral){
    senial s(100,-2);
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialEnojadaConMayoriaDeMuestrasIgualesACero){
    senial s = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialEnojadaConMayoriaDeMuestrasBajas)
{
    senial s = { 0, 0, 1, 0, 4, 0, 0, 4, 2, 0, 0, 0, 0, 0, 2, 0, 1, 0, -1, 0, 0, 5, 0, -5, 0, 0, 0, 0, 0 };
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}
