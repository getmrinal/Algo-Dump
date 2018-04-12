//find the min cost for travelling from forst node of TD array to last node
//given the size of TD array and cost of each node

#include <iostream>
using namespace std;

int minCost(int **TD,int l,int b,int i,int j,int ** THelp){//dp with recursion
	if(i==l && j==b){
		return TD[l][b];
	}
	if(i>l || j>b){
		return 99999;
	}
	

	if(THelp[i][j] > 0){
		return THelp[i][j];
	}

	int right = minCost(TD,l,b,i,j+1,THelp);
	int diag = minCost(TD,l,b,i+1,j+1,THelp);
	int left = minCost(TD,l,b,i+1,j,THelp);
	int ans = TD[i][j] + min(right,min(diag,left));
	THelp[i][j] = ans;
	return ans;

}

int minCostIter(int **TD,int l, int b){//iterative dp
	int **cost = new int*[l];
	for(int i=0;i<l;i++){
		cost[i] = new int[b];
		
	}
	//write the base  cases first
	
	cost[l-1][b-1] = TD[l-1][b-1];
	
	for(int i = l-2;i>=0;i--){
		cost[i][b-1] = TD[i][b-1] + cost[i+1][b-1];
	}	
	for(int i=b-2;i>=0;i--){
		cost[l-1][i] = TD[l-1][i] + cost[l-1][i+1];
	}
	//done base cases
	//make the rest of matrix using base cases!!
	
	for(int i = l-2;i>=0;i--){
		for(int j = b-2;j>=0;j--){
			cost[i][j] = min(TD[i][j] + cost[i+1][j],min(TD[i][j] + cost[i][j+1],TD[i][j] + cost[i+1][j+1])); //right down and diagonal all three!!
			
		}
		cout<<endl;
	}

	return cost[0][0];


}


int main(){
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
	cout<<minCostIter(TD,l,b);


	return 0;
}