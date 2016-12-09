#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

// exploit namespaces to shorten code
using namespace boost::numeric::ublas;
using std::cout; 
using std::endl;

void print_plane(matrix<std::complex<long double> > p, int rows, int cols)
{
	int r,c;

	for (r=0;r<rows;r++){
		for (c=0;c<cols;c++){
			cout<<p(r,c) << ' ';	
		}
		cout << endl;
	}

}

int main(int argc, char **argv) 
{

  // declare three 3x3 matrices of complex<long double> elements
  matrix<std::complex<long double> > m(3, 3), n(3, 3), o(3, 3);

  // iterate over 3x3 matrix entries
  // r : row index
  // c : column index
  for (unsigned r = 0; r < m.size1(); r++) {
    for (unsigned c = 0; c < m.size2(); c++) {
      // enumerated matrix entries
      m(r,c) = 3 * r + c;

      // complex numbers designating rows and cols
      n(r,c) = r + c * 1i;

      // elementwise square of n
      o(r,c) = std::pow(n(r,c), 2);
    }
  }

  // print to screen as demonstration
  cout << "m:" << endl;
  cout << m << endl;
  cout << endl << "n:" << endl;
  cout << n << endl;
  cout << endl << "o:" << endl;
  cout << o << endl;
  cout << endl << "m + n:" << endl;
  cout << m + n << endl;
  cout << endl << "m * n:" << endl;
  cout << prod(m, n) << endl;
  cout << endl << "n * n - o:" << endl;
  cout << prod(n, n) - o << endl;
  cout << endl;
  cout << "Print matrix m as a plane:" << endl;
  print_plane(m,3,3);
}
