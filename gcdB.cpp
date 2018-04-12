#include <iostream>
#include <cstring>
using namespace std;

int main(){

	string a;
	cin>>a;
	int b=0;

	for(int i=0;i<a.length();i++){
		string f=a.substr(i,1);
		int z = stoi(f);
		b = (b*10 + z) % 40;
	}
	cout<<b;




	return 0;
}