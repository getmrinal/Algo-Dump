#include <iostream>
using namespace std;

void merge2array(int *input,int si,int mid,int ei){
  int out[ei-si];
  int size =0;
  int i = si;
  int j = mid+1;
  int k =0;
  while(i<=mid && j <=ei){
    if(input[i]<input[j]){
      out[size++] = input[i++];
    }else{
      //inv count A[i] > A[j] i<j
      out[size++] = input[j++];
    }
  }
  if(i<=mid){
      while(i<=mid){
        out[size++] = input[i++];
      }
  }else if(j<=ei){
    while(j<=ei){
      out[size++] = input[j++];
    }
  }
  size =0;
  
  for(int i=si;i<=ei;i++){
    input[i] = out[size++];
  }
  
}


void mergeHelper(int *input,int si,int ei){
  if(si>=ei){
    return;
  }
  int mid = (si+ei)/2;
  mergeHelper(input,si,mid);
  mergeHelper(input,mid+1,ei);
  merge2array(input,si,mid,ei);  
  
}

int main(){

  int arr1[] =  {43, 53, 12, 34, 212, 4 ,6 ,2 ,1, 442};
  int size = 10;

 
  mergeHelper(arr1,0,size-1);
  // merge2array(arr1,0,5,9);
  for (int i = 0; i < 10;i++)
  {
     
    cout<<arr1[i]<<' ';
  }

  return 0;
}