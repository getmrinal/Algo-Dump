//segmented etf!!	
#include <iostream>
using namespace std;

void etfFunc(int n){
	int arr[n+1];
	for(int i=0;i<=n;i++){
		arr[i] = i;  //put its value same as the position !!
	}

	for(int i=2;i<=n;i++){
		if(arr[i] == i){
			arr[i] = i-1;
			int j = 2*i;
			while(j<=n){
				arr[j] = (arr[j]*(i-1)/i);
				j = j+i;
			}
		} 
	}

	for(int i=0;i<=n;i++){
		cout<<"etf of"<<i<<"is :"<<arr[i]<<endl;
	}
}

int main(){

	int n;
	cin>>n;
	etfFunc(n);



	return 0;
}