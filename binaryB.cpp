#include <iostream>
#include <cmath>
using namespace std;

int helper(int n){
	if(n==1){
		return 1;
	}
	if(n==2){
		return 3;
	}
	int mod = (int)pow(10,9) + 7;
	int smallOne = (helper(n-1));
	int smallTwo = helper(n-2);

	int x = (int)(((long long)smallOne*smallOne)% mod);
	int y = (int)(((long long)smallOne*smallTwo*2)%mod);
	
	int ans = (long long)(((long long)(x) + y)%mod);
	return ans;


}


int main(){

	int n;
	cin>>n;
	cout<<helper(n);



	return 0;
}
