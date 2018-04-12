#include <iostream>
using namespace std;
int editDistance(string s1,string s2,int a,int b,int m,int n){
	if(m==0){
		return b-n;
	}
	if(n==0){
		return a-m;
	}


	if(s1[a-m] == s2[b-n]){
		return 1 + editDistance(s1,s2,a,b,m-1,n-1);
	}else{
		return 1 + min(editDistance(s1,s2,a,b,m-1,n-1),min(editDistance(s1,s2,a,b,m-1,n),editDistance(s1,s2,a,b,m,n-1)));
	}
}

int main(){

		string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	int m = s1.length();
	int n = s2.length();
	cout<<m<<endl;
	cout<<n<<endl;
	int **help = new int*[m+1];
	for(int i=0;i<=m;i++){
		help[i] = new int[n+1];
		for(int j=0;j<=n;j++){
			help[i][j] = -1;
		}
	}
	cout<<editDistance(s1,s2,m,n,m,n);




	return 0;
}