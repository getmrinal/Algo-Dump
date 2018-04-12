#include <iostream>
#include <set>
using namespace std;

bool checkPrime(set<int>&p,int n,int max ){
	  int count=0;
  //store prime number multiples!!

  for(int i=1;i*i <= n;i++){
    if(n%i == 0){
      if(i*i == n){
        count++;
      }else{
        count = count +2;
      }
    }
  }
  if(count==2){
  	
  	if(n!=1){
  	int i=number;
  	int er=0;
  	while(er<=max){
  		er = n*i;
  	
  		p.erase (er);
  		i++;
  	}
  }
    return true;
  }else{
    return false;
  }

}


int main(){

	int n;
	cin>>n;
	set<int> p;
	for(int i=0;i<=n;i++){
		p.insert(i);
	}
	int count=0;
	set<int>::iterator it;
	for (it = p.begin(); it != p.end(); it++){
			
			if(checkPrime(p,*it,n)){
				count++;
			}
	}


	cout<<count<<endl;

	return 0;
}