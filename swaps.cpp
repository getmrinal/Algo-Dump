#include <iostream>
using namespace std;
#define MOD 1000000007
int largestPower(int n,int i){
	int x =0;
	while(n){
		n = n/i;
		x = x+n;
	}
	return x;
}
long long powerMod(long long a,long long b){
	if(b==0){
		return 1;
	}
	
	if(b%2==0){
		return powerMod((a*a)%MOD,b/2);
	}else{
		long long ans = powerMod((a*a)%MOD,b/2);
		return ((a%MOD)*ans)%MOD;
	}
}

void makeSieve(int n,bool*arr){
	//bool arr[n+1];
	for(int i=0;i<=n;i++){
		arr[i] = true;
	}
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
	//return arr;
}
long long findfact(int n){
	bool arr[n+1];
	makeSieve(n,arr);
	long long result = 1;
	for(int i=0;i<=n;i++){
		if(arr[i]){
			int k = largestPower(n,i);
			long long p = powerMod(i,k);
			result = (result * p)%MOD;
		}
	}
	return result;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		
		int a = findfact(n);
		int b = findfact(n-k);
		b = powerMod(b,MOD-2);
		int c = findfact(k);
		c = powerMod(c,MOD-2);
		int d = powerMod(2,k);
		int ans = (((((a*b)%MOD)*c)%MOD)*d)%MOD;
		cout<<ans<<endl;


	}



	return 0;
}