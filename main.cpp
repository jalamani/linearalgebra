#include <iostream>
#include <limits>
#include "linearalgebra.h"
using namespace std;

//Function to print s, get an input x, and ignore non-integer inputs
void coutcin(string s, int &x){
	while (cout << s && !(cin >> x)) {
    	cin.clear(); 
    	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    	cout << "Invalid input; please re-enter.\n";
	}
}

//Function to print the prompt for creating a matrix
Matrix matrixPrompt(){
	int userRows, userColumns, userValue;
	coutcin("Enter number of rows in the matrix:\n", userRows);	
	coutcin("Enter number of columns:\n", userColumns);	
	coutcin("Enter the initial value of the matrix:\n", userValue);
	Matrix d(userRows,userColumns,userValue);
	cout<< "\nHere is your matrix:" <<endl;
	d.printMatrix();
	return d;
}

int main(){
	int userRows, userColumns, userValue, userSelect;	
	bool hasMatrix = false;
	bool cont = true;
	char change;
	cout<< "Welcome to the demo for this linear algebra library. Currently, only matrix operations are available." << endl;
	while(cont){	
		Matrix d = matrixPrompt();
		hasMatrix = true;
		while(hasMatrix){
			coutcin("\nYou can do the following with this matrix.\n"
				"1. Transpose\n"
				"2. Multiply with another matrix\n"
				"3. Enter unique values into this matrix\n"
				"4. Create a new matrix.\n"
				"5. Quit. \n"
				"Enter the number of your choice:\n", userSelect);
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
        		case 5:{
        			hasMatrix = false;
        			cont = false;
        		}
    			default:{
    				continue;
    			}
			}
		}
	}
	return 0;
}