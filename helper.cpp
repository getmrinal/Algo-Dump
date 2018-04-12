#include <iostream>
using namespace std;
long long powerMod(long long a,long long b,int MOD){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	//cout<<"ok3";
	long long ans = (a*a)%MOD;
	if(b%2!=0){
		return powerMod((ans*a)%MOD,(b-1)/2,MOD);
	}
	return powerMod(ans,b/2,MOD);
}


long long convertDeci(int a,string e,int size,int t,int MOD){
	if(t==1){
		if((e.at(0)-'0'==0)){
			return 1;
		}else{
			return powerMod(a,(powerMod(3,size-t,MOD)*(e.at(0)-'0'))%MOD,MOD);
		}
		
	}
	if((e.at(0)-'0'==0)){
			return 1* convertDeci(a,e.substr(0,t-1),size,t-1,MOD);
	}else{
		long long result = (powerMod(a,(powerMod(3,size-t,MOD)*(e.at(t-1)-'0'))%MOD,MOD) * convertDeci(a,e.substr(0,t-1),size,t-1,MOD))%MOD;
		return result;
	}
	

}
int main(){
	int t;
	cin>>t;
	while(t--){	
	int a;
	cin>>a;
	string e;//2111022101 into decimal
	cin>>e;
	int MOD;
	cin>>MOD;
	long long ans = convertDeci(a,e,e.length(),e.length(),MOD);
	cout<<ans<<endl;
	
	}
	return 0;
}