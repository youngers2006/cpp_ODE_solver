#ifndef VECTOR_MATH_TEMPLATES_H
#define VECTOR_MATH_TEMPLATES_H
#include <vector>
#include <stdexcept>

template<class T>
std::vector<T> operator*(const std::vector<T> LHS, const std::vector<T> RHS) {
    if (LHS.size() != RHS.size()) {
        throw std::invalid_argument("Vectors must be of equal size for elementwise multiplication.");
    }
    std::vector<T> result;
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS[i] * RHS[i];
    }
    return result;
}

template<class T>
std::vector<T> operator+(const std::vector<class T>& LHS, const std::vector<T>& RHS) {
    if (LHS.size() != RHS.size()) {
        throw std::invalid_argument("Vectors must be of equal size for addition.");
    }
    std::vector<T> result;
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS[i] + RHS[i];
    }
    return result;
}

template<class T>
std::vector<T> operator-(const std::vector<class T>& LHS, const std::vector<T>& RHS) {
    if (LHS.size() != RHS.size()) {
        throw std::invalid_argument("Vectors must be of equal size when subtracting.");
    }
    std::vector<T> result;
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS[i] - RHS[i];
    }
    return result;
}

template<class T>
std::vector<T> operator*(const T& LHS, const std::vector<T>& RHS) {
    std::vector<T> result;
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS[i] * RHS[i];
    }
    return result;
}

template<class T>
std::vector<T> operator*(const std::vector<T>& LHS, const T& RHS) {
    std::vector<T> result;
    for (int i = 0; i < LHS.size(); ++i) {
        result[i] = LHS[i] * RHS[i];
    }
    return result;
}
#endif