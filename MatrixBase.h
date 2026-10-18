#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <vector>
#include <iostream>

template <typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase();

    MatrixBase(size_t rows, size_t cols);

    void addElement(size_t row, size_t col, T value);

    T getElement(size_t row, size_t col) const;

    size_t getRows() const;

    size_t getCols() const;

    void Display() const;
};


template <typename T>
MatrixBase<T>::MatrixBase()
    : rows(0), cols(0) {
}


template <typename T>
MatrixBase<T>::MatrixBase(size_t rows, size_t cols)
    : rows(rows), cols(cols) {

    data.resize(rows);

    for (size_t i = 0; i < rows; i++) {
        data[i].resize(cols);
    }
}


template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, T value) {
    data[row][col] = value;
}


template <typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const {
    return data[row][col];
}


template <typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;
}


template <typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;
}


template <typename T>
void MatrixBase<T>::Display() const {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

#endif