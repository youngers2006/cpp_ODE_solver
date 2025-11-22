#ifndef VECTOR_MATH_TEMPLATES_H
#define VECTOR_MATH_TEMPLATES_H
#include <vector>
#include <stdexcept>

// Template operator overload for vector elementwise multiplication.
template<class T>
std::vector<T> operator*(const std::vector<T>& LHS, const std::vector<T>& RHS) {
    if (LHS.size() != RHS.size()) {
        throw std::invalid_argument("Vectors must be of equal size for elementwise multiplication.");
    }
    std::vector<T> result(LHS.size());
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS[i] * RHS[i];
    }
    return result;
}

// Template operator overload for vector addition.
template<class T>
std::vector<T> operator+(const std::vector<T>& LHS, const std::vector<T>& RHS) {
    if (LHS.size() != RHS.size()) {
        throw std::invalid_argument("Vectors must be of equal size for addition.");
    }
    std::vector<T> result(LHS.size());
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS[i] + RHS[i];
    }
    return result;
}

// Template operator overload for vector subtraction.
template<class T>
std::vector<T> operator-(const std::vector<T>& LHS, const std::vector<T>& RHS) {
    if (LHS.size() != RHS.size()) {
        throw std::invalid_argument("Vectors must be of equal size when subtracting.");
    }
    std::vector<T> result(LHS.size());
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS[i] - RHS[i];
    }
    return result;
}

// Template operator overload for scalar multiplication of a vector when LHS is scalar.
template<class T>
std::vector<T> operator*(const T& LHS, const std::vector<T>& RHS) {
    std::vector<T> result(RHS.size());
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS * RHS[i];
    }
    return result;
}

// Template operator overload for scalar multiplication of a vector when RHS is scalar.
template<class T>
std::vector<T> operator*(const std::vector<T>& LHS, const T& RHS) {
    std::vector<T> result(LHS.size());
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS[i] * RHS;
    }
    return result;
}
#endif