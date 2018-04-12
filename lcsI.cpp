#include <iostream>
#include<cstring>
using namespace std;




	void lcsI(char* s1, char* s2,int**dp) {
		int m = strlen(s1);
		int n = strlen(s2);
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j<= n; j++) {
				if (s1[m - i] == s2[n - j]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}	else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}

	int lcs(string ac, string bc){

		int m = ac.length();
		int n = bc.length();
		
		char * a = new char[m];
		char * b = new char[n];



		strcpy(a, ac.c_str());
		strcpy(b, bc.c_str());
		int** dp = new int*[m + 1];
		for (int i = 0; i <= m; i++) {
			dp[i] = new int[n + 1];
		}
		for (int i = 0; i <= m; i++) {
			dp[i][0] = 0;
		}
		for (int i = 0; i <=n ;i++) {
			dp[0][i] = 0;
		}
		 lcsI(a,b,dp);
		 cout<<"start";
	  	for(int i=0;i<=m;i++){
	  		for(int j=0;j<=n;j++){
	  			cout<<dp[i][j]<<" ";
	  		}
	  		cout<<endl; 	 
	  	}
	  	cout<<"endl";
	  	return dp[m][n];
	}
int main(){

	string a,b;
	cin>>a;
	cin>>b;
	cout << lcs(a, b) << endl;



	return 0;
}