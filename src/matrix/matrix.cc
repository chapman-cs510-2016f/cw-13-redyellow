// Pre-processor directives to prevent redundant library loading
#ifndef CW13_MATRIX_CPP_
#define CW13_MATRIX_CPP_

// include the header declarations
#include "matrix.h"
#include <iostream>
#include <fstream>

//*************
//
// CONSTRUCTORS
//
//*************

// Default constructor
template<typename T> 
Matrix<T>::Matrix(unsigned int _rows, unsigned int _cols, const T& _initial) {
    // use vector method to resize outer vector of rows to length _rows
    mat.resize(_rows);
    for (unsigned int i=0; i<mat.size(); i++) {
        // for each row, resize to length _cols of columns
        // and initialize elements to value _initial
        mat[i].resize(_cols, _initial);
    }
    // set private fields rows and cols properly
    rows = _rows;
    cols = _cols;
}

// "Rule of 3" memory management:
// 1) Copy-constructor
template<typename T> Matrix<T>::Matrix(const Matrix<T>& rhs) {
    // Simply set private fields according to fields
    // of existing Matrix<T> object
    mat = rhs.mat;
    rows = rhs.get_rows();
    cols = rhs.get_cols();
}

// 2) Destructor
// No memory is dynamically allocated in the class,
// so just use default compiler cleanup of memory 
template<typename T> Matrix<T>::~Matrix() {}

// 3) Assignment operator
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    // If assigning to itself, just return itself
    if (&rhs == this)
        return *this;
  
    // Acquire new rows and cols
    unsigned int new_rows = rhs.get_rows();
    unsigned int new_cols = rhs.get_cols();
  
    // resize to new number of rows
    mat.resize(new_rows);
    // resize each row to new number of cols
    for (unsigned int i=0; i<mat.size(); i++) {
        mat[i].resize(new_cols);
    }
  
    // assign each element 
    for (unsigned int i=0; i<new_rows; i++) {
        for (unsigned int j=0; j<new_cols; j++) {
            mat[i][j] = rhs(i, j);
        }
    }
  
    // store new number of rows and columns
    rows = new_rows;
    cols = new_cols;
  
    // return newly modified object
    return *this;
}



//*************
//
// ACCESSORS
//
//*************


// Access individual elements (non-const: read + write)
template<typename T>
T& Matrix<T>::operator() (const unsigned int &row, const unsigned int &col) {
    return this->mat[row][col];
}

// Access individual elements (const: read only)
template<typename T>
const T& Matrix<T>::operator() (const unsigned int &row, const unsigned int &col) 
const {
    return this->mat[row][col];
}

// Get number of rows
template<typename T>
unsigned int Matrix<T>::get_rows() const {
    return this->rows;
}

// Get number of cols
template<typename T>
unsigned int Matrix<T>::get_cols() const {
    return this->cols;
}



//*********************
//
// OPERATOR OVERLOADING
//
//*********************


// Addition of two matrices
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
    // Create new matrix to store result, initialize to zero
    Matrix result(rows, cols, 0.0);
  
    // Add each matrix element-by-element
    for (unsigned int i=0; i<rows; i++) {
        for (unsigned int j=0; j<cols; j++) {
            result(i,j) = this->mat[i][j] + rhs(i,j);
        }
    }
  
    return result;
}

// Addition of a matrix with a scalar value
template<typename T>
Matrix<T> Matrix<T>::operator+(const T s) {
    // Create new matrix to store result, initialize to zero
    Matrix result(rows, cols, 0.0);
  
    // Add each matrix element-by-element
    for (unsigned int i=0; i<rows; i++) {
        for (unsigned int j=0; j<cols; j++) {
            result(i,j) = this->mat[i][j] + s;
        }
    }
  
    return result;
}

// Multiply of two matrices
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs){
    // Create new matrix to store result, initialize to zero
   	Matrix result(rows, cols, 0.0);
  
	// multiply each matrix element-by-element
   	for (unsigned int i=0; i<rows; i++) {
       	for (unsigned int j=0; j<cols; j++) {
			for (unsigned int k=0; k<cols; k++) {
           		result(i,j) += this->mat[i][k] * rhs(k,j);
			}
       	}
   	}
	return result;
}
// multiply matrix with a scalar value
template<typename T>
Matrix<T> Matrix<T>::operator*(const T r){
    // Create new matrix to store result, initialize to zero
   	Matrix result(rows, cols, 0.0);
  
	// multiply each matrix element-by-element
   	for (unsigned int i=0; i<rows; i++) {
       	for (unsigned int j=0; j<cols; j++) {
           	result(i,j) += this->mat[i][j] * r;
		}
   	}
	return result;
}


template<typename T>
void Matrix<T>::print() {
// Print out the third matrix as a text array
	int i,j;
    for (int i=0; i<this->get_rows(); i++) {
        for (int j=0; j<this->get_cols(); j++) {
            std::cout << this->mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }

}

// save matrix into a csv file
template<typename T>
void Matrix<T>::save(std::string filename){
	// each row as seperated by ,
	std::cout << filename<<std::endl;
	std::ofstream csvf(filename); // open the file
	int i,j;
    for (int i=0; i<this->get_rows(); i++) {
        for (int j=0; j<this->get_cols(); j++) {
			if (j==get_cols()-1){
			csvf << this->mat[i][j];
			}
			else{
            csvf << this->mat[i][j] << ",";
			}
        }
        csvf << '\n';
    }

	csvf.close(); // close file

}

#endif // CW13_MATRIX_CPP_
