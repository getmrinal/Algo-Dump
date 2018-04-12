#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k;
	string text;
	cout<<"Enter the Cipher text:\n";
	cin>>text;

	vector <string> matrix;
	vector <int> sums;
	matrix.push_back(text);
	int key_len;
	//=====Guessing the length of key=====

	for(i=1;i<text.length();i++)	
		matrix.push_back(text.substr(0,text.length()-i));

	for(i=1;i<matrix.size();i++)
	{
		int count = 0;
		for(j=matrix[i].size()-1,k=matrix[0].size()-1;j>=0;j--,k--)
			if(matrix[i][j] == matrix[0][k])
				count++;	
		sums.push_back(count);
	}
	cout<<"For the given cipher text, the number of repeating letters after each shift:\n";
	for(i=0;i<50;i++)
		cout<<sums[i]<<" ";
	cout<<"\n";
	
	//the key guessing algorithm below, guesses only a few cases (400 < where length of text < 1400).
	//The user will have to guess the key themeselves after looking at the sums after each shift.
	
	cout<<"If text size is greater than 450 and lesser than 1300,\n Guessed length of key by this program: ";
	vector < pair < int, int > > finals;
	int freq[50] = {0};
	for(i=0;i<sums.size();i++)
		if(sums[i]>=text.size()/30)
			finals.push_back(make_pair(sums[i], i));

	for(i = 1; i<finals.size();i++)
		freq[finals[i].second-finals[i-1].second]++;

	int max = 1;
	for(i=1;i<50;i++)
		if(freq[i]>max)
			max = i;
	cout<<max<<"\n";
	cout<<"If guessed length is correct press 'y' else press 'n': ";
	char a;
	cin>>a;
	if(a == 'y')
		key_len = max;
	else if(a == 'n')
	{
		cout<<"Please enter the key length after analysing the sums: ";
		cin>>key_len;
	}
	else
		cout<<"Wrong! Bye bye!";

	double f[26];
	//guessing the key

	//actual probability of frequency of english letters
	double actual[26] = {0.08167, 0.01492, 0.02782, 0.04253, 
		0.12702, 0.02228,0.02015, 0.06094, 0.06966, 0.00153, 
		0.00772, 0.04025,0.02406, 0.06749, 0.07507, 0.01929, 
		0.00095, 0.05987,0.06327, 0.09056, 0.02758, 0.00978, 
		0.02360, 0.00150,0.01974, 0.00074};
		char Key[key_len];
	for(i=0;i<key_len;i++)
	{
		double a[26] = {0};
		
		for(j=i;j<text.length();j+=key_len)
			a[text[j]-'a']++;
		//for(j=0;j<26;j++)
		//	cout<<a[j]<<" ";
		for(j=0;j<26;j++)
		{
			a[j]*=key_len;	
			a[j]= (double) a[j] / (double) text.size();
		}
		vector <pair <int,double> > all_muls;
		
		for(j=0;j<26;j++)
		{
			double mul=0;
			for(k=0;k<26;k++)
				mul += actual[k]*a[(j+k)%26];
			all_muls.push_back(make_pair(j,mul));
		}
		double max_mul = all_muls[0].second;
		int shift=0;
		for(j = 0;j<26;j++)
		{
			if(max_mul < all_muls[j].second)
			{
				max_mul = all_muls[j].second;
				shift = j;
			}
		}
		Key[i]=(char)(shift+'a');
	}	
	cout << "Key: " ;
	for(j=0;j<key_len;j++)
		cout<<Key[j];
	cout<<"\n";

	//Decrypting the text
	cout<<"Decrypted text: ";
	string plain_text = text;
	for(i=0;i<key_len;i++)
	{
		for(j=i;j<text.length();j+=key_len)
			plain_text[j] = (char)((plain_text[j] - Key[i] + 26)%26 + 'a');
	}
	cout<<plain_text<<"\n";
	return 0;
}
