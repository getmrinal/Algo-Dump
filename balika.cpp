//select lcs from 2 strings which will lead to max ascii value in sum and the length of that
//subsequence is given 
//axyz
//yaxz
//ans should be yz not axz!!
#include <iostream>
using namespace std;

int lcsSum(string s1,string s2,int m,int n,int ***threedp,int k){
	if(m<=0 || n<=0  ){
		cout<<"&&";	
		return 0;
	}
	int ans;
	//cout<<"1";
	cout<<m<<" "<<n<<" "<<k<<endl;
	if(threedp[m][n][k] > -1){
		return threedp[m][n][k];
	}
	cout<<"2";
	if(s1.at(0) == s2.at(0)){
		char a = s1.at(0);
		cout<<"3";
		ans = (int)a + lcsSum(s1.substr(1),s2.substr(1),m-1,n-1,threedp,k-1);
	}else{
		cout<<"4";
		int one = lcsSum(s1.substr(1),s2,m-1,n,threedp,k);
		int two = lcsSum(s1,s2.substr(1),m,n-1,threedp,k);
		ans = max(one,two);
	}
	threedp[m][n][k] = ans;
	return ans;


}


int main(){

	string s1,s2;
	cin>>s1>>s2;
	int k;
	cin>>k;
	int ***threedp = new int**[s1.length()+1];
	for(int i=0;i<=s1.length();i++){
		threedp[i] = new int*[s2.length()+1];
		for(int j=0;j<=s2.length();j++){
			threedp[i][j] = new int[k+1];
			for(int l=0;l<=k;l++){
				threedp[i][j][l] = -1;
			}
		}
	}


	// for(int i=0;i<n=s1.length();i++){
	// 	cout<<"row   "<<i<<"   ";
	// 	for(int j=0;j<=s2.length();j++){
	// 		cout<<"col  "<<j<<"   ";
	// 		for(int l=0;l<=k;l++){
	// 			cout<<"arr "<<l<<"  ";
	// 			cout<<threedp[i][j][l]<<",";
	// 		}
	// 		cout<<"     ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	cout<<lcsSum(s1,s2,s1.length(),s2.length(),threedp,k);

	// for(int i=0;i<s1.length();i++){
	// 	cout<<"row   "<<i<<"   ";
	// 	for(int j=0;j<s2.length();j++){
	// 		cout<<"col  "<<j<<"   ";
	// 		for(int l=0;l<k;l++){
	// 			cout<<"arr "<<l<<"  ";
	// 			cout<<threedp[i][j][l]<<",";
	// 		}
	// 		cout<<"     ";
	// 	}
	// 	cout<<endl;
	// }



	return 0;
}
  
