#include <iostream>
#include "../src/matrix/matrix.h"
#include <fstream>

int main() {
    // Define two 10x10 matrices with element types of long double
    // The first has all elements set to 1.0
    Matrix<long double> mat1(10, 10, 1.0);
    // The second has all elements set to 2.0
    Matrix<long double> mat2(10, 10, 2.0);
  
    // Set a few elements differently as a test of accessors
    mat1(3,4) = 10.0;
    mat2(1,2) = -15.0;
  
    // Add two matrices
	std::cout << "Add two matrices:" << std::endl;
	Matrix<long double> mat3 = mat1 + mat2;
	mat3.print();

    // Add a matrix with a scalar value
	std::cout << "Add a matrix with a scalar value:" << std::endl;
	long double s=9;
    mat3 = mat1 + s;
	mat3.print();

	// multiply two matrices
	std::cout << "multiply two matrices:" << std::endl;
	mat3 = mat1 * mat2;
	mat3.print();

	// multiply matrix with a scalar value
	std::cout << "multiply matrix with a scalar value:" << std::endl;
	s=5;
	mat3 = mat1 * s;
	mat3.print();

	// save matrix to csvfile
	std::cout << "save matrix to csv file:" << std::endl;
	std::string filename="matrix.csv";
	mat3.save(filename);
	


  
    return 0;
}
