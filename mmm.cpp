#include <iostream>
using namespace std;
#define MOD 1000
int Modulo(int n){
	if(n==1){
		return 2;
	}
	int ans = (2 * Modulo(n-1))%MOD;
	return ans;
}

int main(){

	int n;
	cin>>n;
	cout<<Modulo(n);



	return 0;
}