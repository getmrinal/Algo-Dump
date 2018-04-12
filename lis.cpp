#include <iostream>
using namespace std;

int lis(int*arr,int n){
	int help[n+1];
	help[0] =1;
	for(int i=1;i<n;i++){
		help[i] =1;
		for(int j = i-1;j>=0;j--){
			if(arr[j] > arr[i]){
				continue;
			}
			if(help[i] <= help[j]){
				help[i] = help[j]+1;
			}
		}
	}

	int best =0;
	for(int i=0;i<n;i++){
		if(best<help[i]){
			best = help[i];
		}
	}
	return best;               
}


int main(){

	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	} 
	cout<<lis(arr,n);



	return 0;
}