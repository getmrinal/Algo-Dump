#include<iostream>
#include <math.h>
using namespace std;


bool checkPrime(int n){
  int count=0;
  //store prime number multiples!!

  for(int i=1;i*i <= n;i++){
    if(n%i == 0){
      if(i*i == n){
        count++;
      }else{
        count = count +2;
        int temp = i;
        while(temp  <= n){
          
        }
      }
    }
  }
  if(count==2){
    return true;
  }else{
    return false;
  }
}

int main(){
	// Write your code here
	int n;
  cin>>n;
  int count=0;
  for (int i = 0; i < n; i++){
    if(checkPrime(i)){
      count++;
    }
  }

  cout<<count<<endl;
  
  
  
  return 0;
}

//more efficien
