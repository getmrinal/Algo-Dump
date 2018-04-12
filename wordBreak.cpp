#include <iostream>
using namespace std;
int ni;
int dictionaryContains(string &word,string *dictionary)
{
	
	for (int i = 0; i < ni; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

void wordBreakUtil(string str, int n, string result,string *dict)
{
	for (int i=1; i<=n; i++)
	{
		//extract substring from 0 to i in prefix
		string prefix = str.substr(0, i);

		if (dictionaryContains(prefix,dict))
		{
			if (i == n)
			{
				result += prefix;
				cout << result << endl; //print result
				return;
			}
			wordBreakUtil(str.substr(i, n-i), n-i,
								result + prefix + " ",dict);
		}
	}	 //end for
}//end function

// void wordBreak(string str,string*dict)
// {
// 	wordBreakUtil(str, str.size(), "",dict);
// }

int main()
{
	
	cin>>ni;
	string *dict = new string[ni];
	for(int i=0;i<ni;i++){
		cin>>dict[i];
	}
	string input;
	cin>>input;
	wordBreakUtil(input,input.size(),"",dict);
	return 0;
}
