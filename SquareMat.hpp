#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

namespace mat {

class SquareMat {
private:
    int size;            // Size of the matrix (N x N)
    double** data;       // 2D array of values

public:
    SquareMat(int size);

    ~SquareMat();

    SquareMat(const SquareMat& other);

    SquareMat& operator=(const SquareMat& other);
    friend SquareMat operator+(const SquareMat& lhs, const SquareMat& rhs);

    double* operator[](int index);

    int getSize() const;

    // Helper to calculate sum of all elements (used in ==, >, < ops)
    double sum() const;
};

} 

#endif
