#include <iostream>
#include<string>
#include<math.h>
using namespace std;

long long powerModIter(long long a,string b,int MOD){
	long long ans =1;
	while(b.length() > 0){
		int c ;
		//cout<<b<<" ";
		c = b.at(b.length()-1) - '0';
		if(c==1){
			ans = (ans*a)%MOD;
			
			//cout<<c;	
		}else if(c==2){
			ans = (((ans*a)%MOD)*a)%MOD;
		}

		a = (a*(a*a)%MOD)%MOD;
		b = b.substr(0,b.length()-1);
	}
	return ans;
}

int main(){

	long long a,MOD;
	string b;
	cin>>a>>b>>MOD;
	cout<<powerModIter(a,b,MOD);
	return 0;
}