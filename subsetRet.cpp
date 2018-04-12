#include <iostream>
using namespace std;

int helper(int input[],int si,int n,int output[][20]){
	if(si==n){
		output[0][0] = 0;
		return 1;
	}
	int small = helper(input,si+1,n,output);
	for (int i = 0; i < small; i++){
		
		output[i+small][0]  = output[i][0] +1;
		output[i+small][1] = input[si];
			for (int j = 1; j <= output[i][0]; j++){
				output[i + small][j+1] =  output[i][j];
			}
	}
	return 2*small;

}

int main(){

	int input[] ={1,2,3,4,5,6,7,8};
	int s = 8;
	int output[300][20];
	int size = helper(input,0,s,output);
	for (int i = 0; i < size; i++){
		
		int a = output[i][0];
		for (int j = 1; j <=a; j++){
			
			cout<<output[i][j]<<' ';

		}
		cout<<endl;
	}


	return 0;
}