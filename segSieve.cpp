#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
#define MAX 100001
vector<int> makeSieve(){
	bool arr[MAX];
	for(int i=0;i<=MAX;i++){
		arr[i] = true;
	}
	//arr[0] = false;
	//arr[1] = false;

	//filter prime
	for(int i=2;i*i<MAX;i++){
		if(arr[i]){
			for(int j=i*i;j<MAX;j = j+i){
				arr[j] = false;
			}
		}
	}

	vector<int> v;
	//int count =0;
	v.push_back(2);
	for(int i=3;i<MAX;i=i+2){
		if(arr[i]){
			v.push_back(i);
		}
	}
	return v;
}

//from l to u remove all the  multiples of prime

void segSieve(long long	l,long long u,vector<int> v){
	long long s = u-l;
	bool arr[s+1];
	for(int i=0;i<=s;i++){
		arr[i] = true;
	}
	//arr[0] = false;
	//arr[1] = false;

	for(int i=0;v.at(i)*v.at(i) <= u;i++){
		int cPrime = v.at(i);
		long long bVal = (l/cPrime)*cPrime;
		if(bVal<l){
			bVal = bVal + cPrime;
		}
		for(long long j = bVal ;j<=u;j+= cPrime){
			arr[j-l] = false;
		}
		if(bVal== cPrime){
			arr[bVal-l] = true;
		}
	}

	for(int i=0;i<=s;i++){
		if(arr[i]==true){
			cout<<i+l<<endl;
		}
	}


}


int main(){

	vector<int> primes = makeSieve();
	int t;
	cin >> t;
	while(t--){
		long long l,r;
		cin>>l>>r;
		segSieve(l,r,primes);
	}





	return 0;
}