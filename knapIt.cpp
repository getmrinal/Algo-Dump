#include <iostream>
using namespace std;


int knapSackIt(int *wt,int *val,int n,int maxLeft){
	int **dp= new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[maxLeft+1];
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}
	for(int i=0;i<=maxLeft;i++){
		dp[0][i] =0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=maxLeft;j++){
			dp[i][j] = dp[i-1][j];
			if(maxLeft >= wt[i-1]){
				dp[i][j] = max(dp[i][j],val[i-1] + dp[i-1][j-wt[i-1]]);
			}
		}
	}
	int ans = dp[n][maxLeft];
	return ans;
}

int knapsnack(int* val,int* wt,int W,int n){
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[W+1];
	}

	for(int i=0;i<=W;i++){
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int w=0;w<=W;w++){

			dp[i][w] = dp[i-1][w];
			if(wt[i-1] <= w){
				dp[i][w] = max(dp[i][w],val[i-1] + dp[i-1][w-wt[i-1]]);
			}
		}
	}

	int ans = dp[n][W];
	//delete dp array 
	return ans;
}

int main(){

	int m;
	cin>>m;
	int *wt = new int[m];
	int *val = new int[m];
	for(int i=0;i<m;i++){
		cin>>wt[i];
	}
	for(int i=0;i<m;i++){
		cin>>val[i];
	}
	int max;
	cin>>max;
	cout<<knapSackIt(wt,val,m,max)<<endl;
	cout<<knapsnack(wt,val,max,m);



	return 0;
}