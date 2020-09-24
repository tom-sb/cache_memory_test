#include <iostream>
#include <ctime>

using namespace std;
#define MAX 3

void Mult(int (&A)[MAX][MAX], int (&B)[MAX][MAX], int (&matrix)[MAX][MAX]){
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

int main(){
	int A[MAX][MAX], B[MAX][MAX], matrix[MAX][MAX];
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			A[i][j]=j;
			B[i][j]=MAX-1-j;
			matrix[i][j]=0;
		}
	}

	
/*
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			cout<<A[i][j];
		}
		cout<<endl;
	}
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			cout<<B[i][j];
		}
		cout<<endl;
	}
*/
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"**************************************"<<endl;
	Mult(A,B,matrix);

	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
