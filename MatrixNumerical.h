#ifndef MATRIX_NUMERICAL_H
#define MATRIX_NUMERICAL_H

#include "MatrixBase.h"
#include <stdexcept>

template <typename T>
class MatrixNumerical : public MatrixBase<T> {

public:
    MatrixNumerical();

    MatrixNumerical(size_t rows, size_t cols);

    MatrixNumerical(const std::vector<std::vector<T>>& data);

    T getDeterminant() const;

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;

    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;

    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;

    MatrixNumerical<T> getInverse() const;

    MatrixNumerical<T> operator/(const MatrixNumerical<T>& other) const;

    static MatrixNumerical<T> getIdentity(int size);
};


template <typename T>
MatrixNumerical<T>::MatrixNumerical()
    : MatrixBase<T>() {
}


template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols)
    : MatrixBase<T>(rows, cols) {
}


template <typename T>
MatrixNumerical<T>::MatrixNumerical(
    const std::vector<std::vector<T>>& data)
    : MatrixBase<T>(data.size(),
                    data.empty() ? 0 : data[0].size()) {

    this->data = data;
}


template <typename T>
T MatrixNumerical<T>::getDeterminant() const {

    if (this->rows != this->cols) {
        throw std::invalid_argument(
            "Le determinant necessite une matrice carree.");
    }

    if (this->rows == 0) {
        return T(1);
    }

    if (this->rows == 1) {
        return this->data[0][0];
    }

    if (this->rows == 2) {
        return this->data[0][0] * this->data[1][1]
             - this->data[0][1] * this->data[1][0];
    }

    T determinant = T(0);

    for (size_t col = 0; col < this->cols; col++) {

        MatrixNumerical<T> cofactorMatrix(
            this->rows - 1,
            this->cols - 1
        );

        size_t newRow = 0;

        for (size_t i = 0; i < this->rows; i++) {

            if (i == 0) {
                continue;
            }

            size_t newCol = 0;

            for (size_t j = 0; j < this->cols; j++) {

                if (j == col) {
                    continue;
                }

                cofactorMatrix.data[newRow][newCol]
                    = this->data[i][j];

                newCol++;
            }

            newRow++;
        }

        T sign = (col % 2 == 0) ? T(1) : T(-1);

        determinant +=
            sign
            * this->data[0][col]
            * cofactorMatrix.getDeterminant();
    }

    return determinant;
}


template <typename T>
MatrixNumerical<T>
MatrixNumerical<T>::operator+(
    const MatrixNumerical<T>& other) const {

    if (this->rows != other.rows ||
        this->cols != other.cols) {

        throw std::invalid_argument(
            "Les matrices doivent avoir les memes dimensions.");
    }

    MatrixNumerical<T> result(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {

            result.data[i][j] =
                this->data[i][j] + other.data[i][j];
        }
    }

    return result;
}


template <typename T>
MatrixNumerical<T>
MatrixNumerical<T>::operator-(
    const MatrixNumerical<T>& other) const {

    if (this->rows != other.rows ||
        this->cols != other.cols) {

        throw std::invalid_argument(
            "Les matrices doivent avoir les memes dimensions.");
    }

    MatrixNumerical<T> result(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {

            result.data[i][j] =
                this->data[i][j] - other.data[i][j];
        }
    }

    return result;
}


template <typename T>
MatrixNumerical<T>
MatrixNumerical<T>::operator*(
    const MatrixNumerical<T>& other) const {

    if (this->cols != other.rows) {
        throw std::invalid_argument(
            "Dimensions incompatibles pour la multiplication.");
    }

    MatrixNumerical<T> result(this->rows, other.cols);

    for (size_t i = 0; i < this->rows; i++) {

        for (size_t j = 0; j < other.cols; j++) {

            result.data[i][j] = T(0);

            for (size_t k = 0; k < this->cols; k++) {

                result.data[i][j] +=
                    this->data[i][k]
                    * other.data[k][j];
            }
        }
    }

    return result;
}


template <typename T>
MatrixNumerical<T>
MatrixNumerical<T>::getInverse() const {

    if (this->rows != this->cols) {
        throw std::invalid_argument(
            "L'inverse necessite une matrice carree.");
    }

    T determinant = this->getDeterminant();

    if (determinant == T(0)) {
        throw std::invalid_argument(
            "La matrice n'est pas inversible.");
    }

    MatrixNumerical<T> result(this->rows, this->cols);

    // Cas 1x1
    if (this->rows == 1) {
        result.data[0][0] =
            T(1) / this->data[0][0];

        return result;
    }

    for (size_t i = 0; i < this->rows; i++) {

        for (size_t j = 0; j < this->cols; j++) {

            MatrixNumerical<T> minor(
                this->rows - 1,
                this->cols - 1
            );

            size_t minorRow = 0;

            for (size_t r = 0; r < this->rows; r++) {

                if (r == i) {
                    continue;
                }

                size_t minorCol = 0;

                for (size_t c = 0; c < this->cols; c++) {

                    if (c == j) {
                        continue;
                    }

                    minor.data[minorRow][minorCol]
                        = this->data[r][c];

                    minorCol++;
                }

                minorRow++;
            }

            T sign =
                ((i + j) % 2 == 0)
                ? T(1)
                : T(-1);

            T cofactor =
                sign * minor.getDeterminant();

            result.data[j][i] =
                cofactor / determinant;
        }
    }

    return result;
}


template <typename T>
MatrixNumerical<T>
MatrixNumerical<T>::operator/(
    const MatrixNumerical<T>& other) const {

    return *this * other.getInverse();
}


template <typename T>
MatrixNumerical<T>
MatrixNumerical<T>::getIdentity(int size) {

    MatrixNumerical<T> identity(size, size);

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (i == j) {
                identity.data[i][j] = T(1);
            }
            else {
                identity.data[i][j] = T(0);
            }
        }
    }

    return identity;
}

#endif