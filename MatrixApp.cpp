#include "Matrix.h"
using namespace std;

int main()
{
	try
	{
		cout << "Creating matrices:\n\n";

		cout << "a:\n";
		Matrix a(2, 2);
		//a.PopulateMatrix();	
		a.DisplayMatrix();

		cout << "b:\n";
		Matrix b(6, 6, 6);
		b.DisplayMatrix();

		cout << "Copying Matrix a to matrix c...\n\n";
		cout << "c:\n";
		Matrix c(a);
		c.DisplayMatrix();

		cout << "Generating matrix from vector<vector<int> >...\n\n";

		srand(time(0));
		vector<vector<int> > v(10);
		for (size_t i = 0; i < v.size(); i++)
		{
			v[i].resize(10);

			for (size_t k = 0; k < v[i].size(); k++)
				v[i][k] = rand();
		}
		cout << "d:\n";
		Matrix d(v);
		d.DisplayMatrix();

		cout << "Updating Matrix Elements...\n\n";
		cout << "e:\n";

		Matrix e(2, 6);
		for (int i = 0; i < e.GetNumOfRows(); i++)
			for (int k = 0; k < e.GetNumOfCols(); k++)
				e.UpdateValue(i, k, rand());
		e.DisplayMatrix();

		cout << "Acessing Matrix element...\n";
		cout << "e[0,3] = " << e(0, 3) << "\n\n";

		cout << "Transposing Matrix...\n\n";
		cout << "Transposed e:";
		Matrix eTransposed = e.Transpose();
		eTransposed.DisplayMatrix();

		cout << "Square Matrix:\n";
		Matrix square({{1,2,3}, {4,5,6}, {7,8,9}});
		cout << "Is it really square? - " << (square.IsSquare() ? "Yes!" : "No!") << "\n";
		square.DisplayDiagonal(MAIN);
		square.DisplayDiagonal(ANTIDIAGONAL);

		cout << "Arithmetic operations:\n\n";
		cout << "m1:\n";
		Matrix m1 = Matrix({{1,2,3}, {4,5,6}, {7,8,9}});
		m1.DisplayMatrix();
		cout << "m2:\n";
		Matrix m2 = Matrix({ {1,2,3},{4,5,6},{7,8,9} });
		m2.DisplayMatrix();
		cout << "m3:\n";
		Matrix m3 = Matrix({ {2,4,6}, {12,8,10}, {22,16,30} });
		m3.DisplayMatrix();
		cout << "m1 + m2:\n";
		(m1 + m2).DisplayMatrix();
		cout << "m1 - m2:\n";
		(m1 + m2).DisplayMatrix();
		cout << "m2 += 10:\n";
		m2 += 10;
		m2.DisplayMatrix();
		cout << "m2 = m1:\n";
		m2 = m1;
		m2.DisplayMatrix();
		cout << "m1 * 5:\n";
		(m1 * 5).DisplayMatrix();
		cout << "m1 * m2:\n";
		(m1 * m2).DisplayMatrix();
		cout << "m3 / 2:\n";
		(m3 / 2).DisplayMatrix();
	}
	catch (const invalid_argument& ex)
	{
		cout << "\n\n\n" << ex.what() << "\n\n\n";
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu