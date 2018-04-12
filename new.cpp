#include<iostream>
using namespace std;

void sumOfTwoArrays(int input1[], int size1, int input2[], int size2){
  int size=0;
  if(size1>=size2){
    size = size1;
  }else{
    size = size2;
  }
  int flag=0;
    for(int i=size1-1,j=size2-1;i>=0 || j>=0;i--,j--){
    	int n;
        if(i<0){
          
          n = flag + input2[j];
          
        }else if(j<0){
          
          n = flag + input1[i];
          
        }else{
         
          n = flag+input1[i]+input2[j];
          
        }
  	  flag=0;
     
      if(n>9){
       	int a = n%10;
       	cout<<a;
       	flag =  n/10;
      }else{
      	cout<<n;
      }
    }  
}
void SelectionSort(int arr[], int n) {
	// Write your code here
	
	int flag=0;
  	for(int i=0;i<n-1;i++){
      int min=arr[i];

      for(int j=i+1;j<n;j++){
        if(min>=arr[j]){
          cout<<min<<"un"<<'\n';
          flag=1;
          min=j;
          cout<<min<<"ch"<<'\n';
        }
      }
      if(flag==1){
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    	}
    }
}


void PushZeroesEnd(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to return or print the output.
     * Taking input and printing output is handled automatically.
     */
  int l=n-1;
  int i=0;
  while(i<n){
  	if(arr[i]==0){
  		//cout<<"n"<<arr[l]<<'|'<<arr[i]<<'\n';
  		cout<<i<<'\n';
  		cout<<l<<'\n';
  		int temp=arr[i];
  		arr[i] =arr[l];
  		arr[l] =temp;
  		l--;
  		//cout<<"R"<<arr[l]<<'|'<<arr[i]<<'\n';
  	}else{
  		i++;
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