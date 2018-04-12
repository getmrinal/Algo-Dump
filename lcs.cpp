#include <iostream>
#include<cstring>
using namespace std;

int lcsSum(char *a, char * b,int m,int n,int**storage){
	if(m==0 || n==0){
		return 0;
	}

	//if the first char matches
	if(storage[m][n] > -1){
		return storage[m][n];
	}
	int ans;
	if(a[0] == b[0]){
		 ans =  1+ lcsSum(a+1,b+1,m-1,n-1,storage);
		storage[m][n] = ans;
		
	}else{
		int one = lcsSum(a,b+1,m,n-1,storage);
		int two = lcsSum(a+1,b,m-1,n,storage);
		ans = max(one,two);
		storage[m][n] = ans;
	}
	return ans;
}

int lcsIt(string a,string b){
	int m = a.length();
	int n = b.length();
	int **dp = new int*[m+1];
	for(int i=0;i<=m;i++){
		dp[i] = new int[n+1];
	}
	for(int i=0;i<=m;i++){
		dp[i][0] = 0;
	}	
	for(int i=0;i<=n;i++){
		dp[0][i] = 0;
	}
	
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(a.at(m-i) == b.at(n-j)){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<"     ";
		}
		cout<<endl;
	}
}
int lcsHelper(string ac,string bc){
	int m = ac.length();
	int n = bc.length();
	
	char * a = new char[m];
	char * b = new char[n];



	strcpy(a, ac.c_str());
	strcpy(b, bc.c_str());
	return lcsI(a,b);
	// int **storage = new int*[m+1];
	// for(int i=0;i<=m;i++){
	// 	storage[i] = new int[n+1];
	// 	for(int j =0;j<=n;j++){
	// 		storage[i][j] = -1;
	// 	}
	// }
	// return lcsSum(a,b,m,n,storage);

}
int main(){
	string a;
	string b;
	cin>>a;
	cin>>b;
	cout<<lcsHelper(a,b)<<endl;	
	lcsIt(a,b);


	return 0;
}