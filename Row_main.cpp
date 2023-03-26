//function to row reduce matrix
#include <iostream>

using namespace std;

extern void Row_change(int, int, int, double**, double**);
extern double** Row_dot(double**, double**, int, int, int);
extern double** Row_createmat(int, int);
extern void Row_ireset(int, double**);
extern bool Row_icheck(double**, double**, int);

//Function performs row operations on a matrix

double** Row_main(int row, int col, double** MAT){

	//create identities
	double** I = Row_createmat(row, row);
	Row_ireset(row, I);
	double** I_U = Row_createmat(row, row);
	Row_ireset(row, I_U);

	//while loop to perform operations
	int i = 0;
	int j = 0;
	int flag = 0;
	int index = 0;
	bool check = 1;
	double row_op = 0; 
	while (i<row && j<col){

		//nested while loop for the zeros
		while(MAT[i][j] == 0){
			flag = 0;
			//checks column for number
			for (int z=j; z<col; z++){
				for (int t=i; t<row; t++){
					//super if statments
					if (MAT[t][z] != 0){
						index = t;

						if(i==t && z>j){
							//pivot is behind entry?
							flag = 1;
							j = z;
							break;

						}else if(t>i && z==j){
							//pivot is below current entry
							flag = 1;
							Row_change(i, index, row, I, I_U);
							break;

						}else if(t>i && z>j){
							//pivot is below and behind entry
							flag = 1;
							Row_change(i, index, row, I, I_U);
							j=z;
							break;

						}
					}
				}
				//kick me out of the second loop
				if (flag == 1){
					break;
				}	
			}

			//check that its not the identiy - breaks the nested while loop
			if(Row_icheck(I, I_U, row)){
				break;
			}

			//apply changes to the matrix to ensure the pivot is being acted on
			MAT = Row_dot(I_U, MAT, row, row, col);

			//check for zero row - breaks the nested while loop
			check = 1;
			for (int u=0; u<col; u++){
				if (MAT[i][u] != 0){
					check = 0;
					break;
				}
			}
			if (check){
				break;
			}

			//reset matrix
			Row_ireset(row, I_U);
		}

		//pivot maker
		if (MAT[i][j] != 1 && MAT[i][j] != 0){
			Row_ireset(row, I_U);

			//building new identity
			row_op = 1/MAT[i][j];
			for (int i1=0; i1<row; i1++){
				I_U[i][i1] = row_op*I_U[i][i1];
			}

			//cpp cant round
			if (row_op > 1e10 || row_op < -1e10){
				cout<<"cpp can't round"<<endl;
				return MAT;
			}

			MAT = Row_dot(I_U, MAT, row, row, col);
		}

		//use pivot to eliminate entries
		for (int k=0; k<row; k++){
			Row_ireset(row, I_U);
	
			if (k != i && MAT[k][j] != 0 && MAT[i][j] != 0){
				row_op = MAT[k][j];
				I_U[k][i] = -row_op;
				
				MAT = Row_dot(I_U, MAT, row, row, col);
			}
		}

		Row_ireset(row, I_U);
		//needs to be at end because matlab is super gay
		i++;
		j++;
	}


	//free intentity pointers
	for (int random_name=0; random_name<row; random_name++){
		delete [] I[random_name];
		delete [] I_U[random_name];
	}
	delete [] I;
	delete [] I_U;

	return MAT;
}