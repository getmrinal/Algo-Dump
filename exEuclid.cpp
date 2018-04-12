#include <iostream>
using namespace std;

class Triplet{
public:
	int gcd;
	int x;
	int y;
};

Triplet exEuclid(int a,int b){
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

void modInverse(int a,int m){
	Triplet modAns = exEuclid(a,m);
	cout<<modAns.x<<endl;
}

int main(){

	int a,b;
	cin>>a>>b;
	modInverse(a,b);
	// Triplet myAns = exEuclid(a,b);
	// cout<<myAns.gcd<<endl;
	// cout<<myAns.x<<endl;
	// cout<<myAns.y<<endl;



	return 0;
}