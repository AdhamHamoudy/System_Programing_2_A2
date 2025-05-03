#include "SquareMat.hpp"
#include <stdexcept>
// #include <iostream>   // optional for debugging

namespace mat {

// Constructor: Allocates memory for a size x size matrix
SquareMat::SquareMat(int size) : size(size) {
    if (size <= 0) {
        throw std::invalid_argument("Matrix size must be positive.");
    }

    // Allocate outer array (rows)
    data = new double*[size];

    // Allocate inner arrays (columns) and initialize to 0
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0.0;
        }
    }
}

// Destructor: Frees all dynamically allocated memory
SquareMat::~SquareMat() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i]; // Delete each row
    }
    delete[] data; // Delete the outer array
}

// Copy Constructor: Creates a deep copy of another matrix
SquareMat::SquareMat(const SquareMat& other) : size(other.size) {
    data = new double*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Copy Assignment Operator: Deep copy and handle self-assignment
SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this == &other) return *this; // Self-assignment check

    // Free current memory
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;

    // Copy size and allocate new memory
    size = other.size;
    data = new double*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

// [] Operator: Allows access to elements with mat[i][j] syntax
double* SquareMat::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// getSize(): Returns the size of the matrix
int SquareMat::getSize() const {
    return size;
}

// sum(): Returns the sum of all elements (used for ==, >, <)
double SquareMat::sum() const {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            total += data[i][j];
        }
    }
    return total;
}

SquareMat operator+(const SquareMat& lhs, const SquareMat& rhs) {
    if (lhs.size != rhs.size) {
        throw std::invalid_argument("Matrix sizes do not match for addition");
    }

    SquareMat result(lhs.size);
    for (int i = 0; i < lhs.size; ++i) {
        for (int j = 0; j < lhs.size; ++j) {
            result[i][j] = lhs.data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

SquareMat operator-(const SquareMat& lhs, const SquareMat& rhs) {
    if (lhs.size != rhs.size) {
        throw std::invalid_argument("Matrix sizes do not match for subtraction");
    }

    SquareMat result(lhs.size);
    for (int i = 0; i < lhs.size; ++i) {
        for (int j = 0; j < lhs.size; ++j) {
            result[i][j] = lhs.data[i][j] - rhs.data[i][j];
        }
    }
    return result;
}

SquareMat operator-(const SquareMat& mat) {
    SquareMat result(mat.size);
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            result[i][j] = -mat.data[i][j];
        }
    }
    return result;
}

SquareMat operator*(const SquareMat& lhs, const SquareMat& rhs) {
    if (lhs.size != rhs.size) {
        throw std::invalid_argument("Matrix sizes must match for multiplication");
    }

    SquareMat result(lhs.size);

    for (int i = 0; i < lhs.size; ++i) {
        for (int j = 0; j < lhs.size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < lhs.size; ++k) {
                result[i][j] += lhs.data[i][k] * rhs.data[k][j];
            }
        }
    }

    return result;
}

SquareMat operator*(const SquareMat& mat, double scalar) {
    SquareMat result(mat.size);
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            result[i][j] = mat.data[i][j] * scalar;
        }
    }
    return result;
}

// scalar * matrix (just re-use the other function)
SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;  // re-use implementation
}


SquareMat operator%(const SquareMat& lhs, const SquareMat& rhs) {
    if (lhs.size != rhs.size) {
        throw std::invalid_argument("Matrix sizes must match for element-wise multiplication");
    }

    SquareMat result(lhs.size);
    for (int i = 0; i < lhs.size; ++i) {
        for (int j = 0; j < lhs.size; ++j) {
            result[i][j] = lhs.data[i][j] * rhs.data[i][j];
        }
    }
    return result;
}


SquareMat operator%(const SquareMat& mat, int scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero is undefined");
    }

    SquareMat result(mat.size);
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            result[i][j] = static_cast<int>(mat.data[i][j]) % scalar;
        }
    }
    return result;
}


SquareMat operator/(const SquareMat& mat, double scalar) {
    if (scalar == 0.0) {
        throw std::invalid_argument("Division by zero is undefined");
    }

    SquareMat result(mat.size);
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            result[i][j] = mat.data[i][j] / scalar;
        }
    }

    return result;
}

SquareMat operator^(const SquareMat& mat, int power) {
    if (power < 0) {
        throw std::invalid_argument("Negative exponent not supported");
    }

    SquareMat result(mat.size);
    if (power == 0) {
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                result[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
        return result;
    }

    result = mat;
    for (int i = 1; i < power; ++i) {
        result = result * mat;
    }

    return result;
}

// Prefix ++
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] += 1;
    return *this;
}

// Prefix --
SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] -= 1;
    return *this;
}

// Postfix ++
SquareMat SquareMat::operator++(int) {
    SquareMat copy = *this; // Save current state
    ++(*this);              // Use prefix ++
    return copy;            // Return previous version
}

// Postfix --
SquareMat SquareMat::operator--(int) {
    SquareMat copy = *this;
    --(*this);
    return copy;
}

SquareMat operator~(const SquareMat& mat) {
    SquareMat result(mat.size);

    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            result[i][j] = mat.data[j][i];  // flip i <-> j
        }
    }

    return result;
}

bool operator==(const SquareMat& lhs, const SquareMat& rhs) {
    return lhs.sum() == rhs.sum();
}

bool operator!=(const SquareMat& lhs, const SquareMat& rhs) {
    return !(lhs == rhs);
}

bool operator<(const SquareMat& lhs, const SquareMat& rhs) {
    return lhs.sum() < rhs.sum();
}

bool operator<=(const SquareMat& lhs, const SquareMat& rhs) {
    return lhs.sum() <= rhs.sum();
}

bool operator>(const SquareMat& lhs, const SquareMat& rhs) {
    return lhs.sum() > rhs.sum();
}

bool operator>=(const SquareMat& lhs, const SquareMat& rhs) {
    return lhs.sum() >= rhs.sum();
}


// Helper to create minor matrix
SquareMat getMinor(const SquareMat& mat, int rowToRemove, int colToRemove) {
    int n = mat.getSize();
    SquareMat minor(n - 1);

    int mi = 0;
    for (int i = 0; i < n; ++i) {
        if (i == rowToRemove) continue;
        int mj = 0;
        for (int j = 0; j < n; ++j) {
            if (j == colToRemove) continue;
            minor[mi][mj] = mat.data[i][j];
            ++mj;
        }
        ++mi;
    }

    return minor;
}

// Determinant via recursion
double operator!(const SquareMat& mat) {
    int n = mat.getSize();

    if (n == 1) return mat.data[0][0];
    if (n == 2) {
        return mat.data[0][0] * mat.data[1][1] - mat.data[0][1] * mat.data[1][0];
    }

    double det = 0.0;
    for (int col = 0; col < n; ++col) {
        SquareMat minor = getMinor(mat, 0, col);
        double sign = (col % 2 == 0) ? 1 : -1;
        det += sign * mat.data[0][col] * !minor;
    }

    return det;
}

} // namespace mat
