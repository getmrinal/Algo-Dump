//PRINCESS FARIDA
#include <iostream>
using namespace std;

long long farida(int *arr,int n){
	int maxSum[n];
	for(int i=0;i<n;i++){
		maxSum[i] = arr[i];
		for(int j=i-2;j>=0;j--){
			if(arr[i]+maxSum[j] > maxSum[i]){
	
				maxSum[i] = arr[i] + maxSum[j];
				
			}
		}
	}
	 long long best =0;
	 for(int i=0;i<n;i++){
	 	cout<<maxSum[i]<<" ";
	 	if(best<maxSum[i]){
	 		best = maxSum[i];
	 	}
	 }
	
	return best;
}

int main(){
	int t;
	cin>>t;
	int k=1;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
	
		cout<<"case "<<k<<": "<<farida(arr,n)<<endl;

		k++;
	}

	return 0;
}