#include <iostream>
using namespace std;
int sub(int input[],int n,int si,int out[][20]){
	if(si==n){
		out[0][0] = 0;
		return 1;
	}
	int small = sub(input,n,si+1,out);
	for (int i = 0; i < small; i++)
	{
		out[i+small][0] = out[i][0] + 1;
		out[i+small][1] = input[si];
		for (int j = 0; j < count; j++)
		{
			out[i+small][j+1] = out[i][j];
		}
	}
	return 2*small;
}



int subset(int input[],int n,int output[][20]){
	return sub(input,n,0,output);
}
int main(){

	int



	return 0;
}