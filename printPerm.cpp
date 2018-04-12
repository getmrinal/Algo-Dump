#include <iostream>
using namespace std;
void helper(string s,string out=""){
	if(s.empty()){
		//out  = out + s[0];
		cout<<out<<endl;
		return;
	}

	for(int i=0;i<s.size();i++){

		string in = s.substr(0,i)+s.substr(i+1);
		string outI = out + s[i];
		helper(in,outI);
	}


}
int main(){

	string s = "adg";
	helper(s);


	return 0;
}