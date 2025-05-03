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
    friend SquareMat operator-(const SquareMat& lhs, const SquareMat& rhs);
    friend SquareMat operator-(const SquareMat& mat); 
    friend SquareMat operator*(const SquareMat& lhs, const SquareMat& rhs);
    friend SquareMat operator*(const SquareMat& mat, double scalar);
    friend SquareMat operator*(double scalar, const SquareMat& mat);
    friend SquareMat operator%(const SquareMat& lhs, const SquareMat& rhs);
    friend SquareMat operator%(const SquareMat& mat, int scalar);
    friend SquareMat operator/(const SquareMat& mat, double scalar);
    friend SquareMat operator^(const SquareMat& mat, int power);
    SquareMat& operator++();    // ++mat
    SquareMat& operator--();    // --mat
    SquareMat operator++(int);  // mat++
    SquareMat operator--(int);  // mat--
    friend SquareMat operator~(const SquareMat& mat);
    friend bool operator==(const SquareMat& lhs, const SquareMat& rhs);
    friend bool operator!=(const SquareMat& lhs, const SquareMat& rhs);
    friend bool operator<(const SquareMat& lhs, const SquareMat& rhs);
    friend bool operator<=(const SquareMat& lhs, const SquareMat& rhs);
    friend bool operator>(const SquareMat& lhs, const SquareMat& rhs);
    friend bool operator>=(const SquareMat& lhs, const SquareMat& rhs);
    friend SquareMat getMinor(const SquareMat& mat, int rowToRemove, int colToRemove);
    friend double operator!(const SquareMat& mat);

    int getSize() const;

    // Helper to calculate sum of all elements (used in ==, >, < ops)
    double sum() const;
};

} 

#endif
