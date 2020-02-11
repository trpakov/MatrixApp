#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

enum Diagonal { MAIN, ANTIDIAGONAL };

class Matrix
{
public:
	Matrix(int rows, int cols);
	Matrix(int rows, int cols, int value);
	Matrix(const Matrix& matrix);
	Matrix(vector<vector<int> > values);
	~Matrix();

	void PopulateMatrix();
	void UpdateValue(int a, int b, int value);
	void DisplayMatrix();
	//int GetValue(int row, int col);
	Matrix Transpose();
	int GetNumOfRows() const;
	int GetNumOfCols() const;
	int GetSize() const;
	bool IsSquare() const;
	vector<int> GetMainDiagonal();
	vector<int> GetAntidiagonal();
	void DisplayDiagonal(Diagonal diagonal);

	int& operator()(int r, int c);
	Matrix& operator=(const Matrix& other);
	Matrix& operator+= (int other);
	Matrix& operator+= (const Matrix& other);
	Matrix operator+ (int other);
	Matrix operator+ (const Matrix& other);
	Matrix& operator-= (int other);
	Matrix& operator-= (const Matrix& other);
	Matrix operator- (int other);
	Matrix operator- (const Matrix& other);
	Matrix& operator*= (int other);
	Matrix operator* (int other);
	Matrix operator* (const Matrix& other);
	Matrix& operator/= (int other);
	Matrix operator/ (int other);


private:
	vector<vector<int> > matrix;
	int rows;
	int cols;
	int size = rows * cols;
	bool isSquare;
};