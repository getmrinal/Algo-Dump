#include <iostream>
using namespace std;

void printSoln(int**chess,int n){
	for (int i = 0; i < n; i++){
		for(int j=0;j<n;j++){
			cout<<chess[i][j];
		}
		cout<<endl;
	}
}
bool isSafe(int **chess,int row,int col,int n){
	//1. check that row for any unSafe positon
	//2. check that column for any unSafe position
	//3. check diagonals
	//4.as we are going from start or u can say left or one corner of matrix we are pretty sure that the points
	//after chess[row][col] is an uncharted territroy so we are noo gonna check that
	for(int i=0;i<row;i++){
		if(chess[i][col]){
			return false;
		}
	}
	// for(int i=0;i<col;i++){
	// 	if(chess[row][i]){
	// 		return false;
	// 	}
	// }
	for(int i=row,j=col;i>=0 && j>=0;i--,j--){
		if(chess[i][j]){
			return false;
		}
	}
	for(int i=row,j=col;i>=0 && j<n;i--,j++){
		if(chess[i][j]){
			return false;
		}
	}
	return true;

}

bool solve(int **chess,int n,int row=0){
	if(row>=n){
		printSoln(chess,n);
		cout<<endl;
		return true;
	}
	for(int i=0;i<n;i++){
		if(isSafe(chess,row,i,n)){
			chess[row][i] = 1;

			solve(chess,n,row+1);

			chess[row][i] =0;
		}
	}
	return false;
}

void nqueen(int n){
	int **chess = new int*[n];
	for(int i=0;i<n;i++){
		chess[i] = new int[n];
	}
	for (int i = 0; i < n; i++){
		for(int j=0;j<n;j++){
			chess[i][j] = 0;
		}
	}
	solve(chess,n);
}


int main(){

	int n;
	cin>>n;
	nqueen(n);



	return 0;
}