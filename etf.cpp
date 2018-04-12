#include <iostream>
using namespace std;

void makeEulerTotient(int n){
	int *etf = new int [n+1];
	for(int i=1;i<=n;i++){
		etf[i] = i;
	}
	for(int i=2;i<=n;i++){
		if(etf[i]==i){
			etf[i] = i-1;
			int k =i;
			while(k<=n){
				k=k+i;
				etf[k] = (etf[k]*(i-1))/i;
				
			}
		}
	}

	for(int i=1;i<=n;i++){
		cout<<etf[i]<<" ";
	}

}

int main(){

	int n;
	cin>>n;
	
	makeEulerTotient(n);
	return 0;
}
