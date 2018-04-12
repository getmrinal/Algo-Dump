#include <iostream>
using namespace std;

vector<int> tollFight(int n,int *men,int *cost,int minCost=0,int menR=0,int fightM[]={0,0,0}){




	tollFight(n-1,men,cost)
}

int main(){

	int n;
	cin>>n;
	int *cost = new int[n];
	int *men = new int [n];
	for(int i=0;i<n;i++){
		cin>>men[i]>>cost[i];
	}

	vector<int> minCost = tollFight(n,men,cost);


	return 0;
}