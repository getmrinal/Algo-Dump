#include <iostream>
#include <string>
using namespace std;

int num_codes(int*n,int size,int *arr){
	if(size ==1 || size ==0){
		return 1;
	}
	//cout<<size<<endl;
	if(arr[size]>0){
		return arr[size];
	}
	int output = num_codes(n,size-1,arr);
	if(n[size-2]*10 + n[size-1] <= 26){
		output += num_codes(n,size-2,arr);
	}

	arr[size] = output;

	return output;
}
int num_codes2(int *n,int size){
	int output[size+1];
	output[0] =1;
	output[1] = 1;
	for(int i=2;i<=size;i++){
		output[i] = output[i-1];
		if(n[i-2]*10 + n[i-1] <= 26){
			output[i] += output[i-2];
		}
	}
	int result = output[size];
	
	return result;
}

int main(){
	int size;
	cin>>size;
	int n[size];
	int arr[size-1];
	for(int i=0;i<size;i++){
		cin>>n[i];
	}
	for(int i=2;i<=size;i++){
		arr[i] =0;
	}
	cout<<num_codes(n,size,arr)<<endl;
	cout<<num_codes2(n,size);


	return 0;
}