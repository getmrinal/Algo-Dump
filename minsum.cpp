#include<vector>
#include<algorithm>
void helper(int *arr,int index,int sc,int sum,vector<int> v,int n){
  if(index == n){
    v.push_back(sum);
    return;
  }
  if(sc == -1){
    index++;
    sc =0;
    helper(*(arr+index),index,sc,sum+ arr[0],v,n);
    sc =1;
    helper(*(arr+index),index,sc,sum+ arr[1],v,n);
    sc = 2;
    helper(*(arr+index),index,sc,sum+ arr[2],v,n);
  }else if(sc == 0){
    index++;
    sc =1;
    helper(*(arr+index),index,sc,sum+ arr[1],v,n);
    sc = 2;
    helper(*(arr+index),index,sc,sum+ arr[2],v,n);
  }else if(sc == 1){
     index++;
    sc =0;
    helper(*(arr+index),index,sc,sum+ arr[0],v,n);
    sc = 2;
    helper(*(arr+index),index,sc,sum+ arr[2],v,n);
  }else if(sc == 2){
    index++;
    sc =0;
    helper(*(arr+index),index,sc,sum+ arr[0],v,n);
    sc =1;
    helper(*(arr+index),index,sc,sum+ arr[1],v,n);
 
  }
  
}


int minSum(int **input, int n) {
	
  vector<int> v;
  v = helper(arr[0],0,-1,0,v,n);
  sort(v.begin(),v.end(),greater<int>());
  return v[0];
  
  

}