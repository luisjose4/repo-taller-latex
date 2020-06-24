#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(tonosDeVozElevadosTEST, tonosDeVozElevadosValido){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {2, 6, 3, 8, 6, 10, 2, 12, 10, -15};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), {1});
}

TEST(tonosDeVozElevadosTEST, tonosDeVozElevadosValido2)
{
    senial hablante1 = { 1, 3, -3, 4, 6, 0, -2, -8, 9, -15 };
    reunion reunion = { make_pair(hablante1, 0) };
    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), { 0 });
}

TEST(tonosDeVozElevadosTEST, tonosDeVozElevadosValido3)
{
    senial hablante1 = { 1, 3, -3, 4, 6, 0, -2, -8, 9, -15 };
    senial hablante2 = { 2, 6, 3, 8, 6, 10, 2, 12, 10, -15 };
    reunion reunion = { make_pair(hablante2, 1), make_pair(hablante1, 0) };
    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), { 1 });
}

TEST(tonosDeVozElevadosTEST, tonosDeVozElevadosValido4)
{
    senial hablante1 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    senial hablante2 = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1) };
    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), { 1 });
}

TEST(tonosDeVozElevadosTEST, tonosDeVozElevadosValido5)
{
    senial hablante1 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    senial hablante2 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1) };
    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), { 0, 1 });
}

TEST(tonosDeVozElevadosTEST, tonosDeVozElevadosValido6)
{
    senial hablante1 = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 6 };
    senial hablante2 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    senial hablante3 = { 1, 1, 1, 1, 5, 1, 1, 1, 1, 1 };
    senial hablante4 = { 1, 1, 1, 5, 1, 1, 1, 1, 1, 1 };
    senial hablante5 = { 2, 2, 2, 2, 1, 1, 1, 1, 1, 1 };

    reunion reunion = { make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2), make_pair(hablante4, 3), make_pair(hablante5, 4), };
    int prof = 8;
    int freq = 10;
    
    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), { 0, 2, 3, 4 });
}

TEST(tonosDeVozElevadosTEST, tonosDeVozElevadosValido7)
{
    senial hablante1 = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 6 };
    senial hablante2 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    senial hablante3 = { 1, 1, 1, 1, 5, 1, 1, 1, 1, 1 };
    senial hablante4 = { 1, 1, 1, 5, 1, 1, 1, 1, 1, 1 };
    senial hablante5 = { 2, 2, 2, 2, 1, 1, 1, 1, 1, 1 };

    reunion reunion = { make_pair(hablante4, 3), make_pair(hablante2, 1), make_pair(hablante5, 4), make_pair(hablante1, 0), make_pair(hablante3, 2), };
    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), { 3, 4, 0, 2 });
}

TEST(tonosDeVozElevadosTEST, tonosDeVozElevadosValido8)
{
    senial hablante1 = { 1, 1, 1, -2, 1, 1, 1, 1, 0, 6 };
    senial hablante2 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    senial hablante3 = { 1, 1, 1, 1, 5, 1, 1, 1, 1, 1 };
    senial hablante4 = { 1, 1, 1, 5, 1, 1, 1, 1, 1, 1 };
    senial hablante5 = { 2, 2, 2, 1, 1, 1, 1, 1, 1, 1 };

    reunion reunion = { make_pair(hablante4, 3), make_pair(hablante2, 1), make_pair(hablante5, 4), make_pair(hablante1, 0), make_pair(hablante3, 2), };
    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), { 0 });
}
