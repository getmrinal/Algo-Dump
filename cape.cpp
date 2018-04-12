#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string findSub(string i,int key){
	int a =1;
	while(a!=key){
		int x =0;
		string t = i.substr(x,0);
		if(t.compare(" ")==0){
			a++;
		}
		x++;
	}
	cout<<a;
}
int key;
bool compare(string i,string j){
	string a = findSub(i,key);
	string b = findSub(j,key);	
}
int main(){

	
	string type;
	int n;
	// cin>>n;
	string *j= new string[n];
	for(int i=0;i<n;i++){
		getline(cin,j[i]);
	}
	cin>>key>>type;
	cin>>n;
    sort(j,j+n,compare);
	for(int i=0;i<3;i++){
		cout<<j[i];
	}





	return 0;
}