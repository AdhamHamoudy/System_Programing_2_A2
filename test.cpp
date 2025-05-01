#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"


TEST_CASE("Addition") {
    mat::SquareMat a(2);
    mat::SquareMat b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    mat::SquareMat c = a + b;

    CHECK(c[0][0] == 6);
    CHECK(c[1][1] == 12);
}
