#include <iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
vector <int> makeSieve(int n){
	bool arr[n+1];
	for(int i=0;i<=n;i++){
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;

	//filter prime
	for(int i=2;i*i<=n;i++){
		if(arr[i]){
			for(int j=i*i;j<=n;j = j+i){
				arr[j] = false;
			}
		}
	}
	vector<int> v;
	int count =0;
	for(int i=0;i<=n;i++){
		if(arr[i]){
			v.push_back(i);
			//cout<<arr[i]<<endl;
			count++;
		}
	}
	vector<int>::iterator i = v.begin();
	// for (i = v.begin();i!=v.end(); i++)
	// {
	// 	 code 
	// 	cout<<*i<<" ";
	// }
	// cout<<endl;
	return v;
}

long long countDivisor(int n){
	vector<int> prime = makeSieve(n+10);
	long long result =1;
	for(int i=0;prime.at(i)<=n;i++){
		long long count =0;
		int k = prime.at(i);
		while(n/k !=0){
			count = (count + n/k)%MOD;
			k = k*prime.at(i);
		}
		result = (result * ((count+1)%MOD))%MOD;
	}
	return result;
}




int main(){

	int t;
	cin>>t;
	while(t--){int n;
		cin>>n;
		
		long long a = countDivisor(n);
		cout<<a<<endl;
	}


	return 0;
}
