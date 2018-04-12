#include <iostream>

using namespace std;
#define MAX 1000005
int * makeSieve(){
//1 to 10^6
	int *arr = new int[MAX];
	for(int i=0;i<MAX;i++){
		arr[i]= 0;
	}
	for(int i=2;i<MAX;i++){
		if(arr[i]==0){
			arr[i] =arr[i] +1;
			int k = i;
			k = k+i;
			while(k<= MAX){
				arr[k] = arr[k]+1;
				k = k+i;
			}
		}
	}
	return arr;
}


int main(){

	int *arr =makeSieve();
	// for(int i=0;i<100;i++){
	// 	cout<<i<<" "<<arr[i]<<endl;
	// }
	int t;
	cin>>t;
	while(t--){
		int n;
		long long a,b;
		cin>>a>>b;
		cin>>n;
		int count;
		count =0;
		for(int i=a;i<=b;i++){
			if(arr[i]==n){
				count++;
			}
		}
		cout<<count<<endl;
	}


	return 0;
}