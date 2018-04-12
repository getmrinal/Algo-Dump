#include <iostream>
#include<vector>
using namespace std;

int KnapSack(int val[], int wt[], int n, int W)
{
	vector<int> v;
	int dp[W+1];
	
	//initially profit with 0 to W KnapSack capacity is 0
	for(int i=0;i<=W;i++){
		dp[i]=0;
	}

	// iterate through all items
	for(int i=0; i < n; i++) {
			//traverse dp array from right to left
			for(int j=W; j>=wt[i]; j--){
				int temp = dp[j];
				dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
			}
		cout<<" "<<val[i]<<" "<<wt[i]<<endl;
	}
		vector<int>::iterator i = v.begin();
	for (i = v.begin();i!=v.end(); i++)
	{
		/* code */
		cout<<*i<<endl;
	}
	return dp[W];
}


int main(){

int max;
	cin>>max;
	int m;
	cin>>m;
	int *wt = new int[m];
	int *val = new int[m];
	for(int i=0;i<m;i++){
		cin>>wt[i]>>val[i];
	}
	cout<<KnapSack(val,wt,m,max);


	return 0;
}