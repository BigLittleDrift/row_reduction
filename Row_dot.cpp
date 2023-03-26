extern double** Row_createmat(int, int);

//function to multiply matrixes
//this function isn't very general because of the program requiremens
double** Row_dot(double** I, double** MAT, int R1, int C1, int C2){

	//allocate memory for new matrix
	double** result = Row_createmat(R1, C2);

	//multiplies the matricies
	double dot = 0;
	for (int i=0; i<R1; i++){
		for(int j=0; j<C2; j++){
			dot = 0;
			for(int k=0; k<C1; k++){
				dot += I[i][k]*MAT[k][j];
			}
			result[i][j] = dot;
		}
	}

	//change the pointer MAT
	double** temp = MAT;
	MAT = result;
	delete[] temp;

	return MAT;
}