//function to reset the identity matrix

void Row_ireset(int row, double** I){

	for (int i=0; i<row; i++){
		for (int j=0; j<row; j++){
			if (i==j){
				I[i][j] = 1;
			}else{
 				I[i][j] = 0;
			}
		}
	}

	return;
}