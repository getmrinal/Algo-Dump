#include <iostream>
using namespace std;


//b->b/2->b/4->b/8->b/16.........1 or 0
int power(int a,int b){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	if(b%2==0){
		return power(a*a,b/2);
	}else{
		int ans = power(a*a,(b-1)/2);
		return ans*a;
	}
}
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

long long powerModIter(long long a,long long b,int MOD){
	long long ans =1;
	while(b>0){
		int c = b;
		//cout<<b<<" ";
		if(c&1 == 1){
			ans = (ans*a)%MOD;
			
			//cout<<c;
			
		}
		a = (a*a)%MOD;
		b = b/2;
	}
	//cout<<" "<<b;
	return ans;
}

void helper(int x,int n,int &ans){
	if(n==0){
		return;
	}
	ans = ans*x;
	helper(x,n-1,ans);
}


int main(){
//x^n 2^3=8
	long long x;
	cin>>x;
	long n;
	cin>>n;
	int ans=1;
	//helper(x,n,ans);
	int MOD = 1000000007;
	cout<<powerMod(x,n,MOD)<<endl;
	cout<<powerModIter(x,n,MOD)<<endl;
	cout<<power(x,n);
	//cout<<ans;



	return 0;
}