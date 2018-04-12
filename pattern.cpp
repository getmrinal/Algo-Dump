#include <iostream>
using namespace std;

int main(){

	int n;
	cin>>n;
	bool *arr = new bool[n];	
	for(int i=2;i<n;i++){
		int k = i;
		while(k<=n){
			arr[k]= false;
			k=k+i;
		}
	}

	return 0;
}