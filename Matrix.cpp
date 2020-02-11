#include "Matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c), size(r * c), isSquare(r == c)
{
	/*rows = r;
	cols = c;
	size = rows * cols;
	if (r == c) isSquare = true; else isSquare = false;*/
	
	//matrix = vector<vector<int>>(rows);
	matrix.resize(rows);

	for (int i = 0; (size_t)i < matrix.size(); i++)
		matrix[i].resize(cols); //vector<int>(cols);
}

Matrix::Matrix(int r, int c, int value) : rows(r), cols(c), size(r * c), isSquare(r == c)
{
	//rows = r;
	//cols = c;
	//size = rows * cols;
	//if (r == c) isSquare = true; else isSquare = false;

	//matrix = vector<vector<int>>(rows);
	matrix.resize(rows);

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		matrix[i].resize(cols); //vector<int>(cols);

		for (int k = 0; k < cols; k++)
			matrix[i][k] = value;
	}
}

Matrix::Matrix(const Matrix& m2) : rows(m2.rows), cols(m2.cols), size(m2.size), isSquare(m2.isSquare)
{
	/*rows = m2.rows;
	cols = m2.cols;
	size = m2.size;
	isSquare = m2.isSquare;*/

	//matrix = vector<vector<int>>(rows);
	matrix.resize(rows);

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		matrix[i].resize(cols); //vector<int>(cols);

		for (int k = 0; k < cols; k++)
		{
			matrix[i][k] = m2.matrix[i][k];
		}
			
	}
}

Matrix::Matrix(vector<vector<int>> values) : matrix(values), rows(values.size()), cols(values[0].size()), size(rows * cols), isSquare(rows == cols)
{
	//matrix = values;
	//rows = values.size();
	//cols = values[0].size();
	//size = rows * cols;
	//if (rows == cols) isSquare = true; else isSquare = false;
}

Matrix::~Matrix()
{
}

void Matrix::PopulateMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			cout << "Enter value for position [" << i << ", " << k << "]: ";
			int input;
			
			while (true)
			{
				cin >> input;
				if (!cin.fail())
				{
					matrix[i][k] = input;
					break;
				}
				else
				{
					cout << "\nPlease enter a valid integer: ";
					cin.clear();
					cin.ignore();
				}
			}			
		}
	}
}

void Matrix::UpdateValue(int r, int c, int value)
{
	if (r < 0 || c < 0 || r >= rows || c >= cols) throw invalid_argument("Updating value failed - Invalid row and/or column...\n");

	matrix[r][c] = value;
}

void Matrix::DisplayMatrix()
{
	cout << "Displaying Matrix with dimensions [" << rows << ", " << cols << "]...:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
			cout << right << setw(8) << matrix[i][k] << "  ";

		cout << "\n";
	}
	cout << "\n";
}

Matrix Matrix::Transpose()
{
	Matrix newMatrix = Matrix(cols, rows);

	for (int i = 0; i < cols; i++)
	{
		for (int k = 0; k < rows; k++)
			newMatrix.matrix[i][k] = matrix[k][i];
	}

	return newMatrix;
}

int Matrix::GetNumOfRows() const { return rows; }

int Matrix::GetNumOfCols() const { return cols; }

int Matrix::GetSize() const { return size; }

bool Matrix::IsSquare() const { return isSquare; }

vector<int> Matrix::GetMainDiagonal()
{
	if (!isSquare) throw invalid_argument("Retrieving diagonal failed - Matrix is not square...");

	vector<int> diagonal(rows);

	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++) 
		{
			if (i == k) diagonal[i] = matrix[i][k];
		}
	}

	return diagonal;
}

vector<int> Matrix::GetAntidiagonal()
{
	if (!isSquare) throw invalid_argument("Retrieving diagonal failed - Matrix is not square...");

	vector<int> diagonal(rows);

	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++) 
		{
			if (i + k == rows - 1) diagonal[i] = matrix[i][k];
		}
	}

	return diagonal;	
}

void Matrix::DisplayDiagonal(Diagonal diagonal)
{
	if (!isSquare) throw invalid_argument("Displaying diagonal failed - Matrix is not square...");

	cout << "Displaying Matrix " << ((diagonal == MAIN) ? "Main" : "Anti") << " Diagonal:\n";

	switch (diagonal) 
	{
	case MAIN:
		for (int i = 0; i < rows; i++)
		{
			for (int k = 0; k < cols; k++)
				if(i == k) cout << right << setw(5) << matrix[i][k] << " ";
				else cout << right << setw(5) <<  " ";
			cout << "\n";
		}
		break;
	case ANTIDIAGONAL:
		for (int i = 0; i < rows; i++)
		{
			for (int k = 0; k < cols; k++)
				if(i + k == rows - 1) cout << right << setw(5) << matrix[i][k] << " ";
				else cout << right << setw(5) << " ";
			cout << "\n";
		}
		break;
	}
}

//int Matrix::GetValue(int r, int c)
//{
//	if (r < 0 || c < 0 || r >= rows || c >= cols) throw invalid_argument("Invalid row and/or column...");
//
//	return matrix[r][c];
//}

int & Matrix::operator()(int r, int c)
{
	if (r < 0 || c < 0 || r >= rows || c >= cols) throw invalid_argument("Retrieving value failed - Invalid row and/or column...");

	return matrix[r][c];
}

Matrix & Matrix::operator=(const Matrix & other)
{
	if (&other == this) return *this;

	rows = other.rows;
	cols = other.cols;
	size = rows * cols;
	isSquare = other.isSquare;

	matrix.resize(rows);

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		matrix[i].resize(cols);
	}

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			matrix[i][k] = other.matrix[i][k];
		}
	}

	return *this;
}

Matrix & Matrix::operator+=(int other)
{
	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			matrix[i][k] += other;
		}
	}

	return *this;
}

Matrix & Matrix::operator+=(const Matrix & other)
{
	if(size != other.size) throw invalid_argument("Addition operaion failed - Matrices are of different size...");

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			matrix[i][k] += other.matrix[i][k];
		}
	}

	return *this;
}

Matrix Matrix::operator+(int other)
{
	Matrix newMatrix = Matrix(rows, cols);

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			newMatrix.matrix[i][k] = matrix[i][k] + other;
		}
	}

	return newMatrix;
}

Matrix Matrix::operator+(const Matrix & other)
{
	if(size != other.size) throw invalid_argument("Addition operaion failed - Matrices are of different size...");

	Matrix newMatrix = Matrix(rows, cols);

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			newMatrix.matrix[i][k] = matrix[i][k] + other.matrix[i][k];
		}
	}

	return newMatrix;
}

Matrix & Matrix::operator-=(int other)
{
	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			matrix[i][k] -= other;
		}
	}

	return *this;
}

Matrix & Matrix::operator-=(const Matrix & other)
{
	if(size != other.size) throw invalid_argument("Addition operaion failed - Matrices are of different size...");

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			matrix[i][k] -= other.matrix[i][k];
		}
	}

	return *this;
}

Matrix Matrix::operator-(int other)
{
	Matrix newMatrix = Matrix(rows, cols);

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			newMatrix.matrix[i][k] = matrix[i][k] - other;
		}
	}

	return newMatrix;
}

Matrix Matrix::operator-(const Matrix & other)
{
	if(size != other.size) throw invalid_argument("Substraction operaion failed - Matrices are of different size...");

	Matrix newMatrix = Matrix(rows, cols);

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			newMatrix.matrix[i][k] = matrix[i][k] - other.matrix[i][k];
		}
	}

	return newMatrix;
}

Matrix & Matrix::operator*=(int other)
{
	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			matrix[i][k] *= other;
		}
	}

	return *this;
}

Matrix Matrix::operator*(int other)
{
	Matrix newMatrix = Matrix(rows, cols);

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			newMatrix.matrix[i][k] = matrix[i][k] * other;
		}
	}

	return newMatrix;
}

Matrix Matrix::operator*(const Matrix & other)
{
	if(cols != other.rows) throw invalid_argument("Multiplication operaion failed - Matrices not suitable for multiplication...");

	Matrix newMatrix = Matrix(rows, other.cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				newMatrix.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}

	return newMatrix;
}

Matrix& Matrix::operator/=(int other)
{
	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			matrix[i][k] /= other;
		}
	}

	return *this;
}

Matrix Matrix::operator/(int other)
{
	Matrix newMatrix = Matrix(rows, cols);

	for (int i = 0; (size_t)i < matrix.size(); i++)
	{
		for (int k = 0; k < cols; k++)
		{
			newMatrix.matrix[i][k] = matrix[i][k] / other;
		}
	}

	return newMatrix;
}


