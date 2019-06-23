#include <iostream>
#include "linearalgebra.h"
using namespace std;

Matrix matrixPrompt(){
	int userRows, userColumns, userValue;
	cout<< "Enter number of rows in the matrix:" << endl;
	cin>>userRows;
	cout<< "Enter number of columns:" << endl;
	cin>>userColumns;
	cout<< "Enter the initial value of the matrix:" << endl;
	cin>> userValue;
	Matrix d(userRows,userColumns,userValue);
	cout<< "\nHere is your matrix:" <<endl;
	d.printMatrix();
	return d;
}

int main(){
	int userRows, userColumns, userValue, userSelect;	
	bool hasMatrix = false;
	int change;
	cout<< "Welcome to the demo for this linear algebra library. Currently, only matrix operations are available." << endl;
	while(1){	
		Matrix d = matrixPrompt();
		hasMatrix = true;
		while(hasMatrix){
			cout<< "\nYou can do the following with this matrix.\n1. Transpose\n2. Multiply with another matrix\n3. Enter unique values into this matrix\n4. Create a new matrix.\nEnter the number of your choice:" << endl;
			cin>>userSelect;
			switch(userSelect){
    			case 1:{
					cout<< "\nHere is your transposed matrix:" <<endl;
    				 d = d.transpose();
    				 d.printMatrix();
    				 break;
        		}
    			case 2:{
    				cout<< "\nCreate another matrix to multiply with." <<endl;
    				Matrix e = matrixPrompt();
    				cout<< "\nWould you like to enter unique values into this matrix? [y/n]" <<endl;
    				cin>>change;
    				if(change == 89 || change == 121) e.setEach();
    				cout<< "Here is your multiplied matrix:" <<endl;
    				d = d.matrixMultiply(e);
    				d.printMatrix();
    				break;
        		}
        		case 3:{
        			d.setEach();
        			d.printMatrix();
        			break;
        		}
        		case 4:{
        			hasMatrix = false;
        			break;
        		}
    			default:{
    				continue;
    			}
			}
		}
	}
	return 0;
}