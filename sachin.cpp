#include<bits/stdc++.h>
using namespace std;

class Triplet{
public:
	long long gcd;
	long long x;
	long long y;
};

Triplet exEuclid(long long a,long long b){
	if(a<b){
		return exEuclid(b,a);
	}

	if(b==0){
		Triplet myAns;
		myAns.gcd = a;
		myAns.x =1;
		myAns.y=0;
		return myAns;
		
	}

	Triplet smallAns = exEuclid(b,a%b);
	Triplet myAns;
	myAns.gcd = smallAns.gcd;
	myAns.x = smallAns.y;
	myAns.y = (smallAns.x - (smallAns.y * (a/b)));
	return myAns;
}

long long modInverse(long long a,long long m){
	Triplet modAns = exEuclid(a,m);
	return modAns.x;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	long long a,b,d;
	cin>>a>>b>>d;
	
	long long g = __gcd(b,a);
	if(d%g){
		cout<<0<<endl;
		continue;
	}
	if(d==0){
		cout<<1<<endl;
	}


	long long y1 = ((d%a) * modInverse(b,a))%a;
	long long n = (d/b);

	if(d < y1*b){
		cout<<0<<endl;
		continue;
	}


	n = (n-y1)/a;
	cout<<n+1<<endl;
	
	}


	return 0;
}