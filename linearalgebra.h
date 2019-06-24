#ifndef LINEARALGEBRA_H_
#define LINEARALGEBRA_H_

class Matrix{
		int row;
		int column;
		int **pointer;

		//Memory Allocation function
		void dynamic2DArray(){
    		pointer = new int*[row];
    		for (int i = 0; i < row; ++i) {
        		pointer[i] = new int[column];
    		}
		}


	public:
		//Constructors
		Matrix(){
			row = 1;
			column = 1;
			dynamic2DArray();
			pointer[0][0] = 0;
		}
		Matrix(int r, int c){
			if(r<1 || c<1){
				std::cout<< "Assigned impossible dimensions. Initializing default matrix size of 1x1."<< std::endl;
				row = 1;
				column = 1;
			}
			else{
				row = r;
				column = c;
			}
				dynamic2DArray();
		}
		Matrix(int r, int c, int value){
			if(r<1 || c<1){
				std::cout<< "Assigned impossible dimensions. Initializing default matrix size of 1x1."<< std::endl;
				row = 1;
				column = 1;
			}
			else{
				row = r;
				column = c;
			}
			dynamic2DArray();
			for (int i = 0; i < row; ++i) {
        		for (int j = 0; j < column; ++j) {
            		pointer[i][j] = value;
        		}
			}
		}
		

		//Functions		
		int getrow(){
			return row;
		}
		int getcolumn(){
			return column;
		}
		void setIndices(int r, int c, int value){
			if(r>0 && r<row && c>0 && c<column)
				pointer[r][c] = value;
			else
				std::cout<<"Assigned indices are out of bounds."<<std::endl;
		}		
		void printMatrix(){
			for (int i = 0; i < row; ++i){
        		for (int j = 0; j < column; ++j){
            		std::cout << pointer[i][j] << ' ';
        		}
        		std::cout << std::endl;
    		}
		}
		Matrix transpose(){
			Matrix mT(column, row);
			for (int i = 0; i < row; ++i) {
        		for (int j = 0; j < column; ++j) {
            		mT.pointer[j][i] = pointer[i][j];
        		}
			}
			
			return mT;
		}
		Matrix matrixMultiply(Matrix b){
			if(column != b.row){
				std::cout<< "\nMatrix multiplication can only be done if the number of columns in the first matrix is equal to the number of rows in the second.\n " <<std::endl;
				return *this;
			}
			Matrix c(row, b.column);
			for (int i = 0; i < c.row; ++i) {
        		for (int j = 0; j < c.column; ++j) {
            		for(int k = 0; k < column; ++k){
               			c.pointer[i][j] += pointer[i][k] * b.pointer[k][j];
            		}
        		}
			}
			return c;
		}
		void setEach(){
			for(int k = 0; k < row; ++k){
				for(int h = 0; h < column; ++h){
					for (int i = 0; i < row; ++i){
        				for (int j = 0; j < column; ++j){
        					if(i==k && j==h)
        						std::cout << "x" << ' ';        					
        					else
            					std::cout << pointer[i][j] << ' ';
        				}
        				std::cout << std::endl;
    				}
    				std::cout << "Enter a value to be placed at the x:" << std::endl;
    				std::cin >> pointer[k][h];
				}
			}
		}


};



#endif