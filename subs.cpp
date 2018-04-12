#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int subs(string input,string output[]){
	if (input.size()<= 0){
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);
	int smallSize = subs(smallString,output);


	for (int i = 0; i < smallSize; ++i)
	{
		output[i+smallSize] = output[i] + input[0];
	}
	return 2*smallSize;

}
//0 1 2 3

int main(){

	string input;
	cin>>input;
	int size = input.size();
	size = pow(2,size);
	//cout<<size<<' ';
	int flag =0;
	string*output = new string[size];
	int count = subs(input,output);
	for (int i = 0; i < count; ++i)
	{
		if(output[i].size()==1){
			cout<<output[i]<<" ";
			flag++;
			continue;
		}

		int s = output[i].size();
		s = s/2;
		// string s1 = output[i].substr(0,s-1);
		// string s2 = output[i].substr(s);
		if(output[i].compare(0,s,output[i],s,s)){
			cout<<output[i]<<" ";
			flag++;
		}
	}
	cout<<flag<<" ";



	return 0;
}