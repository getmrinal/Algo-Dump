#include <iostream>
#include<iomanip>
#include<vector>
using namespace std;
#define MAX 100001

vector<int> makeSieve(){
	bool arr[MAX];
	for(int i=0;i<=MAX;i++){
		arr[i] = true;
	}
	//arr[0] = false;
	//arr[1] = false;

	//filter prime
	for(int i=2;i*i<MAX;i++){
		if(arr[i]){
			for(int j=i*i;j<MAX;j = j+i){
				arr[j] = false;
			}
		}
	}

	vector<int> v;
	//int count =0;
	v.push_back(2);
	for(int i=3;i<MAX;i=i+2){
		if(arr[i]){
			v.push_back(i);
		}
	}
	return v;
}

int largestPow(long long n,int i){
	int ans =1;
	while(n%i ==0){
		n = n/i;
		ans = ans *i;
	}
	return ans;
}
double etfFunc(int r,int l,vector<int> primes,int k){
	cout<<"ettet";
	int size = l-r+2;
	long long arr[size];
	long long extra[size];
	cout<<"okklk";
	for(int i=0;i<=l-r+1;i++){
	
		arr[i] = r+i;
		extra[i] = r+i;  //put its value same as the position !!
	}

	vector<int>::iterator i = primes.begin();
	
	for(i = primes.begin();(*i)*(*i)<=l;i++){
		int cprime = (*i);
		long long y = (r/cprime)*(cprime);
		if(y<r){
			y = y+cprime;
		}
		for(;y<=l;y=y+cprime){
			arr[y-r] = (arr[y-r]*(cprime-1))/cprime;
			int temp = extra[y-r];
			int temp1 = largestPow(y,cprime);
			extra[y-r] = extra[y-r]/temp1;
//		cout<<temp<<"    "<<extra[y-r]<<"    "<<temp1<<"  "<<y<<":   "<<cprime<<endl;
			 
		} 
	}
	cout<<"done!!";
	double count =0;
	 for(int i=0;i<size-1;i++){
		//cout<<i<<" "<<i+r<<" "<<extra[i]<<endl;
	 	if(extra[i]!= 1){
	 		arr[i] = (arr[i]*(extra[i]-1))/extra[i];
	 	}
		if(arr[i]%k==0){
			count = count + 1;
		}
	 }
	cout<<"done too";
	// for(int i=0;i<l-r+1;i++){
	// 	cout<<i<<" :"<<arr[i]<<endl;
	// }
	//cout<<count<<" "<<l-r+1<<endl;
	double sizes = l-r+1;
	double answer = count /sizes;
	
	cout<< std::fixed;
	cout<< std::setprecision(6);
	cout<< answer;

	return answer;
}

int main(){

	vector<int> v = makeSieve();
	

	long long l,r;
	int k;
	cin>>r>>l>>k;
	double ans = etfFunc(r,l,v,k);
	cout<< std::fixed;
	cout<< std::setprecision(6);
	cout<< ans<<endl;

	return 0;
}