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


} // namespace mat
