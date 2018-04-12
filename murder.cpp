#include <iostream>
using namespace std;

long long merge2array(int *input,int si,int mid,int ei){
  int out[ei-si];
  int size =0;
  int i = si;
  int j = mid+1;
  int murder =0;
  int k =0;
  while(i<=mid && j <=ei){
    if(input[i]<input[j]){
      murder = murder + input[i];
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

  cout<<"murder"<<murder<<endl;
  return murder;
}


long long mergeHelper(int *input,int si,int ei){
  if(si>=ei){
    
    return 0;
  }
  int mid = (si+ei)/2;
  cout<<"Mid"<<mid<<endl;
  long long size1 = mergeHelper(input,si,mid);
  long long size2 = mergeHelper(input,mid+1,ei);
  long long size3 = merge2array(input,si,mid,ei);  
   
  return size1+size2+size3; 
}

int main(){

  int size;
  cin>>size;
  int *arr = new int[size];
  for (int i = 0; i < size; i++){
    
    cin>>arr[i];
  }

 
  cout<<mergeHelper(arr,0,size)<<endl;
  // merge2array(arr1,0,5,9);
  for (int i = 0; i < size;i++)
  {
     
    cout<<arr[i]<<' ';
  }

  return 0;
}