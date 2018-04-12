#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 750005
#define MOD 1000000007

int makeSieve(vector<int> v){
	int *arr = new int[MAX];
	for(int i=0;i<MAX;i++){
		vector<int>::iterator p  = find(v.begin(),v.end(),i);
		if(p!=v.end()){
			arr[i] =1;
		}else{
			arr[i] = 0;
		}
	}
	int result =0;
	for(int i=0;i<=v.back();i++){
		if(arr[i]!=0){
			int k = i;
			k = k+i;
			while(k<=v.back()){
				if(arr[k]!=0){
					//cout<<arr[k]<<" ";
					arr[k] = (arr[k]% MOD +  arr[i]%MOD)%MOD;
					//cout<<i<<" "<<arr[i]<<" "<<arr[k]<<" "<<k<<endl;
				}
				k = k+i;
			}
		}

		//cout<<arr[i]<<" "<<i<<endl;
		result = (result%MOD+arr[i]%MOD)%MOD;
		//cout<<result<<" ";
	}

	return result;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector <int> v ;
		for(int  i=0;i<n;i++){
			int a;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		
		cout<<makeSieve(v)<<endl;
	}



	return 0;
}