#include <iostream>
using namespace std;


int murderCount(int*input,int si,int mid,int ei){
	int i=si;
	int j= mid+1;
	int temp[ei-si];
	int k=0;
	int murder=0;
	int flag=0;
	while(i<=mid && j<=ei){
		if(input[i]<input[j]){
			if(flag==1){
				murder = 2*murder;
				flag =0;
			}
			murder = murder + input[i];
			temp[k++] = input[i++];
		}else{
			flag = 1;
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
	cout<<murder<<endl;
	return murder;

}

int mergeSort(int*input,int si,int ei){
	if(si>=ei){
		return 0;
	}

	int mid = (ei+si)/2;
	int lc = mergeSort(input,si,mid);
	int rc = mergeSort(input,mid+1,ei);
	int c = murderCount(input,si,mid,ei);

	return lc+rc+c;
}

int main(){

	int test;
	cin>>test;
	while(test!=0){
		int n;
		cin>>n;
		int *input = new int[n];
		for(int i=0;i<n;i++){
			cin>>input[i];
		}
		cout<<mergeSort(input,0,n-1)<<endl;
		test--;
	}



	return 0;
}