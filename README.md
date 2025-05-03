
# SquareMat - Operator Overloading for Square Matrices

## 📌 Overview

This project implements a `SquareMat` class in C++ to represent **N × N** square matrices and supports a wide range of **operator overloads**. The goal is to practice dynamic memory management, operator overloading, and clean C++ design.

All code is written according to the assignment requirements and passes all provided test cases.

---

## 📁 Project Structure

```
.
├── SquareMat.hpp        # Class definition and declarations
├── SquareMat.cpp        # Class implementation
├── main.cpp             # Demo program (tests all operators)
├── test.cpp             # Doctest unit tests (can be extended)
├── makefile             # Build and run automation
```

---

## ⚙️ Compilation & Execution

Use the provided `makefile` to build and test the project.

### ✅ Run the demo (`main.cpp`):
```bash
make main
```

### ✅ Run unit tests (`test.cpp`):
```bash
make test
```

### ✅ Check memory leaks with valgrind:
```bash
make valgrind
```

### ✅ Clean compiled files:
```bash
make clean
```

---

## 💡 Implemented Features

### ✅ Matrix Construction
- Dynamic memory allocation for N × N matrix
- Deep copy (copy constructor and assignment operator)
- Proper destructor to release memory

---

## 🔢 Supported Operators

### Arithmetic Operators:
- `A + B` → Matrix addition
- `A - B` → Matrix subtraction
- `-A` → Unary negation
- `A * B` → Matrix multiplication
- `A * scalar`, `scalar * A` → Scalar multiplication
- `A / scalar` → Scalar division
- `A % B` → Element-wise multiplication
- `A % scalar` → Scalar modulo

### Power and Transpose:
- `A ^ n` → Matrix raised to a non-negative power
- `~A` → Matrix transpose

### Determinant:
- `!A` → Determinant (recursive implementation)

### Comparison Operators (based on sum of elements):
- `==`, `!=`, `<`, `<=`, `>`, `>=`

### Increment / Decrement:
- `++A`, `A++` → Increment all elements
- `--A`, `A--` → Decrement all elements

### Compound Assignment Operators:
- `A += B`, `A -= B`, `A *= B`, `A /= scalar`, `A %= scalar`

### Stream Operators:
- `std::ostream << A` → Print matrix
- `std::istream >> A` → Read matrix from user input

---

## 🧠 Design Choices

- All operator overloads that need access to private members are implemented as `friend` functions for clarity and access.
- Internal helper method `sum()` is used for comparison operators.
- `getMinor()` helper is used to compute the determinant recursively.

---

## 🧪 Testing

The `main.cpp` file tests **all operators** with expected output. It includes:

- Arithmetic operations
- Compound assignments
- Comparisons
- Increment/decrement
- Transpose and determinant
- Input/output

---

## ✅ Status

- ✅ All required operators implemented
- ✅ All tests pass
- ✅ Code meets assignment constraints (no STL containers, clean makefile, no memory leaks)

---

## 👤 Author

Adham Hamoudy  
GitHub: [AdhamHamoudy/System_Programing_2_A2](https://github.com/AdhamHamoudy/System_Programing_2_A2)
