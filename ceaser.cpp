#include <iostream>
using namespace std;

string giveAns(string  main,char**matrix){
	for(int i=0;i<main.length();i=i+2){
		char a = main.at(i);
		char b = main.at(i+1);
		if(a=='j'){
			a= 'i';
		}
		if(b=='j'){
			b = 'i';
		}
		int r1,r2,c1,c2;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(matrix[i][j] == a){
					r1 = i;
					c1 = j;
				}
				if(matrix[i][j] == b){
					r2 = i;
					c2 = j;
				}
			}
		}
		if(r1==r2){
			a = matrix[r1][(c1+1)%5];
			b = matrix[r2][(c2+1)%5];
		}else if(c1==c2){
			a =matrix[(r1+1)%5][c1];
			b = matrix[(r2+1)%5][c1];
		}else{
			b = matrix[r1][c2];
			a = matrix[r2][c1];
		}
		cout<<a<<b;
	}
	string dd= "dd";
	return dd;
}

string process(string e){
	int m = e.length();
	int k=2;
	string filler = "x";
	for(int i=1;i<m;i++){
		if(e.at(i-1) == e.at(i) && k==2){
			//fill the filler!!!!
			m++;
			//cout<<i<<k<<"  ";
			e.insert(i,filler);
			i++;
			k++;
		}
		if(k==2){
			k=1;
		}
		k++;
	}
	if(m%2!=0){
		e = e + "x";
	}
	//cout<<e;
	return e;
}
int playFair(string e){
	string main = process(e);
	string key;
	key = "yabcdefgiklmnqsuvwxztroph";//set the key string
	int l = key.length();
	char **matrix = new char*[5];
	int k=0;
	for(int i=0;i<5;i++){
		matrix[i] = new char[5];
		for(int j=0;j<5;j++){
			matrix[i][j] = key.at(k);		
			// cout<<matrix[i][j];
			// if(k==13){
			// 	cout<<"j";
			// }
			// cout<<" ";
			k++;
		}
	}
	//cout<<"fong";
	string enc = giveAns(main,matrix);

}
int ceaser(string e){
	cout<<"the ceaser cipher no"<<endl;
	int t;
	cin>>t;
	cout<<"the encrypted string is:"<<endl;
	for(int i=0;i<e.length();i++){
		int a = e.at(i);
			a = a-96;
			a = (a+ t)%26;
			a = 96 + a;
		char b = (char)a;
		cout<<b;
	}
}
string hill(string e){
	/*5  7  4
	  8  9  2
	  21 11 22*/

	for(int i=0;i<e.length();i=i+3){
		int a = (int)e.at(i);
		a = a-96;//cout<<a;
		int b = (int)e.at(i+1);
		b= b-96;//cout<<b;
		int c = (int)e.at(i+2);
		c=c-96;//cout<<c;
		int a1 = (5*a + 7*b + 4*c)%26;//cout<<a1;
		a1 = a1+96;
		int b1 = (8*a + 9*b + 2*c)%26;//cout<<b1;
		b1 = b1+96;
		int c1 = (21*a + 11*b + 22*c)%26;//cout<<c1;
		c1 = c1+96;
		 cout<<(char)a1<<(char)b1<<(char)c1;

	}
}

int main(){
	cout<<"enter the string to be encrypted!"<<endl;
	string e;
	cin>>e;
	//ceaser(e);
	playFair(e);
	//process(e);
	//hill(e);
	return 0;
}