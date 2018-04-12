#include <iostream>
using namespace std;


int lbs(int*arr,int n){
	int help[n+1];
	int help2[n+1];
	//help[0] =1;
	//help2[0] = 1;
	for(int i=0;i<n;i++){
		help[i] =1;
		help2[i] =1;
		for(int j = i-1;j>=0;j--){
			if(arr[j] > arr[i]){//lds 
				if(help2[i] <= help2[j]){
					help2[i] = help2[j] +1;
				}
			}else if(arr[j] < arr[i]){//lis
				if(help[i] <= help[j]){
					help[i] = help[j]+1;
				}
			}
		}
	}

	int max = help[0] + help2[0] - 1;
	for (int i = 1; i < n; i++)
		if (help[i] + help2[i] - 1 > max)
			max = help[i] + help2[i] - 1;
	return max;
	
}



int main(){

	//int

	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	} 
	cout<<lbs(arr,n);


	return 0;
}