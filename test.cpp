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

TEST_CASE("Subtraction") {
    mat::SquareMat a(2), b(2);

    a[0][0] = 5; a[0][1] = 7;
    a[1][0] = 9; a[1][1] = 11;

    b[0][0] = 1; b[0][1] = 2;
    b[1][0] = 3; b[1][1] = 4;

    mat::SquareMat c = a - b;

    CHECK(c[0][0] == 4);
    CHECK(c[1][1] == 7);
}

TEST_CASE("Unary minus") {
    mat::SquareMat a(2);
    a[0][0] = 1;
    a[0][1] = -2;
    a[1][0] = 3;
    a[1][1] = -4;

    mat::SquareMat b = -a;

    CHECK(b[0][0] == -1);
    CHECK(b[0][1] == 2);
    CHECK(b[1][0] == -3);
    CHECK(b[1][1] == 4);
}

TEST_CASE("Matrix multiplication") {
    mat::SquareMat a(2), b(2);

    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    mat::SquareMat c = a * b;

    CHECK(c[0][0] == 19);  // 1*5 + 2*7
    CHECK(c[0][1] == 22);  // 1*6 + 2*8
    CHECK(c[1][0] == 43);  // 3*5 + 4*7
    CHECK(c[1][1] == 50);  // 3*6 + 4*8
}

TEST_CASE("Scalar multiplication (matrix * scalar)") {
    mat::SquareMat a(2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    mat::SquareMat b = a * 2.0;

    CHECK(b[0][0] == 2);
    CHECK(b[0][1] == 4);
    CHECK(b[1][0] == 6);
    CHECK(b[1][1] == 8);
}

TEST_CASE("Scalar multiplication (scalar * matrix)") {
    mat::SquareMat a(2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    mat::SquareMat b = 3.0 * a;

    CHECK(b[0][0] == 3);
    CHECK(b[0][1] == 6);
    CHECK(b[1][0] == 9);
    CHECK(b[1][1] == 12);
}

TEST_CASE("Element-wise multiplication with %") {
    mat::SquareMat a(2), b(2);

    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    mat::SquareMat c = a % b;

    CHECK(c[0][0] == 5);   // 1*5
    CHECK(c[0][1] == 12);  // 2*6
    CHECK(c[1][0] == 21);  // 3*7
    CHECK(c[1][1] == 32);  // 4*8
}

TEST_CASE("Matrix % scalar") {
    mat::SquareMat a(2);
    a[0][0] = 5.5;
    a[0][1] = 8.2;
    a[1][0] = 13;
    a[1][1] = 4;

    mat::SquareMat b = a % 5;

    CHECK(b[0][0] == 0);  // 5 % 5
    CHECK(b[0][1] == 3);  // 8 % 5
    CHECK(b[1][0] == 3);  // 13 % 5
    CHECK(b[1][1] == 4);  // 4 % 5
}

TEST_CASE("Matrix / scalar") {
    mat::SquareMat a(2);
    a[0][0] = 4;
    a[0][1] = 8;
    a[1][0] = 10;
    a[1][1] = 12;

    mat::SquareMat b = a / 2.0;

    CHECK(b[0][0] == doctest::Approx(2.0));
    CHECK(b[0][1] == doctest::Approx(4.0));
    CHECK(b[1][0] == doctest::Approx(5.0));
    CHECK(b[1][1] == doctest::Approx(6.0));
}

TEST_CASE("Matrix exponentiation") {
    mat::SquareMat a(2);
    a[0][0] = 2; a[0][1] = 0;
    a[1][0] = 0; a[1][1] = 2;

    // a^0 should return identity
    mat::SquareMat id = a ^ 0;
    CHECK(id[0][0] == doctest::Approx(1.0));
    CHECK(id[0][1] == doctest::Approx(0.0));
    CHECK(id[1][0] == doctest::Approx(0.0));
    CHECK(id[1][1] == doctest::Approx(1.0));

    // a^1 should be same as a
    mat::SquareMat pow1 = a ^ 1;
    CHECK(pow1[0][0] == doctest::Approx(2.0));
    CHECK(pow1[1][1] == doctest::Approx(2.0));

    // a^3 should be each element to power 3 (because matrix is diagonal)
    mat::SquareMat pow3 = a ^ 3;
    CHECK(pow3[0][0] == doctest::Approx(8.0));
    CHECK(pow3[1][1] == doctest::Approx(8.0));
}

TEST_CASE("Prefix ++ and --") {
    mat::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    ++a;
    CHECK(a[0][0] == 2);
    CHECK(a[1][1] == 5);

    --a;
    CHECK(a[0][0] == 1);
    CHECK(a[1][1] == 4);
}

TEST_CASE("Postfix ++ and --") {
    mat::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    mat::SquareMat b = a++;  // b = before, a = after
    CHECK(b[0][0] == 1);
    CHECK(a[0][0] == 2);

    mat::SquareMat c = a--;  // c = before, a = after
    CHECK(c[1][1] == 5);
    CHECK(a[1][1] == 4);
}

TEST_CASE("Transpose with ~") {
    mat::SquareMat a(2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    mat::SquareMat t = ~a;

    CHECK(t[0][0] == 1);
    CHECK(t[0][1] == 3);
    CHECK(t[1][0] == 2);
    CHECK(t[1][1] == 4);
}

TEST_CASE("Comparison operators based on sum") {
    mat::SquareMat a(2), b(2), c(2);

    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 1;  // sum = 4

    b[0][0] = 2; b[0][1] = 2;
    b[1][0] = 2; b[1][1] = 2;  // sum = 8

    c[0][0] = 1; c[0][1] = 1;
    c[1][0] = 1; c[1][1] = 1;  // sum = 4

    CHECK(a < b);
    CHECK(b > a);
    CHECK(a <= c);
    CHECK(a == c);
    CHECK(a != b);
    CHECK(b >= c);
}

TEST_CASE("Determinant !mat") {
    mat::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    CHECK(!a == doctest::Approx(-2));

    mat::SquareMat b(3);
    b[0][0] = 6; b[0][1] = 1; b[0][2] = 1;
    b[1][0] = 4; b[1][1] = -2; b[1][2] = 5;
    b[2][0] = 2; b[2][1] = 8; b[2][2] = 7;

    CHECK(!b == doctest::Approx(-306));
}


