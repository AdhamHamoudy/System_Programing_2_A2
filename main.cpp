#include <iostream>
#include "SquareMat.hpp"

using namespace mat;

int main() {
    try {
        SquareMat a(2);  // 2x2 matrix
        SquareMat b(2);

        // Fill matrix a
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;

        // Fill matrix b
        b[0][0] = 5;
        b[0][1] = 6;
        b[1][0] = 7;
        b[1][1] = 8;

        // Sum matrices
        SquareMat c = a + b;

        std::cout << "Matrix A + B = C:" << std::endl;
        for (int i = 0; i < c.getSize(); ++i) {
            for (int j = 0; j < c.getSize(); ++j) {
                std::cout << c[i][j] << " ";
            }
            std::cout << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
