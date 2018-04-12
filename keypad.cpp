#include <iostream>
#include <string>
using namespace std;

int main(){

	string str = "abcdefgh";
	int a =4;
	int size = str.size();
	//for (int i = 1; i < a; ++i)
	
	string temp = str;
	for (int i = 1; i < a ; ++i)
	{
		/* code */
		str = str+temp;
	}
		
	
	for (int i = 0; i < str.size(); ++i)
	{
		/* code */
		cout<<str[i]<<' ';
	}



	return 0;
}