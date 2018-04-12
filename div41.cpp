#include <bits/stdc++.h>
using namespace std;

int helper(int a,int b){
  if(b==0){
    return a;
  }
  return helper(b,a%b);
  
}
int gcd(int a,int b){
  int x,y;
  if(a<=b){
    x=b;
  y=a;
  }else{
    x=a;
    y=b;
  }
  
 int k = helper(x,y);
  return k;
  
}

int main()
{
  
  int a0,a1;
  cin>>a0>>a1;
  int c,n;
  cin>>c>>n;
  int *a = new int[n];
  a[0] = a0;
  a[1] = a1;

  int i =2;
    while(i<=n-1){
      a[i] = (a[i-1]*c + a[i-2]) % 10;
  	i++; 
  }
  
  int b=0;
  for(int i=0;i<n;i++){
    b = (b*10 + a[i]) % 41;
  }
  if(gcd(41,b)!=1){
    cout<<"yes"<<endl;
  }else{
    cout<<"no";
  }

  
    return 0;
}
