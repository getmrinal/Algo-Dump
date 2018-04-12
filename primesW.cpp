#include <iostream>
using namespace std;

void makeSieve(int n,bool*arr){
	
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
	
	//return count;
}


int main(){

	int a,b;
	cin>>a>>b;
	bool arr[b+1];
	for(int i=0;i<=b;i++){
		arr[i] = true;
	}
	makeSieve(b,arr);
	//cout<<a;
	int count=0;
	for(int i=a;i<=b;i++){
		if(arr[i]){
			cout<<i<<endl;
			count++;
		}
	}
	cout<<count;

	return 0;
}