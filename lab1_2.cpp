#include <iostream>
#include <ctime>

using namespace std;
#define MAX 3

void multplyMatrices(int (&A)[MAX][MAX], int (&B)[MAX][MAX], int (&matrix)[MAX][MAX]){
//void Mult(int A[][MAX], int B[][MAX], int matrix[][MAX]){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			matrix[i][j]=0;
			for(int k=0;k<MAX;k++){
				matrix[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void showMatrix(int (&MATRIX)[MAX][MAX]){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			cout<<MATRIX[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
}

int main(){
	int A[MAX][MAX], B[MAX][MAX], matrix[MAX][MAX];

	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			A[i][j]=j;
			B[i][j]=MAX-1-j;
			matrix[i][j]=0;
		}
	}
///////////////////////////////////////////////
	showMatrix(A);
	showMatrix(B);
	showMatrix(matrix);

	multplyMatrices(A,B,matrix);

	showMatrix(matrix);


	return 0;
}
