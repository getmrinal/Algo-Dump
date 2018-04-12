#include <iostream>
#include<cmath>
#include<climits>
#include<iomanip>

using namespace std;

double distance(int x,int xx,int y,int yy){
	double ans = (x-xx)*(x-xx) + (y-yy)*(y-yy);
	if(ans < 0){
		ans = -1*ans;
	}
	ans = sqrt(ans);
	return ans;
}
double hasan(int a,int n,int*xi,int*yi,int*fi,int k,double**dp){
	if(a==0){
		
		return fi[0] + hasan(a+1,n,xi,yi,fi,k,dp);
	}
	if(a==n-1){
		return fi[a] - distance(xi[k],xi[a],yi[k],yi[a]); 
	}
	if(dp[a][k] > INT_MIN){
		//cout<<" fbu";
		return dp[a][k];
	}
	
	double one = fi[a] - distance(xi[k],xi[a],yi[k],yi[a]) + hasan(a+1,n,xi,yi,fi,k+1,dp);
	double two = hasan(a+1,n,xi,yi,fi,k,dp);
	double final = max(one,two);
	dp[a][k] = final;
	return final;
}

int main(){

	int n;
	cin>>n;
	int *xi = new int[n];
	int *yi = new int[n];
	int *fi = new int[n];
	for(int i=0;i<n;i++){
		cin>>xi[i]>>yi[i]>>fi[i];
	}
	double**dp = new double *[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new double[n+1];
		for(int j=0;j<=n;j++){
			dp[i][j] =INT_MIN;
		}
	}
	double d = hasan(0,n,xi,yi,fi,0,dp);
	std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << d;
    cout<<endl;
    for(int i=0;i<=n;i++){
	//	dp[i] = new double[n+1];
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
}