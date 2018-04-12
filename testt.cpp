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
int findfact(long long n,long long MOD){//27 13
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
        //cout<<ans<<endl;
		return ans;
}
int main(){
	int time;
	cin>>time;
	while(time--){
		long long t;
		long long m;
		cin>>t>>m;
		if(t<m){
			cout<< findfact(t,m);
		}else{
			long q = t/m;
			long r = t%m;
			long ans=0;
			if(q%2==0){
				ans = (m-1);
			}else{
				ans =1;
			}
			long long base = q*m;
			for(int i=1;i<=r;i++){
				ans = (ans*(base+i))%m;
			}
			cout<<ans<<endl;
		}
	}




	return 0;
}