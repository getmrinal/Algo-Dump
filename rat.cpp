#include <iostream>
using namespace std;
void printPath(int**soln,int n){
	for (int i = 0; i < n; i++){
		for(int j=0;j<n;j++){
			cout<<soln[i][j]<<' ';
		}
	}
}
//pass default parameter of the coordinates of point 
void path(int**soln,int**maze,int n,int row=0,int col=0){
	if(row==n-1 && col == n-1){
		soln[row][col]=1;
		printPath(soln,n);
		cout<<endl;
		return;
	}
	//up  down right left i.e, n+1,n-1 for both row & col
	if(row>=n || row<0||col>=n-1 || col<0||maze[row][col] == 0||soln[row][col]==1){
		return;
	}
		soln[row][col] =1;
		path(soln,maze,n,row-1,col);
		path(soln,maze,n,row+1,col);
		path(soln,maze,n,row,col-1);
		path(soln,maze,n,row,col+1);
		soln[row][col] =0;
	
}




int main(){
	int n;
	cin>>n;

	int** maze = new int*[n];
	for(int i=0;i<n;i++){
		maze[i] = new int[n];
	}
	for (int i = 0; i < n; i++){
		for(int j=0;j<n;j++){
			cin>>maze[i][j];
		}
	}
	int **soln = new int*[n];
	for(int i=0;i<n;i++){
		soln[i] = new int[n];
	}
	for (int i = 0; i < n; i++){
		for(int j=0;j<n;j++){
			soln[i][j] = 0;
		}
	}
	//soln[0][0] =1;//starting point
	path(soln,maze,n);


	return 0;
}