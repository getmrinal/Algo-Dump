#include <iostream>
using namespace std;

long long merge2array(int *input,int si,int mid,int ei){
  long long inversion = 0;
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
      inversion = inversion + (mid-i+1);
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
  return inversion;
}


long long mergeHelper(int *input,int si,int ei){
  if(si>=ei){
    
    return 0;
  }
  int mid = (si+ei)/2;
  long long size1 = mergeHelper(input,si,mid);
  long long size2 = mergeHelper(input,mid+1,ei);
  long long size3 = merge2array(input,si,mid,ei);  
   
  return size1+size2+size3; 
}

int main(){

  int arr1[] =  {36343342, 658445766, 281323766, 703538013, 437455363 ,900766801, 84401391 ,159903601, 626186515, 127519304, 222484765, 609828661, 190927389, 152625748 ,358752776 ,522920848, 494568773 ,977351598, 782415711 ,966011559};

  int size = 20;

 
  cout<<mergeHelper(arr1,0,size-1)<<endl;
  // merge2array(arr1,0,5,9);
  for (int i = 0; i < size;i++)
  {
     
    cout<<arr1[i]<<' ';
  }

  return 0;
}