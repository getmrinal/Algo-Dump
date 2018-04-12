#include <iostream>
using namespace std;

void phi(long long n,long long *etf){
	
	for(long long i=1;i<=n;i++){
		etf[i] = i;
	}
	for(long long i=2;i<=n;i++){
		if(etf[i]==i){
			etf[i] = i-1;
			long long k =i;
			while(k<=n){
				k=k+i;
				etf[k] = (etf[k]*(i-1))/i;
				
			}
		}
	}


}


long long lcmSum(long long n){
	long long *etf = new long long [n+1];
	phi(n,etf);
	long long ans =0;
	for(long long i=1;i<=n;i++){
		if(n%i==0){
			ans = ans + (etf[i] *i);
		}
	}
	ans = ans +1;
	ans = ans * n/2;
	return ans;
}

long long main(){

	long long n;
	cin>>n;
	cout<<lcmSum(n);



	return 0;
}