#include<iostream>
using namespace std;
void PushZeroesEnd(int arr[], int n){
  int last=n-1;
  for(int i=0;i<last;i++){
    if(arr[i]==0){
      int temp =arr[last];
      arr[last] = arr[i];
      arr[i]=temp;
      last--;
      i--;
    }
  }

}

int main(){
	int input2[] = {5,0,3,0,1};
	int input1[] = {1,3};
	int size1 = 2;
	int size2 = 5;
	//sumOfTwoArrays(input1,size1,input2,size2);
	PushZeroesEnd(input2,size2);
	for(int i=0;i<size2;i++){
		cout<<input2[i]<<' ';
	}

}