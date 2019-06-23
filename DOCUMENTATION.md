# Linear Algebra Library Documentation



## Constructors


### Matrix Default Constructor
	
	Matrix m();

###### Description

Initializes *m* as a 1 x 1 matrix with the element set to 0.

### Matrix Two Parameter Constructor
	
	Matrix m(r, c);

###### Description

Initializes *m* as an *r* x *c* matrix with all elements set to 0. If *r* or *c* are lower than 1, will initialize *m* as 1x1.

##### Parameters	

- *r*: Integer representing the number of rows in the matrix.
- *c*: Integer representing the number of columns in the matrix.

### Matrix Three Parameter Constructor
	
	Matrix m(r, c, value);

###### Description
	
Initializes *m* as an *r* x *c* matrix with all elements set to *value*. If *r* or *c* are lower than 1, will initialize *m* as 1x1.

##### Parameters	

- *r*: Integer representing the number of rows in the matrix.
- *c*: Integer representing the number of columns in the matrix.
- *value*: Integer representing the value set to each element of the matrix.

## Functions


### Get Row
	
	m.getrow();

###### Description

Returns the number of rows of matrix *m* as an integer.

### Get Column
	
	m.getcolumn();

###### Description

Returns the number of columns of matrix *m* as an integer.

### Set Value at Indices
	
	m.setIndices(r, c, value);

##### Description
	
Assigns *value* to (*r*, *c*) in matrix *m*. If *r* or *c* are out of bounds, will display error message and *value* will not be assigned.

##### Parameters	

- *r*: Integer representing the row used to index the matrix.
- *c*: Integer representing the column used to index the matrix.
- *value*: Integer representing the value to be assigned.

### Print Matrix
	
	m.printMatrix();

###### Description

Prints matrix *m*.

### Transpose Matrix
	
	m.transpose();

##### Description
	
Returns a matrix that is *m* transposed.

### Multiply Matrices
	
	m.matrixMultiply(m2);

##### Description
	
Returns a matrix that is the product of *m* and *m2*. If *m* and *m2* cannot be multiplied due to their sizes, will return *m*.

##### Parameters	

- *m2*: Second Matrix to be multiplied with *m*.




	
