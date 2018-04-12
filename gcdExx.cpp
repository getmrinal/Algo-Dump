#include <iostream>
using namespace std;
#define MAX 1000001
void eulerPhi(int*phi){
	//cout<<"okk2";
	

	for(int i=1;i<=MAX;i++){
		phi[i] = i;
	}

	for(int i=2;i<=MAX;i++){
		if(phi[i] == i){
			phi[i] = i-1;
			for(int j=2*i;j<=MAX;j+=i){
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}	
}

int main(){

	int *etf = new int[MAX+1];
	//cout<<"okk";
	eulerPhi(etf);
	int n=-1;
	//cin>>n;
	while(n!=0){
		//int n;
		cin>>n;
		int result[n+1];
		for(int i=1;i<=n;i++){
			result[i] = 0;
		}
		for(int i=1;i<n;i++){
			for(int j=2;i*j<=n;j++){
				result[i*j] = result[i*j] + i*etf[j];
			}
		}
		long long ans =0;
		for(int i=1;i<=n;i++){
			ans = ans + result[i];
		}
		cout<<"ans"<<ans<<endl;
	}

	return 0;
}