#include <iostream>
using namespace std;

int helper(int a,int b){
  if(b==0){
    return a;
  }
  return helper(b,a%b);
  
}

int fgcd(int a,int b){
	int x,y;
  if(a<=b){
    x=b;
	y=a;
  }else{
    x=a;
    y=b;
  }
 int k = helper(x,y);
  return k;
}

void gcd(int n,int *a,int**dp){

	dp[0][0] = 1;
	for(int i=1;i<n;i++){
		cout<<a[i]<<endl;
		for(int j=0;j<=i;j++){
			if(a[i]>a[j]){
				 for(int k=0;k<a[i];k++){
				 	int m = fgcd(a[i],k+1);
				 	dp[i][m] = 1 + dp[j][k];
				 	cout<<i<<" "<<j<<" "<<k<<" "<<m<<" "<<dp[i][m]<<" "<<dp[j][k]<<endl;
				 }
			}
		}
	}
}

int main(){

	int n;
	cin>>n;
	int**dp = new int*[n];
	int*input = new int[n];
	for(int i=0;i<n;i++){
		dp[i] = new int[100];
		cin>>input[i];
		for(int j=0;j<100;j++){
			dp[i][j] = 0;
		}
	}
	
	gcd(n,input,dp);
	// for(int i=0;i<n;i++){
	// 	for(int j=1;j<=100;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }
	int sum =0;
	for(int i=0;i<n;i++){
		cout<<i<<": "<<dp[i][1]<<endl;
		sum = sum + dp[i][1];		
	}
	cout<<sum;
	return 0;
}