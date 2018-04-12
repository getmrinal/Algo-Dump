#include <iostream>
#include<math.h>
using namespace std;

bool subsetK(int n,int *arr,int ki){
	bool flag = false;
	int **dp = new int*[n];
	for(int i=0;i<n;i++){
		int nn = pow(2,i);
		dp[i] = new int[nn];
		dp[i][0] = arr[i];
		int k=0;
		int x=0;
		int sum =1;
		for(int j=1;j<nn;j++){
			dp[i][j] = dp[i][0] + dp[x][k];
			k++;
			if(dp[i][j]==ki){
				flag = true;
				return flag;
			}
			if(sum==k){
				x =x+1;
				k=0;
				sum = sum + sum;
			}

		}
	}
	return false;
}

int main(){

	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int s;
	cin>>s;
	bool i = subsetK(n,arr,s);
	if(i==true){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}