#include <iostream>
using namespace std;

void printS(int **sudoku){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<sudoku[i][j]<<' ';
		}
		cout<<endl;
	}
}

bool isSafe(int**sudoku,int row,int col,int number){
	for(int i=0;i<9;i++){
		if(sudoku[row][i] == number){//checked row
			return false;
		}
	}
	for(int i=0;i<9;i++){
		if(sudoku[i][col] == number){//checked row
			return false;
		}
	}
	//check the nonet!!!
	//0 0 0
	//0 0 0 
	//0 0 0
	row = row - row%3;
	col = col - col%3;
	 for (int i = 0; i < 3; i++){
	 		for (int j = 0; j < 3; j++){
	 			if (sudoku[i + row][j + col] == number)
                return false;
	 		}    
	 }
        
	
	return true;

}


bool solve(int **sudoku,int row=0,int c =0){
	if(c==9 && row==8){
		printS(sudoku);
		return true;
	}else if(c==9){
		row = row+1;
		c = 0;
	}
		if(sudoku[row][c] == 0){
			//cout<<'#';
			for(int i=1;i<10;i++){
				//cout<<'$';
				if(isSafe(sudoku,row,c,i)){
					//cout<<'%';
					sudoku[row][c] = i;
					if(solve(sudoku,row,c+1)){
						
						return true;
					}
					sudoku[row][c] = 0;
				}
			}
		}else{
			//cout<<'*';
			if(solve(sudoku,row,c+1)){
				return true;
			}
		}

	return false;

	

}

int main(){

	int n = 9;
	int **sudoku = new int*[n];
	for(int i=0;i<n;i++){
		sudoku[i] = new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>sudoku[i][j];
		}
	}

	cout<<solve(sudoku);



	return 0;
}