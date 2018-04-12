#include <iostream>
using namespace std;

int main(){

	long long a = 41;
	long long p =1;
	long long n=10;
	for(long long i=0;i<12;i++){
		n = n*p;
		cout<<n%a<<endl;
		p = p*10;
	}



	return 0;
}