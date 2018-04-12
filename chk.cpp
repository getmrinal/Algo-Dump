#include <iostream>
using namespace std;


int powerMod(int a,int b, int MOD){

	if(b==0){
		return 1;
	}

	int ans = powerMod((a*a)%MOD,b/2,MOD);

	if(b%2!=0){
		b = (a*ans)%MOD;
		ans = b;
	}
	return ans;
}


int main(){

	int n;
	int mod;
	cin>>n>>mod;
	if(n<mod){
		int ans = 1;
		while(n<mod-2){
			n = n+1;
			ans = (ans * powerMod(n,mod-2,mod))%mod;
		}
		cout<<ans;


	}else{
		cout<<"0";
	}





	return 0;
}