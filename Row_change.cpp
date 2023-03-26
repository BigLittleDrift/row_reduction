//function to generate the identiy matrix
void Row_change(int x, int y, int row, double** I, double** I_U){

	for (int i=0; i<row; i++){
		I_U[x][i] = I[y][i];
		I_U[y][i] = I[x][i];
	}	

	return;
}