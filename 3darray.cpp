#include <iostream>
using namespace std;

int main(){

	int ***three = new int**[5];
	int g=0;
	for(int i=0;i<5;i++){
		three[i] = new int*[5];
		cout<<"row "<<i<<"   ";
		for(int j=0;j<5;j++){
			three[i][j] = new int[5];
			cout<<"col "<<j<<"   ";
			for(int k=0;k<5;k++){
				three[i][j][k] = k;
				cout<<three[i][j][k]<<",";
				g++;
			}
			cout<<"  ";
		}
		cout<<endl;
	}


	return 0;
}