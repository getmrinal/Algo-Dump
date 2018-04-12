#include <iostream>
using namespace std;
int maxSum(int n1,int*arr,int n2,int *arr2){
	int mSum =0;
	int s1=0;
	int s2=0;
	int i=0;
	int j=0;
	while(i<n1 && j<n2){
		if(arr[i]<arr2[j]){
			s1 = s1 + arr[i];
			i++;
		}else if(arr[i]>arr2[j]){
			s2 = s2 + arr2[j];
			j++;
		}else{
			s1 = s1+arr[i];
			s2 =s2+arr2[j];
			if(s1>s2){
				mSum= mSum + s1;
			}else{
				mSum=mSum + s2;
			}
			i++;
			j++;
			s1=0;
			s2=0;
			cout<<mSum<<endl;
		}
	}
	while(i<n1){
		s1 =s1 + arr[i];
		i++;
	}
	while(j<n2){
		s2 = s2 + arr2[j];
		j++;
	}
	if(s1>s2){
		mSum= mSum + s1;
	}else{
		mSum=mSum + s2;
	}
	cout<<mSum<<endl;
	return mSum;
}

int main(){

	int n1,n2;
	cin>>n1;
	int *arr = new int[n1];
	for(int i=0;i<n1;i++){
		cin>>arr[i];
	}
	cin>>n2;
	int *arr2 = new int[n2];
	for(int i=0;i<n2;i++){
		cin>>arr2[i];
	}
	cout<<maxSum(n1,arr,n2,arr2);



	return 0;
}