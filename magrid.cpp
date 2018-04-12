#include <bits/stdc++.h>
using namespace std;

int minCost(int **TD,int l,int b,int i,int j,int ** THelp){//dp with recursion
	if(i==l-1 && j==b){
		//cout<<i<<" "<<j<<" "<<TD[l][b]<<endl;
		return 1;
	}
	if(i==l && j==b-1){
		//cout<<i<<" "<<j<<" "<<TD[l][b]<<endl;
		return 1;
	}
	if(i==l && j==b){
		return 1;
	}
	if(i>=l || j>=b){
		return INT_MAX;
	}
	

	// if(THelp[i][j] > -99){
	// 	return THelp[i][j];
	// }	

	int right = minCost(TD,l,b,i,j+1,THelp) - TD[i][j+1];
	int left = minCost(TD,l,b,i+1,j,THelp) - TD[i+1][j];
	int ans = min(right,left);
	//THelp[i][j] = ans;
	//cout<<i<<" "<<j<<" "<<right<<" "<<left<<endl;
	if(ans < 1){
		ans = 1;
	}
	return ans;

}

int main(){
	int t;
	cin>>t;
	while(t--){
		int l,b;
		cin>>l>>b;
		int **TD = new int*[l];
		for(int i=0;i<l;i++){
			TD[i] = new int[b];
			for(int j=0;j<b;j++){
				cin>>TD[i][j];
			}
		}
		int **THelp = new int*[l];
		for(int i=0;i<l;i++){
			THelp[i] = new int[b];
			for(int j=0;j<b;j++){
				THelp[i][j] = 0;
			}
		}
		cout<<minCost(TD,l-1,b-1,0,0,THelp)<<endl;
		//cout<<minCostIter(TD,l,b)<<endl;
	}


	return 0;
}