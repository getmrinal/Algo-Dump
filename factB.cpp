#include <iostream>
using namespace std;


long long powerMod(long long a,long long b,int MOD){
	if(b==0){
		return 1;
	}
	
	if(b%2==0){
		return powerMod((a*a)%MOD,b/2,MOD);
	}else{
		long long ans = powerMod((a*a)%MOD,b/2,MOD);
		return ((a%MOD)*ans)%MOD;
	}
}
void findfact(long long n,long long MOD){
	long long ans=1;
		if(MOD > n){
          while(n<MOD-2){
			 n = n+1;
			 ans = (ans * powerMod(n,MOD-2,MOD))%MOD;
			 //cout<<ans<<" ";
			}
        }else{
          ans =0;
        }
		cout<<ans<<endl;
}
int main(){
		int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long MOD;
		cin>>MOD;
		findfact(n,MOD);	
	}
	


	return 0;
}