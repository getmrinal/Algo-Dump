#include <iostream>
using namespace std;

int makeSieve(int n){
	bool arr[n+1];
	for(int i=0;i<=n;i++){
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;

	//filter prime
	for(int i=2;i*i<=n;i++){
		if(arr[i]){
			for(int j=i*i;j<=n;j = j+i){
				arr[j] = false;
			}
		}
	}

	int count =0;
	for(int i=0;i<=n;i++){
		if(arr[i]){
			count++;
		}
	}
	return count;
}


int main(){

	int n;
	cin>>n;
	 n = makeSieve(n);
	cout<<n;



	return 0;
}
