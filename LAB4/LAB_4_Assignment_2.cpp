/*Author : RAJ ROY*/
/*Scholar Id = 2212002*/

#include<iostream>
#include<vector>
using namespace std;

class matrixType {
public:
    vector<vector<double>> matrix;
    int rows;
    int cols;

public:
    
    //custom constrctor
     matrixType(int numRows, int numCols) {
        rows = numRows;
        cols = numCols;
        matrix.resize(rows, vector<double>(cols, 0.0));
    }

    // Overload addition operator
    matrixType operator+(matrixType& input){
        if (rows != input.rows || cols != input.cols) {
            cout  << "NOT MATCHING WITH ORIGINAL MATRIX DIMENSION" << endl;
            return *this; 
        }

        matrixType result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] + input.matrix[i][j];
            }
        }

        return result;
    }

    // Overload subtraction operator
    matrixType operator-(matrixType& input)  {
        if (rows != input.rows || cols != input.cols) {
            cout << "NOT MATCHING WITH ORIGINAL MATRIX DIMENSION" << endl;
            return *this;  // Return the original matrix if sizes do not match
        }

        matrixType result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] - input.matrix[i][j];
            }
        }

        return result;
    }

    // Overload multiplication operator
    matrixType operator*(matrixType& input)  {
        if (cols != input.rows) {
           cout << "NOT CORRECT DIMENSION FOR MATRIX MULTIPLICATION" << endl;
            return *this;  // Return the original matrix if multiplication is not possible
        }

        matrixType result(rows, input.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < input.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.matrix[i][j] += matrix[i][k] * input.matrix[k][j];
                }
            }
        }

        return result;
    }

    // Overload << operator for matrix output
    friend ostream& operator<<(ostream& os, matrixType& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                cout << matrix.matrix[i][j] << " ";
            }
            cout << endl;
        }
        return os;
    }
};

int main() {
    matrixType A(4, 4); 
    matrixType B(4, 4);

    // Initialize matrices A and B
    //and assigning some random values in it;
   for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.cols; ++j) {
        A.matrix[i][j] = 1 + i; 
        B.matrix[i][j] = 1 + j + i;
    }
}

    //addition
    matrixType C = A + B;
    
    //subtraction
    matrixType D = A - B;
    
    //multiplication
    matrixType E = A * B;

    
    cout << "Matrix A:" << endl << A << endl;
    cout << "Matrix B:" << endl << B << endl;
    cout << "Addition of Matrix A and Matrix B:" << endl << C << endl;
    cout << "Subtraction of Matrix A and Matrix B:" << endl << D << endl;
    cout << "Multiplication of Matrix A and Matrix B:" << endl << E << endl;

    return 0;
}