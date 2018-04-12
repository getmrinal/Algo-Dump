#include <iostream>
#include <string>
using namespace std;

void helper(string s,string out=""){
	if(s.empty()){
		cout<<out<<endl;
	
		return;
	}
	int a = s[0] - '0';
	int b = a+96;
	string outI = out + (char)b;
	helper(s.substr(1),outI);
	if(s.size()>=2){
		int c =  s[1] - '0';
		int k = a*10 + c;
		if(k<=26){
			k= k+96;
			string outII = out + (char)k;
			
			helper(s.substr(2),outII);
		}
	}
}



int main(){

	//string output[1000];
	string s= "1123";
	helper(s);
	



	return 0;
}