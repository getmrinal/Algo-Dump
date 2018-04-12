#include <iostream>
#include <algorithm>

using namespace std;

bool isSafe(long long in[],int c,int n,long long d){
	int count = 1;
	long long last  = in[0];
	for (int i=1;i<n;i++){
		if(in[i]-last >= d){
			last = in[i];
			count++;
		}
		if(count==c){
			return true;
		}
	}
	return false;
}
int main(){

	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		long long*in = new long long [n];
		for(int i=0;i<n;i++){
			cin>>in[i];
		}
		sort(in,in+n);
		long long si =0;
		long long ei = in[n-1] - in[0];
		long long ans = -1;
		while(si<=ei){
			long long mid = si + (ei-si)/2;
			if(isSafe(in,c,n,mid)){
				ans = mid;
				si = mid+1;

			}else{
				ei = mid-1;
			}
		}
		cout<<ans;

	} 

	return 0;
}