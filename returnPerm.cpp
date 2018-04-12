#include <iostream>
using namespace std;


int helper(string s,string *output){
	if(s.empty()){
		output[0] = "";
		return 1;
	}
	if (s.size()==1){
		output[0] = s[0];
		return 1;
	}
	int si =0;
	for(int i=0;i<s.size();i++){
		string in = s.substr(0,i)+s.substr(i+1);
		 string outI[1000];
		int size = helper(in,outI);
		for(int j=si,k=0;j<si + size;j++,k++){
			output[j] = s[i] + outI[k];
		 }
		si = si + size;
	}
	return si;
}


int main(){

	string output[1000];
	string s= "adg";
	int a = helper(s,output);
	for (int i = 0; i < a; i++){

		cout<<output[i]<<endl;
	}



	return 0;
}