#include <iostream>
using namespace std;
int knapSackH(int a,int m,int *wt,int *val,int maxLeft,int **KnapSt){
	if(maxLeft==0){
		return 0;
	}
	if(m==a){
		return 0;
	}
	//for each wt we have 2 choices  select it or reject it!
	if(KnapSt[m][maxLeft] > -1){
		return KnapSt[m][maxLeft];
	}
	
	if(maxLeft >= wt[m]){
		int ch1 = knapSackH(a,m+1,wt,val,maxLeft,KnapSt);
		int ch2 = val[m] + knapSackH(a,m+1,wt,val,maxLeft-wt[m],KnapSt);
		KnapSt[m][maxLeft] = max(ch1,ch2);
	}else{
		KnapSt[m][maxLeft] =  knapSackH(a,m+1,wt,val,maxLeft,KnapSt);
	}
	return KnapSt[m][maxLeft];
}


int knapsack(int* weights, int* values, int n, int maxWeight){
	int **KnapSt = new int*[n+1];
	for(int i=0;i<=n;i++){
		KnapSt[i] = new int [maxWeight+1];
		for(int j=0;j<=maxWeight;j++){
			KnapSt[i][j] = -1;
		}
	}

  return knapSackH(n,0,weights,values,maxWeight,KnapSt);
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
	cout<<knapsack(val,wt,m,max);



	return 0;
}
