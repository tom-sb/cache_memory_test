#include <iostream>
#include <ctime>

using namespace std;
#define MAX 100

void reSet(double (&A)[MAX][MAX], double (&B)[MAX][MAX], double (&matrix)[MAX][MAX]){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			A[i][j]=j+1;
			B[i][j]=MAX-j;
			matrix[i][j]=0;
		}
	}

}

void multplyMatrices(double (&A)[MAX][MAX], double (&B)[MAX][MAX], double (&matrix)[MAX][MAX]){
//void Mult(double A[][MAX], double B[][MAX], double matrix[][MAX]){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			matrix[i][j]=0;
			for(int k=0;k<MAX;k++){
				matrix[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void showMatrix(double (&MATRIX)[MAX][MAX]){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			cout<<MATRIX[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
}

void blockMultiplyMatrices(double (&A)[MAX][MAX], double (&B)[MAX][MAX], double (&matrix)[MAX][MAX], int blockSize){
	int i,j,k,ii,jj,kk;
	for(i = 0 ; i < MAX ; i +=blockSize){
		for(j = 0 ; j < MAX ; j += blockSize){
			for(k = 0 ; k < MAX ; k += blockSize){
				for(ii = i ; ii < i + blockSize ; ii++){
					for(jj = j ; jj < j + blockSize ; jj++){
						for(kk = k ; kk < k + blockSize ; kk++){
							matrix[ii][jj] += A[ii][kk] * B[kk][jj];
						}
					}
				}
			}
		}
	}
}

int main(){
	double A[MAX][MAX], B[MAX][MAX], matrix[MAX][MAX];
	/*
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			A[i][j]=j;
			B[i][j]=MAX-1-j;
			matrix[i][j]=0;
		}
	}
	*/
	reSet(A,B,matrix);
	clock_t start, start2;

///////////////////////////////////////////////
//	showMatrix(A);
//	showMatrix(B);
//	showMatrix(matrix);

	cout<<"********************************************"<<endl;
	start = clock();
	multplyMatrices(A,B,matrix);
	cout<<"time: "<<clock() - start / (double)(CLOCKS_PER_SEC / 1000) << "ms" << endl;
	//showMatrix(matrix);


	cout<<"********************************************"<<endl;
	reSet(A,B,matrix);
	start2 = clock();
	blockMultiplyMatrices(A,B,matrix,100);
	cout<<"time: "<<clock() - start2 / (double)(CLOCKS_PER_SEC / 1000) << "ms" << endl;
	//showMatrix(matrix);
	

	return 0;
}
