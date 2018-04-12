#include <iostream>
#include <algorithm>
using namespace std;

bool check(long long *inp,int mid,,long long k,int n){
	//inp[mid] == 

	//check input[mid] for(int i=0 to k){}
	int it =0;
	while(k!=0 && it<n){
		if(inp[it] >= inp[mid]){
			k--;
		} 
		it--;
	}

	if(k==0){
		return true;
	}else{
		return false;
	}

}

void helper(long long *inp,int si,int ei,long long k){
	if(si>=ei){
		
		return;
	}

	 int mid = si + (ei-si)/2;
	 if(check(inp,mid)){

	 }
}

int main(){

	int n;
	cin>>n;
	long long k;
	cin>>k;

	long long *inp = new long long [n];
	for (int i = 0; i < n; ++i)
	 {
	 	/* code */
	 	cin>>inp[i];
	 } 
	 sort(inp,inp+n);
	 helper(inp,0,n,k);



	  


	return 0;
}