#include <iostream>
#include "linearalgebra.h"
using namespace std;

int main(){
	int userRows, userColumns, userValue;
	cout<< "Create a matrix." << endl;
	cout<< "Enter number of rows in the matrix:" << endl;
	cin>>userRows;
	cout<< "Enter number of columns:" << endl;
	cin>>userColumns;
	cout<< "Enter intial value of matrix:" << endl;
	cin>> userValue;
	Matrix d(userRows,userColumns,userValue);
	cout<< "Here is your matrix:" <<endl;
	d.printMatrix();


	Matrix e = d.transpose();
	cout<< "Here is your transposed matrix:" <<endl;
	e.printMatrix();
	cout<< "Here is your multiplied matrix:" <<endl;

	Matrix t = d.matrixMultiply(e);
	t.printMatrix();
	
	return 0;
}