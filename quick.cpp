#include <iostream>
using namespace std;

void swap(int &a,int &b){
  int temp =a;
  a=b;
  b=temp;
}


int partiton(int *input,int si,int ei){
  int count =0;
  int num =input[si];
  int start = si;
  int end = ei;
  for(int i=si+1;i<=ei;i++){
    if(num>input[i]){
      count++;
    }
  }
  swap(input[si],input[si+count]);
  
  while(start< (si+count)  && end > (si+count)){
    if(input[start] > num){
      if(input[end] < num){
        swap(input[start],input[end]);
        start++;
        end--;
      }else if(input[end] > num){
        end--;
      }
    }else if(input[start] < num){
      start++;
    }
  }
   
	return si+count;  
}

int main(){

	 int arr1[] =  {43, 53,34, 212, 4 ,6 ,2 ,1, 442};
	  int size = 10;
	  	cout<<partiton(arr1,0,8)<<endl;

	  	for (int i = 0; i < 9; ++i)
	  	{
	  		/* code */
	  		cout<<arr1[i]<<' ';
	  	}



	return 0;
}