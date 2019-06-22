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
		Matrix(int r, int c, int value){
			row = r;
			column = c;
			dynamic2DArray();
			for (int i = 0; i < row; ++i) {
        		for (int j = 0; j < column; ++j) {
            		pointer[i][j] = value;
        		}
			}
		}
		Matrix(int r, int c){
			row = r;
			column = c;
			dynamic2DArray();
		}
		Matrix(){
			row = 1;
			column = 1;
			dynamic2DArray();
			pointer[0][0] = 0;
		}

		//Functions
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
				std::cout<< "Matrix multiplication can only be done if the number of columns in the first matrix is equal to the number of rows in the second. " <<std::endl;
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
		int getrow(){
			return row;
		}
		int getcolumn(){
			return column;
		}
		void setIndices(int r, int c, int value){
			pointer[r][c] = value;
		}
		void printMatrix(){
			for (int i = 0; i < row; ++i){
        		for (int j = 0; j < column; ++j){
            		std::cout << pointer[i][j] << ' ';
        		}
        		std::cout << std::endl;
    		}
		}
		


};



#endif