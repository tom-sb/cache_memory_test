#include <iostream>
#include <ctime>

using namespace std;
int main(){
	int MAX = 1000;
	double A[MAX][MAX], x[MAX], y[MAX];

/*First pair of loops*/
	clock_t start, start2;
	start = clock();
	for(int i = 0;i<MAX;i++)
		for(int j = 0;j<MAX;j++)
			y[i] += A[i][j] * x[j];
	cout<<"time: "<<clock() - start / (double)(CLOCKS_PER_SEC / 1000) << "ms" << endl;	
/*Second pair of loops*/
	start2 = clock();
	for(int j= 0;j<MAX;j++)
		for(int i= 0;i<MAX;i++)
			y[i] += A[i][j] * x[j];
	cout<<"time: "<<clock() - start2 / (double)(CLOCKS_PER_SEC / 1000) << "ms" << endl;

	return 0;
}
