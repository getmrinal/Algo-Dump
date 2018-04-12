#include <iostream>
using namespace std;

void eulerSieve(int n){
	int *a = new int [n];

	for(int i=0;i<=n;i++){a[i]=i;}

	for(int i=2;i<=n;i++){
		if(a[i]==i){
			a[i] = i-1;
			int j=i;
			while(j<=n){
				j= j+i;
				a[j] = (a[j] *(i-1))/i;
			}
		}
	}
	for(int i=0;i<=n;i++){
		cout<<a[i]<<" ";
	}

}



int main(){

	int n;
	cin>>n;
	eulerSieve(n);
	cout<<"okk";


	return 0;
}