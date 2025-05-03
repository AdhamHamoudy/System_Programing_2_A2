#include "SquareMat.hpp"
#include <iostream>

using namespace mat;

int main() {
    std::cout << "====== MATRIX TEST DEMO ======\n";

    SquareMat A(2), B(2);

    // Initialize A
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    // Initialize B
    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;

    std::cout << "\n== Initial Matrices ==\n";
    std::cout << "Matrix A:\n" << A;
    std::cout << "Matrix B:\n" << B;

    std::cout << "\n== Basic Arithmetic ==\n";
    std::cout << "A + B:\n" << (A + B) << "-----\n";
    std::cout << "A - B:\n" << (A - B) << "-----\n";
    std::cout << "-A (unary minus):\n" << (-A) << "-----\n";

    std::cout << "\n== Multiplications ==\n";
    std::cout << "A * B:\n" << (A * B) << "-----\n";
    std::cout << "A * 2:\n" << (A * 2.0) << "-----\n";
    std::cout << "2 * B:\n" << (2.0 * B) << "-----\n";

    std::cout << "\n== Scalar Division and Modulo ==\n";
    std::cout << "A / 2:\n" << (A / 2.0) << "-----\n";
    std::cout << "A % B (element-wise):\n" << (A % B) << "-----\n";
    std::cout << "B % 3 (scalar modulo):\n" << (B % 3) << "-----\n";

    std::cout << "\n== Exponentiation ==\n";
    std::cout << "A ^ 2:\n" << (A ^ 2) << "-----\n";

    std::cout << "\n== Increment/Decrement ==\n";
    std::cout << "++A (prefix):\n" << (++A) << "-----\n";
    std::cout << "A++ (postfix):\n" << (A++) << "-----\n";
    std::cout << "After A++:\n" << A << "-----\n";

    std::cout << "--B (prefix):\n" << (--B) << "-----\n";
    std::cout << "B-- (postfix):\n" << (B--) << "-----\n";
    std::cout << "After B--:\n" << B << "-----\n";

    std::cout << "\n== Transpose and Determinant ==\n";
    std::cout << "~A (transpose):\n" << (~A) << "-----\n";
    std::cout << "!A (determinant): " << !A << "\n-----\n";

    std::cout << "\n== Comparisons ==\n";
    std::cout << "A == B: " << (A == B ? "true" : "false") << "\n";
    std::cout << "A != B: " << (A != B ? "true" : "false") << "\n";
    std::cout << "A < B: " << (A < B ? "true" : "false") << "\n";
    std::cout << "A <= B: " << (A <= B ? "true" : "false") << "\n";
    std::cout << "A > B: " << (A > B ? "true" : "false") << "\n";
    std::cout << "A >= B: " << (A >= B ? "true" : "false") << "\n-----\n";

    std::cout << "\n== Compound Assignment Operators ==\n";
    A += B;
    std::cout << "A += B:\n" << A << "-----\n";
    A -= B;
    std::cout << "A -= B:\n" << A << "-----\n";
    A *= B;
    std::cout << "A *= B:\n" << A << "-----\n";
    A = A / 2;
    std::cout << "A /= 2:\n" << A << "-----\n";
    A = A % 3;
    std::cout << "A %= 3:\n" << A << "-----\n";

    std::cout << "\n== Input Operator (>>)==\n";
    std::cout << "Enter 4 values for matrix A (2x2): ";
    std::cin >> A;
    std::cout << "You entered A:\n" << A;

    std::cout << "====== END OF DEMO ======\n";
    return 0;
}
