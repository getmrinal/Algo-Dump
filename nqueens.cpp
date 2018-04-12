#include <iostream>
using namespace std;
void printSoln(int**chess,int n){
	for (int i = 0; i < n; i++){
		for(int j=0;j<n;j++){
			cout<<chess[i][j];
		}
	}
}
bool isSafe(int **chess,int row,int col,int n){

	 int i, j;
 
    for (i = 0; i < col; i++)
        if (chess[row][i])
            return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (chess[i][j])
            return false;
 
    for (i=row, j=col; j>=0 && i<n; i++, j--)
        if (chess[i][j])
            return false;
 
    return true;

}
bool solve(int **chess,int col,int n){
	if(col==n){
		printSoln(chess,n);
		cout<<endl;
		return true;
	}
	for(int i=0;i<n;i++){
		if(isSafe(chess,i,col,n)){
			chess[i][col] = 1;
			solve(chess,col+1,n);
			
			chess[i][col] = 0;
		}
	}
	return false;
}

void nqueens(int n){
	int **chess = new int*[n];
	for(int i=0;i<n;i++){
		chess[i] = new int[n];
	}
	for (int i = 0; i < n; i++){
		for(int j=0;j<n;j++){
			chess[i][j] = 0;
		}
	}
	solve(chess,0,n);
	return;
	
}


int main(){

	int n;
	cin>>n;
	nqueens(n);
	return 0;
}