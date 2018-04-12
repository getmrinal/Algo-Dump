#include <iostream>
using namespace std;

int editDistance(string s1,string s2,int a,int b,int m,int n,int **help){
	if(m==a){
		return b-n;
	}
	if(n==b){
		return a-m;
	}

	if(help[m][n] > -1){
		return help[m][n];
	}


	if(s1[m] == s2[n]){
		help[m][n] =  1 + editDistance(s1,s2,a,b,m+1,n+1,help);
		return help[m][n];
	}else{
		help[m][n] =1 +  min(editDistance(s1,s2,a,b,m+1,n+1,help),min(editDistance(s1,s2,a,b,m+1,n,help),editDistance(s1,s2,a,b,m,n+1,help)));
		return help[m][n];
	}
}
int editDistanceString(string s1,string s2,int ** help){
	int m = s1.length();
	int n = s2.length();
	if(m == 0){
		return n;
	}
	if(n == 0){
		return m;
	}

	if(help[m][n] > -1){
		return help[m][n];
	}
	if(s1[0] == s2[0]){
		help[m][n] = 1 + editDistanceString(s1.substr(1,m-1),s2.substr(1,n-1),help);
	}else{
		help[m][n] = 1 + min(editDistanceString(s1.substr(1,m-1),s2.substr(1,n-1),help),min(editDistanceString(s1.substr(1,m-1),s2,help),editDistanceString(s1,s2.substr(1,n-1),help)));
	}
	return help[m][n];
}
int main(){

	string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	int m = s1.length();
	int n = s2.length();
	int **help = new int*[m+1];
	for(int i=0;i<=m;i++){
		help[i] = new int[n+1];
		for(int j=0;j<=n;j++){
			help[i][j] = -1;
		}
	}
	cout<<editDistanceString(s1,s2,help);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<help[i][j]<<"   ";
		}
		cout<<endl;
	}

	return 0;
}