#include <iostream>
#include <string>
using namespace std;


int helper(string s,string *output){
	if(s.empty()){
		output[0] = "";
		return 1;
	}
	int a = s[0] - '0';
	// a = a+96;
	// char d = (char)a;
	string outI[1000];
	int smallSize = helper(s.substr(1),outI);
	int smallSize2;
	int k;
	if(s.size()>=2){
		int c = s[1] - '0';
		k = a*10 + c;
		string outII[1000];
		if(k<=26){
			smallSize2 = helper(s.substr(2),outII);
		} 	
	}
	a = a+96;
	for(int i=0;i<smallSize;i++){
		output[i] = (char)a + outI[i];
	}
	if(k<=26){
		k = 96+k;
		for(int i=smallSize;i<smallSize + smallSize2;i++){
			output[i] = (char)k + outII[i]; 
		}
	}
	
	return smallSize+smallSize2;
}


int main(){


	string output[1000];
	string s= "44";
	int a = helper(s,output);
	for (int i = 0; i < a; i++){

		cout<<output[i]<<endl;
	}

	return 0;
}

