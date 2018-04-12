#include <iostream>
using namespace std;

int coin(int size,int den[],int val,int **storage){
	if(val<0){
		return 0;
	}
	if(val==0){
		return 1;
	}
	if(size==0){
		return 0;
	}

	if(storage[size][val]>-1){
		return storage[size][val];
	}
	int ans = coin(size,den,val-den[0],storage) + coin(size-1,den+1,val,storage);
	storage[size][val] = ans;
	return ans;
}

int main(){

	int size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
	int val;
	cin>>val;
	int **storage = new int*[size+1];
	for(int i=0;i<=size;i++){
		storage[i] = new int [val+1];
	} 
	for(int i=0;i<=size;i++){
		for(int j=0;j<=val;j++){
			storage[i][j] = -1;
		}
	}
	for(int i=0;i<=size;i++){
		for(int j=0;j<=val;j++){
			cout<<storage[i][j]<<" ";	
		}
		cout<<endl;
	}

	cout<<coin(size,a,val,storage);



	return 0;
}