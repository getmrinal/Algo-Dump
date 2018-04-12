#include <iostream>
#include<algorithm>
using namespace std;

bool help(int c,int n,int *arr,int mid){
	c = c-1;
	int last = arr[0];
	int i=1;
	while(c!=0 && i<n){
		if(arr[i]- last>=mid){
			last =arr[i];
			//cout<<'*'<<last<<endl;
			c = c-1;
			//cout<<c<<'*';
		}
		i++;
	}
	if(c==0){
		return true;
	}else{return false;}
}

int main(){

	int stall;
	cin>> stall;
	int cows;
	cin>>cows;
	int *arr = new int[stall];
	for(int i=0;i<stall;i++){
		cin>>arr[i];
	}

	sort(arr,arr+stall);

	int mid = arr[stall-1] - arr[0];
	//cout<<mid<<false;
	//checck if the min diatnce between cows is feasible or not
	//how??
	//let d=3{1 2 4 8 9}
	// 1 put in one
	//then i(where last cow) - (i(present))>=3
	//i.e, parameter 3 arr length mid
	cout<<help(cows,stall,arr,mid);





	return 0;
}