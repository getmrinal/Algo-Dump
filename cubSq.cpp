#include <iostream>
using namespace std;

int solution(int a,int b,int M){
	if(b==1){
		return a;
	}

	int ans = solution((a*a)%M,b/2,M);
	if(b%2!=0){
		return (a*ans)%M;
	}
	return ans;
}

int main(){

	int a;
	int b;
	int M;
	cin>>a>>b>>M;
	cout<<soluiton(a,b,M);



	return 0;
}