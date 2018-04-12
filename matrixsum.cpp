#include <iostream>
using namespace std;

void helper(int *arr,int m,int si=0){
	if(si==m){
		cout<<arr[si]<<' ';
		return;
	}
	helper(arr,m,si+1);
	cout<<arr[si]<<' ';
	return;
}

int main(){
	int m,n;
	cin>>n;
	cin>>m;

	// for (int i = 0; i < m; i++) {
	// 	p[i] = new int[i + 1];
	// 	for (int j = 0;j <n; j++) {
	// 		cin >> p[i][j];
	// 	}
	// }

	int**p = new int*[n];
	for(int i=0;i<n;i++){
		p[i] = new int[m];
		for (int j = 0; j < m; j++){
			cin>>p[i][j];
		}
	}
	for(int i=0;i<n;i++){
    		helper(p[i],m-1);
       		cout<<'\n';
  	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout<<p[i][j]<<' ';
	// 	}
	// 	cout<<'\n';
	// }

	return 0;
}