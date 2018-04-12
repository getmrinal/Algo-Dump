#include<iostream>
#include<set>
#include <string>
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
	
	char str[] = {'B','c','r','$','g','w',')','T','c','E','5','S','@','D','H','T','F','w','7','6'};
	// string a(s);//copied s string in a
	// cout<<a<<endl;
	// string b(s,1,3);
	// string c = s.substr(0,2);
	// cout<<b<<endl<<c<<endl;
	// if(b.compare(c)==0S){
	// 	cout<<b<<" is equal to "<<c<<endl;
	// }else{
	// 	cout<<b<<" is not equal to "<<c<<endl;
	// }
	 int size = sizeof(str)/sizeof(str[0]);
	
  	set<char>s;
  	string out;
  
    for (int i = 0; i < size; ++i){
          /* code */
      	s.insert(str[i]);
      }
  	   char *result = new char();
  set<char>::iterator it;
  int i=0;
  for(it = s.begin();it!=s.end();it++){
    result[i] = *it;
    i++;
  }
  for (int j = 0; j <i ; ++j)
  {
  	/* code */
  	cout<<result[j];
  }
	
}