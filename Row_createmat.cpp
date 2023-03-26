//function to create pointer**

double** Row_createmat(int row, int col){

	double** ptr = new double*[row];
	for (int i=0; i<row; i++){
		ptr[i] = new double[col];
	}

	//saftey first kids
	for (int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			ptr[i][j] = 0;
		}
	}

	return ptr;
}