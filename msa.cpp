#include <iostream>
using namespace std;

int kadine(int *arr,int size){
	int best=0;
	int curr_best =0;
	for(int i=0;i<size;i++){
	 	curr_best = curr_best +arr[i];
	 	if(best < curr_best){
	 		best = curr_best;
	 	}
	 	if(curr_best < 0){
	 		curr_best =0;
	 	}
	}

	return best;
}


int main(){

	int size;
	cin>>size;
	int *arr  = new int [size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	cout<<maxSumArr(arr,size);


	return 0;
}