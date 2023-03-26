//funciton to check that the identy is infact different

bool Row_icheck(double** I, double** I_U, int row){
	for(int i=0; i<row; i++){
		if(I[i][i] != I_U[i][i]){
			return 0;
		}
	}
	return 1;
}