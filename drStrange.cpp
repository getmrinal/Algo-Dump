#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> makeSieve(int n){	
	vector<int> v;
	// vector<int> iterator i;
	// for(i =v.begin();i!=v.end();i++){

	// }
	for(int i=0;i<=n;i++){
		v.push_back(i);
	}

	for(int i=n;i>=2;i--){
		if(v.at(i)==i){
			int k =i;
			k = k+i;
			while(k<=n){
				v[k] = i;
				k= k+i;
			}
		}
	}

	return v;
}

void printStrange(vector<int> v,int n){
	bool *arr = new bool[n+1];
	//cout<<"okk";
	vector<int> result;
	//vector<int> primes;
	for(int i=n;i>=1;i--){
		//cout<<endl;
		//cout<<"*"<<i<<"*"<<arr[i]<<endl;
		if(arr[i]==false){
			//cout<<endl;
			int x = i;
			while(x!=1){
				int lpd = v.at(x);
				//cout<<lpd<<endl;
						
				int k=i;
				while(k>=lpd){
					
					if(arr[k]==false){
					result.push_back(k);
					arr[k] = true;
					//cout<<k<<"false";
					}
					k = k-lpd;
				}

				while(x%lpd==0){
					x=x/lpd;
				}
			}
		}
		sort(result.begin(),result.end(),greater<int>());
		vector<int>::iterator it = v.begin();
		for (it = result.begin();it!=result.end(); it++){
			cout<<*it<<" ";
		}
		result.clear();
	}
	cout<<"1";
}


int main(){

	int n;
	cin>>n;
	vector<int> v = makeSieve(n);
	printStrange(v,n);

	return 0;
}