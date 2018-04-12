#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(){

	vector<int> v;
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		v.push_back(i+1);
	}
	vector<int>::iterator i = v.begin();
	for (i = v.begin();i!=v.end(); i++)
	{
		/* code */
		cout<<*i<<endl;
	}
	cout<<v.back()<<endl;
		for (int i = 0; i < v.size(); i++)
		{
			/* code */
			v[i] = i*2;
		}
		
	for (i = v.begin();i!=v.end(); i++)
	{
		/* code */
		cout<<*i<<endl;
	}
	// vector<int>::iterator t = v.end();

	// sort(v.begin(),v.end());


}