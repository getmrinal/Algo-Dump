#include<iostream>
#include<vector>
#include <string>
#include <utility>
#include <set>
using namespace std;
int main(){

	// vector<int> v;
	// for (int i = 0; i < 5; ++i)
	// {
	// 	/* code */
	// 	v.push_back(i+1);
	// }
	// vector<int>::iterator i;
	// for (i = v.begin();i!=v.end(); i++)
	// {
	// 	/* code */
	// 	cout<<*i<<endl;
	// }
	// for (int i = 0; i < v.size(); i++)
	// {
	// 	/* code */
	// 	cout<<v[i]<<'\n';

	// }
	// string s = "mrinal";
	// string a(s);//copied s string in a
	// cout<<a<<endl;
	// string b(s,1,3);
	// string c = s.substr(0,2);
	// cout<<b<<endl<<c<<endl;
	// if(b.compare(c)==0){
	// 	cout<<b<<" is equal to "<<c<<endl;
	// }else{
	// 	cout<<b<<" is not equal to "<<c<<endl;
	// }

	pair<int,char>p;
	p = make_pair(1,'a');
	pair<int,char>p2(2,'b');
	cout<<p.first<<' '<<p.second<<endl;
	cout<<p2.first<<' '<<p2.second<<endl;






}