#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
		
	string s = "aDcadhc";
	map<char,int> m;
		string::iterator it;
		for (it = s.begin(); it!=s.end(); it++)
		{
			/* code */
			m[*it] = m[*it] +1;
		}
		map<char,int> :: iterator t;
	for (it = s.begin(); it!=s.end(); it++)
		{
			t = m.find(*it);
			if(t->second == 1){
				cout<<t->first<<endl;
				break;
			}else{
				continue;
			}
		}
}