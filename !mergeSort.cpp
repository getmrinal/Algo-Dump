#include <iostream>
using namespace std;

void mergeArray(int *input,int si,int mid,int ei){
	int i=si;
	int j= mid+1;
	int temp[ei-si];
	int k=0;
	while(i<=mid && j<=ei){
		if(input[i]<= input[j]){
			temp[k++] = input[i++];
		}else{
			temp[k++] = input[j++];
		}
	}

	while(i<=mid){
		temp[k++] = input[i++];
	}
	while(j<=ei){
		temp[k++] = input[j++];
	}
	k=0;
	for(int i=si;i<=ei;i++){
		input[i] = temp[k++];
	}
	return;
}

void mergeSort(int*input,int si,int ei){
	if(si>=ei){
		return;
	}

	int mid = (ei+si)/2;
	mergeSort(input,si,mid);
	mergeSort(input,mid+1,ei);
	mergeArray(input,si,mid,ei);
	return;
}

int main(){

	int n;
	cin>>n;
	int *input = new int[n];
	for(int i=0;i<n;i++){
		cin>>input[i];
	}

	mergeSort(input,0,n-1);
	for(int i=0;i<n;i++){
		cout<<input[i]<<' ';
	}



	return 0;
}