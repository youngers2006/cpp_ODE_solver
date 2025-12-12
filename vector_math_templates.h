#ifndef VECTOR_MATH_TEMPLATES_H
#define VECTOR_MATH_TEMPLATES_H
#include <vector>
#include <cmath>
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
    for (int i = 0; i < RHS.size(); ++i) {
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

template<class T>
double vector_norm(const std::vector<T>& v) {
    double sum_sq = 0.0;
    for (auto& val : v) {
        sum_sq += val * val;
    }
    return std::sqrt(sum_sq);
}

std::vector<std::vector<double>> eye(const int& rows, const int& columns) {
    std::vector<std::vector<double>> I(rows, std::vector<double>(columns, 0.0));
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            if (row == col) {
                I[row][col] = 1.0;
            } 
        }
    }
    return I;
}

// Template operator overload for scalar multiplication of a matrix when LHS is scalar.
template<class T>
std::vector<std::vector<T>> operator*(const T& LHS, const std::vector<std::vector<T>>& RHS) {
    int rows = RHS.size();
    int cols = RHS[0].size();
    std::vector<std::vector<T>> result(rows, std::vector<double>(cols, 0.0));
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            result[row][col] = LHS * RHS[row][col];
        }
    }
    return result;
}

// Template operator overload for scalar multiplication of a matrix when RHS is scalar.
template<class T>
std::vector<std::vector<T>> operator*(const std::vector<std::vector<T>>& LHS, const T& RHS) {
    int rows = LHS.size();
    int cols = LHS[0].size();
    std::vector<std::vector<T>> result(rows, std::vector<double>(cols, 0.0));
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            result[row][col] = LHS[row][col] * RHS;
        }
    }
    return result;
}

template<class T>
std::vector<std::vector<T>> operator-(const std::vector<std::vector<T>>& LHS, const std::vector<std::vector<T>>& RHS) {
    int rows1 = RHS.size();
    int cols1 = RHS[0].size();
    int rows2 = LHS.size();
    int cols2 = LHS[0].size();
    if (rows1 != rows2 || cols1 != cols2) {
        throw std::invalid_argument("Matricies must be of equal size when subtracting.");
    }
    std::vector<std::vector<T>> result(rows1, std::vector<double>(cols1, 0.0));
    for (int row = 0; row < rows1; ++row) {
        for (int col = 0; col < cols1; ++col) {
            result[row][col] = LHS[row][col] - RHS[row][col];
        }
    }
    return result;
}
#endif